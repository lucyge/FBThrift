/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp/Thrift.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <thrift/lib/cpp/protocol/TProtocol.h>
#include <thrift/lib/cpp/transport/TTransport.h>

namespace apache { namespace thrift { namespace reflection {
class Schema;
}}}


namespace apache { namespace thrift { namespace frozen { namespace schema {

class Field;

class Layout;

class Schema;

void swap(Field &a, Field &b);

class Field final : public apache::thrift::TStructType<Field> {
 public:

  static const uint64_t _reflection_id = 2361056240366028172U;
  static void _reflection_register(::apache::thrift::reflection::Schema&);
  Field() : layoutId(0), offset(0) {
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit Field(
    ::apache::thrift::detail::argument_wrapper<1, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    Field(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    layoutId = arg.move();
    __isset.layoutId = true;
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit Field(
    ::apache::thrift::detail::argument_wrapper<2, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    Field(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    offset = arg.move();
    __isset.offset = true;
  }

  Field(const Field&) = default;
  Field& operator=(const Field& src)= default;
  Field(Field&&) = default;
  Field& operator=(Field&&) = default;

  void __clear();
  int16_t layoutId;
  int16_t offset;

  struct __isset {
    __isset() { __clear(); } 
    void __clear() {
      layoutId = false;
      offset = false;
    }
    bool layoutId;
    bool offset;
  } __isset;

  bool operator == (const Field &) const;
  bool operator != (const Field& rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Field & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  static void translateFieldName(
      folly::StringPiece _fname,
      int16_t& fid,
      apache::thrift::protocol::TType& _ftype);
};

class Field;
void merge(const Field& from, Field& to);
void merge(Field&& from, Field& to);
void swap(Layout &a, Layout &b);

class Layout final : public apache::thrift::TStructType<Layout> {
 public:

  static const uint64_t _reflection_id = 3221448234020655692U;
  static void _reflection_register(::apache::thrift::reflection::Schema&);
  Layout() : size(0), bits(0) {
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit Layout(
    ::apache::thrift::detail::argument_wrapper<1, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    Layout(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    size = arg.move();
    __isset.size = true;
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit Layout(
    ::apache::thrift::detail::argument_wrapper<2, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    Layout(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    bits = arg.move();
    __isset.bits = true;
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit Layout(
    ::apache::thrift::detail::argument_wrapper<3, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    Layout(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    fields = arg.move();
    __isset.fields = true;
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit Layout(
    ::apache::thrift::detail::argument_wrapper<4, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    Layout(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    typeName = arg.move();
    __isset.typeName = true;
  }

  Layout(const Layout&) = default;
  Layout& operator=(const Layout& src)= default;
  Layout(Layout&&) = default;
  Layout& operator=(Layout&&) = default;

  void __clear();
  int32_t size;
  int16_t bits;
  std::map<int16_t, Field>  fields;
  std::string typeName;

  struct __isset {
    __isset() { __clear(); } 
    void __clear() {
      size = false;
      bits = false;
      fields = false;
      typeName = false;
    }
    bool size;
    bool bits;
    bool fields;
    bool typeName;
  } __isset;

  bool operator == (const Layout &) const;
  bool operator != (const Layout& rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Layout & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  static void translateFieldName(
      folly::StringPiece _fname,
      int16_t& fid,
      apache::thrift::protocol::TType& _ftype);
};

class Layout;
void merge(const Layout& from, Layout& to);
void merge(Layout&& from, Layout& to);
void swap(Schema &a, Schema &b);

class Schema final : public apache::thrift::TStructType<Schema> {
 public:

  static const uint64_t _reflection_id = 6060681111115730220U;
  static void _reflection_register(::apache::thrift::reflection::Schema&);
  Schema() : fileVersion(0), relaxTypeChecks(false), rootLayout(0) {
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit Schema(
    ::apache::thrift::detail::argument_wrapper<4, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    Schema(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    fileVersion = arg.move();
    __isset.fileVersion = true;
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit Schema(
    ::apache::thrift::detail::argument_wrapper<1, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    Schema(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    relaxTypeChecks = arg.move();
    __isset.relaxTypeChecks = true;
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit Schema(
    ::apache::thrift::detail::argument_wrapper<2, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    Schema(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    layouts = arg.move();
    __isset.layouts = true;
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit Schema(
    ::apache::thrift::detail::argument_wrapper<3, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    Schema(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    rootLayout = arg.move();
    __isset.rootLayout = true;
  }

  Schema(const Schema&) = default;
  Schema& operator=(const Schema& src)= default;
  Schema(Schema&&) = default;
  Schema& operator=(Schema&&) = default;

  void __clear();
  int32_t fileVersion;
  bool relaxTypeChecks;
  std::map<int16_t, Layout>  layouts;
  int16_t rootLayout;

  struct __isset {
    __isset() { __clear(); } 
    void __clear() {
      fileVersion = false;
      relaxTypeChecks = false;
      layouts = false;
      rootLayout = false;
    }
    bool fileVersion;
    bool relaxTypeChecks;
    bool layouts;
    bool rootLayout;
  } __isset;

  bool operator == (const Schema &) const;
  bool operator != (const Schema& rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Schema & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  static void translateFieldName(
      folly::StringPiece _fname,
      int16_t& fid,
      apache::thrift::protocol::TType& _ftype);
};

class Schema;
void merge(const Schema& from, Schema& to);
void merge(Schema&& from, Schema& to);
}}}} // namespace

#include "thrift/lib/thrift/gen-cpp/frozen_types.tcc"

