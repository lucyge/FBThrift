/*
 * Copyright 2014-present Facebook, Inc.
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

#include <folly/fibers/HPromise.h>
#include <thrift/lib/cpp2/async/RequestChannel.h>

namespace apache { namespace thrift {

template <typename Result>
class FiberCallbackBase : public RequestCallback {
  public:
    explicit FiberCallbackBase(
        std::shared_ptr<folly::fibers::HPromise<Result>> promise,
        std::shared_ptr<apache::thrift::RequestChannel> channel = nullptr)
          : promise_(promise),
            channel_(std::move(channel)) {}

    void requestSent() override{}

    void requestError(ClientReceiveState&& state) override {
      CHECK(state.isException());
      promise_->setException(std::move(state.exception()));
    }

  protected:
    std::shared_ptr<folly::fibers::HPromise<Result>> promise_;
    std::shared_ptr<apache::thrift::RequestChannel> channel_;
};

template <typename Result>
class FiberCallback : public FiberCallbackBase<Result> {
  private:
    typedef folly::exception_wrapper (*Processor)(Result&,ClientReceiveState&);

  public:
    FiberCallback(
        std::shared_ptr<folly::fibers::HPromise<Result>> promise,
        Processor processor,
        std::shared_ptr<apache::thrift::RequestChannel> channel = nullptr)
        : FiberCallbackBase<Result>(promise, std::move(channel)),
          processor_(processor) {}

    void replyReceived(ClientReceiveState&& state) {
      CHECK(!state.isException());
      CHECK(state.buf());

      Result result;
      auto ew = processor_(result, state);

      if (ew) {
        this->promise_->setException(ew);
      } else {
        this->promise_->setValue(std::move(result));
      }
    }

  private:
    Processor processor_;
};

template <typename Result>
class HeaderFiberCallback
    : public FiberCallbackBase<std::pair<Result,
        std::unique_ptr<apache::thrift::transport::THeader>>> {
  private:
    using HeaderResult = std::pair<
        Result, std::unique_ptr<apache::thrift::transport::THeader>>;
    typedef folly::exception_wrapper (*Processor)(Result&,ClientReceiveState&);
    Processor processor_;

  public:
    HeaderFiberCallback(
        std::shared_ptr<folly::fibers::HPromise<HeaderResult>> promise,
        Processor processor,
        std::shared_ptr<apache::thrift::RequestChannel> channel = nullptr)
        : FiberCallbackBase<HeaderResult>(promise,
                                           std::move(channel))
        , processor_(processor) {}

    void replyReceived(ClientReceiveState&& state) override {
      CHECK(!state.isException());
      CHECK(state.buf());

      Result result;
      auto ew = processor_(result, state);

      if (ew) {
        this->promise_->setException(ew);
      } else {
        this->promise_->setValue(std::make_pair(std::move(result),
                                               state.extractHeader()));
      }
    }
};

template <>
class HeaderFiberCallback<folly::Unit>
    : public FiberCallbackBase<std::pair<folly::Unit,
        std::unique_ptr<apache::thrift::transport::THeader>>> {
  private:
    using HeaderResult = std::pair<
        folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>;
    typedef folly::exception_wrapper (*Processor)(ClientReceiveState&);
    Processor processor_;

  public:
    HeaderFiberCallback(
        std::shared_ptr<folly::fibers::HPromise<HeaderResult>> promise,
        Processor processor,
        std::shared_ptr<apache::thrift::RequestChannel> channel = nullptr)
        : FiberCallbackBase<HeaderResult>(promise,
                                           std::move(channel))
        , processor_(processor) {}

    void replyReceived(ClientReceiveState&& state) override {
      CHECK(!state.isException());
      CHECK(state.buf());

      auto ew = processor_(state);

      if (ew) {
        promise_->setException(ew);
      } else {
        promise_->setValue(std::make_pair(folly::Unit(),
                                         state.extractHeader()));
      }
    }
};

class OneWayFiberCallback : public FiberCallbackBase<folly::Unit> {
  public:
    explicit OneWayFiberCallback(
        std::shared_ptr<folly::fibers::HPromise<folly::Unit>> promise,
        std::shared_ptr<apache::thrift::RequestChannel> channel = nullptr)
        : FiberCallbackBase<folly::Unit>(
            promise, std::move(channel)) {}

    void requestSent() override {
      promise_->setValue(folly::Unit());
    }

    void replyReceived(ClientReceiveState&& /*state*/) override {
      CHECK(false);
    }
};

template <>
class FiberCallback<folly::Unit> : public FiberCallbackBase<folly::Unit> {
 private:
  typedef folly::exception_wrapper (*Processor)(ClientReceiveState&);

 public:
  FiberCallback(
      std::shared_ptr<folly::fibers::HPromise<folly::Unit>> promise,
      Processor processor,
      std::shared_ptr<apache::thrift::RequestChannel> channel = nullptr)
      : FiberCallbackBase<folly::Unit>(promise, std::move(channel)),
        processor_(processor) {}

  void replyReceived(ClientReceiveState&& state) override {
    CHECK(!state.isException());
    CHECK(state.buf());

    auto ew = processor_(state);

    if (ew) {
      promise_->setException(ew);
    } else {
      promise_->setValue(folly::Unit());
    }
  }

 private:
  Processor processor_;
};

}} // Namespace
