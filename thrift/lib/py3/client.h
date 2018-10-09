/*
 * Copyright 2017 Facebook, Inc.
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

#include <cstdint>
#include <functional>

#include <folly/Try.h>
#include <folly/executors/GlobalExecutor.h>
#include <folly/futures/Future.h>
#include <folly/futures/Promise.h>
#include <thrift/lib/cpp/async/TAsyncSocket.h>
#include <thrift/lib/cpp2/async/HeaderClientChannel.h>
#include <thrift/lib/cpp2/async/RequestChannel.h>


namespace thrift {
namespace py3 {
typedef std::shared_ptr<apache::thrift::RequestChannel> RequestChannel_ptr;

/*
 * T is the cpp2 async client class
 * U is the py3 clientwraper class
 */
template <class T, class U>
std::shared_ptr<U> makeClientWrapper(RequestChannel_ptr channel) {
  auto client = std::make_shared<T>(channel);
  return std::make_shared<U>(client);
}

folly::Future<RequestChannel_ptr> createThriftChannel(
    const std::string& host,
    const uint16_t port,
    const uint32_t connect_timeout) {
  auto eb = folly::getEventBase();
  return folly::via(eb, [=] {
    return apache::thrift::HeaderClientChannel::newChannel(
        apache::thrift::async::TAsyncSocket::newSocket(
            eb, host, port, connect_timeout));
  });
}

} // namespace py3
} // namespace thrift
