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

#include <rsocket/Payload.h>
#include <thrift/lib/cpp2/async/AsyncProcessor.h>
#include <thrift/lib/cpp2/transport/core/StreamThriftChannelBase.h>
#include <thrift/lib/cpp2/transport/core/ThriftChannelIf.h>
#include <yarpl/Single.h>

namespace apache {
namespace thrift {

class RequestResponseThriftChannel : public StreamThriftChannelBase {
 public:
  explicit RequestResponseThriftChannel(
      folly::EventBase* evb,
      yarpl::Reference<yarpl::single::SingleObserver<rsocket::Payload>>
          subscriber)
      : StreamThriftChannelBase(evb), subscriber_(subscriber) {}

  void sendThriftResponse(
      std::unique_ptr<ResponseRpcMetadata> metadata,
      std::unique_ptr<folly::IOBuf> buf) noexcept override;

  folly::EventBase* getEventBase() noexcept override {
    return evb_;
  }

  static std::unique_ptr<folly::IOBuf> serializeMetadata(
      const ResponseRpcMetadata& responseMetadata);

  static std::unique_ptr<RequestRpcMetadata> deserializeMetadata(
      const folly::IOBuf& buffer);

 private:
  yarpl::Reference<yarpl::single::SingleObserver<rsocket::Payload>> subscriber_;
};
} // namespace thrift
} // namespace apache
