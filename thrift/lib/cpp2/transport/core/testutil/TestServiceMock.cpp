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

#include <thrift/lib/cpp2/transport/core/testutil/TestServiceMock.h>
#include <thrift/lib/cpp2/transport/core/ThriftClient.h>
#include <thrift/lib/cpp2/transport/util/ConnectionManager.h>

#include <chrono>
#include <thread>

namespace testutil {
namespace testservice {

using namespace apache::thrift;

int32_t TestServiceMock::sumTwoNumbers(int32_t x, int32_t y) {
  sumTwoNumbers_(x, y); // just inform that this function is called
  return x + y;
}

int32_t TestServiceMock::add(int32_t x) {
  add_(x); // just inform that this function is called
  sum += x;
  return sum;
}

void TestServiceMock::addAfterDelay(int32_t delayMs, int32_t x) {
  /* sleep override */
  std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
  addAfterDelay_(delayMs, x); // just to inform that this function is called
  sum += x;
}

void TestServiceMock::onewayThrowsUnexpectedException(int32_t delayMs) {
  onewayThrowsUnexpectedException_(delayMs);
  std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
  throw std::runtime_error("mock_runtime_error");
}

void TestServiceMock::throwExpectedException(int32_t) {
  TestServiceException exception;
  exception.message = "mock_service_method_exception";
  throw exception;
}

void TestServiceMock::throwUnexpectedException(int32_t) {
  throw std::runtime_error("mock_runtime_error");
}

void TestServiceMock::sleep(int32_t timeMs) {
  /* sleep override */
  std::this_thread::sleep_for(std::chrono::milliseconds(timeMs));
}

void TestServiceMock::headers() {
  auto header = getConnectionContext()->getHeader();

  // Even if the method throws or not, put the header value and check if reaches
  // to the client in any case or not
  header->setHeader("header_from_server", "1");

  auto keyValue = header->getHeaders();
  if (keyValue.find("unexpected_exception") != keyValue.end()) {
    throw std::runtime_error("unexpected exception");
  }

  if (keyValue.find("expected_exception") != keyValue.end()) {
    TestServiceException exception;
    exception.message = "expected exception";
    throw exception;
  }

  if (keyValue.find("header_from_client") == keyValue.end() ||
      keyValue.find("header_from_client")->second != "2") {
    TestServiceException exception;
    exception.message = "Expected key/value, foo:bar, is missing";
    throw exception;
  }
}

void TestServiceMock::hello(
    std::string& result,
    std::unique_ptr<std::string> name) {
  hello_(*name);
  result = "Hello, " + *name;
}

IntermHeaderService::IntermHeaderService(std::string const& host, int16_t port)
    : clientWorkerThread_{"CompatIntermServerWorker"} {
  auto mgr = ConnectionManager::getInstance();
  auto connection = mgr->getConnection(host, port);
  auto channel = ThriftClient::Ptr(
      new ThriftClient(connection, clientWorkerThread_.getEventBase()));
  channel->setProtocolId(apache::thrift::protocol::T_COMPACT_PROTOCOL);
  client_ = std::make_unique<TestServiceAsyncClient>(std::move(channel));
}

int32_t IntermHeaderService::callAdd(int32_t x) {
  auto rq = folly::RequestContext::get();
  auto ret = client_->sync_add(x);
  EXPECT_EQ(rq, folly::RequestContext::get());
  return ret;
}

} // namespace testservice
} // namespace testutil
