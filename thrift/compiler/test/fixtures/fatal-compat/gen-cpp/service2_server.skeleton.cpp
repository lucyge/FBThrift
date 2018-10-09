/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "thrift/compiler/test/fixtures/fatal-compat/gen-cpp/service2.h"
#include <thrift/lib/cpp/async/TEventServer.h>
#include <thrift/lib/cpp/server/TConnectionContext.h>
#include <thrift/lib/cpp/util/TEventServerCreator.h>

using apache::thrift::TProcessor;
using apache::thrift::async::TEventServer;
using apache::thrift::util::TEventServerCreator;

using std::shared_ptr;

using namespace  ::test_cpp1::cpp_reflection;

class service2Handler : virtual public service2If {
 public:
  service2Handler() {
    // Your initialization goes here
  }

  void methodA() {
    // Your implementation goes here
    printf("methodA\n");
  }

  void methodB(int32_t x, const struct1& y, double z) {
    // Your implementation goes here
    printf("methodB\n");
  }

  int32_t methodC() {
    // Your implementation goes here
    printf("methodC\n");
    return int32_t();
  }

  int32_t methodD(int32_t i, const struct1& j, double k) {
    // Your implementation goes here
    printf("methodD\n");
    return int32_t();
  }

  void methodE(struct2& _return) {
    // Your implementation goes here
    printf("methodE\n");
  }

  void methodF(struct2& _return, int32_t l, const struct1& m, double n) {
    // Your implementation goes here
    printf("methodF\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<service2Handler> handler(new service2Handler());
  shared_ptr<TProcessor> processor(new service2Processor(handler));
  TEventServerCreator serverCreator(processor, port);
  shared_ptr<TEventServer> server = serverCreator.createEventServer();
  server->serve();
  return 0;
}