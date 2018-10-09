/*
 * Copyright 2017-present Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <folly/String.h>
#include <thrift/lib/cpp2/transport/core/ThriftChannelIf.h>
#include <yarpl/Flowable.h>

namespace apache {
namespace thrift {

class RPCSubscriber
    : public yarpl::flowable::Subscriber<std::unique_ptr<folly::IOBuf>>,
      public yarpl::flowable::Subscription {
 public:
  using SubscriberRef =
      yarpl::Reference<yarpl::flowable::Subscriber<rsocket::Payload>>;

  RPCSubscriber(
      std::unique_ptr<folly::IOBuf> metaBuf,
      std::unique_ptr<folly::IOBuf> rpcCall,
      SubscriberRef subscriber)
      : inner_(subscriber),
        metaBuf_(std::move(metaBuf)),
        rpcCall_(std::move(rpcCall)) {
    auto ref = this->ref_from_this(this);
    inner_->onSubscribe(ref_from_this(this));
  }

  void onNext(std::unique_ptr<folly::IOBuf> buf) override {
    inner_->onNext(rsocket::Payload(std::move(buf)));

    if (toRequest_) {
      if (auto sub = subscription_.load()) {
        sub->request(toRequest_);
        toRequest_ = 0;
      }
    }
  }

  void onComplete() override {
    auto ref = this->ref_from_this(this);
    inner_->onComplete();
    if (auto sub = subscription_.exchange(nullptr)) {
      // nothing..
    }
  }

  // No further calls to the subscription after this method is invoked.
  void onError(folly::exception_wrapper ex) override {
    auto ref = this->ref_from_this(this);
    inner_->onError(ex);
    if (auto sub = subscription_.exchange(nullptr)) {
      // nothing..
    }
  }

  void onSubscribe(
      yarpl::Reference<yarpl::flowable::Subscription> subscription) override {
    auto ref = this->ref_from_this(this);
    subscription_ = std::move(subscription);
    if (cancelled_) {
      if (auto sub = subscription_.exchange(nullptr)) {
        sub->cancel();
      }
    } else if (toRequest_ > 0) {
      subscription_->request(toRequest_);
      toRequest_ = 0;
    }
  }

  void request(int64_t n) override {
    auto ref = this->ref_from_this(this);
    if (rpcCallNotSent_) {
      rpcCallNotSent_ = false;
      VLOG(3) << "Sending the PRC call: '"
              << folly::humanify(rpcCall_->clone()->moveToFbString());
      inner_->onNext(
          rsocket::Payload(std::move(rpcCall_), std::move(metaBuf_)));
      --n;
    }

    if (auto sub = subscription_.load()) {
      toRequest_ += n;
      sub->request(toRequest_);
      toRequest_ = 0;
    }
  }

  void cancel() override {
    auto ref = this->ref_from_this(this);
    if (auto sub = subscription_.exchange(nullptr)) {
      sub->cancel();
      return;
    }
    cancelled_ = true;
  }

 protected:
  SubscriberRef inner_;
  std::unique_ptr<folly::IOBuf> metaBuf_;
  std::unique_ptr<folly::IOBuf> rpcCall_;
  yarpl::AtomicReference<Subscription> subscription_;
  bool rpcCallNotSent_{true};
  bool cancelled_{false};
  uint64_t toRequest_{0};
};
} // namespace thrift
} // namespace apache
