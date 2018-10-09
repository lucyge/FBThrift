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
#include "thrift/lib/cpp2/transport/rsocket/client/RSRequester.h"

#include <rsocket/framing/FramedDuplexConnection.h>
#include <rsocket/transports/tcp/TcpConnectionFactory.h>
#include <rsocket/transports/tcp/TcpDuplexConnection.h>
#include <thrift/lib/cpp2/async/ClientChannel.h>

namespace apache {
namespace thrift {

using namespace rsocket;

static std::shared_ptr<RSocketStateMachine> createStateMachine(
    apache::thrift::async::TAsyncTransport::UniquePtr socket,
    std::shared_ptr<RSocketConnectionEvents> events) {
  auto conn =
      TcpConnectionFactory::createDuplexConnectionFromSocket(std::move(socket));

  auto stateMachine = std::make_shared<RSocketStateMachine>(
      std::make_shared<RSocketResponder>(),
      nullptr,
      RSocketMode::CLIENT,
      nullptr,
      std::move(events),
      nullptr,
      nullptr);

  SetupParameters setupParameters;
  setupParameters.resumable = false; // Not resumable!

  std::unique_ptr<DuplexConnection> framedConn;
  if (conn->isFramed()) {
    framedConn = std::move(conn);
  } else {
    framedConn = std::make_unique<FramedDuplexConnection>(
        std::move(conn), setupParameters.protocolVersion);
  }
  auto transport = yarpl::make_ref<FrameTransportImpl>(std::move(framedConn));

  stateMachine->connectClient(std::move(transport), std::move(setupParameters));

  return stateMachine;
}

RSRequester::RSRequester(
    apache::thrift::async::TAsyncTransport::UniquePtr socket,
    folly::EventBase* evb,
    std::shared_ptr<RSocketConnectionEvents> status)
    : RSocketRequester(createStateMachine(std::move(socket), status), *evb) {}

RSRequester::~RSRequester() {
  closeNow();
}

void RSRequester::closeNow() {
  DCHECK(eventBase_ && eventBase_->isInEventBaseThread());

  if (auto stateMachine = std::move(stateMachine_)) {
    stateMachine->disconnect(folly::exception_wrapper());
    stateMachine->close(
        folly::exception_wrapper(), StreamCompletionSignal::SOCKET_CLOSED);
  }
}

void RSRequester::attachEventBase(folly::EventBase* evb) {
  eventBase_ = evb;
}

void RSRequester::detachEventBase() {
  eventBase_ = nullptr;
}

bool RSRequester::isDetachable() {
  return isDetachable_;
}

yarpl::Reference<yarpl::flowable::Flowable<rsocket::Payload>>
RSRequester::requestChannel(
    yarpl::Reference<yarpl::flowable::Flowable<rsocket::Payload>>
        requestStream) {
  isDetachable_ = false;

  return RSocketRequester::requestChannel(std::move(requestStream));
}

yarpl::Reference<yarpl::flowable::Flowable<Payload>> RSRequester::requestStream(
    Payload request) {
  isDetachable_ = false;

  return RSocketRequester::requestStream(std::move(request));
}

} // namespace thrift
} // namespace apache
