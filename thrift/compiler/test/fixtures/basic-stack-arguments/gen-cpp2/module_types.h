/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/Thrift.h>
#include <thrift/lib/cpp2/protocol/Protocol.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <folly/io/IOBuf.h>
#include <folly/io/Cursor.h>

#include <thrift/lib/cpp2/GeneratedHeaderHelper.h>



namespace cpp2 {

class MyStruct;

enum class MyEnum {
  MyValue1 = 0,
  MyValue2 = 1
};

using _MyEnum_EnumMapFactory = apache::thrift::detail::TEnumMapFactory<MyEnum, MyEnum>;
extern const _MyEnum_EnumMapFactory::ValuesToNamesMapType _MyEnum_VALUES_TO_NAMES;
extern const _MyEnum_EnumMapFactory::NamesToValuesMapType _MyEnum_NAMES_TO_VALUES;

} // cpp2
namespace std {

template<> struct hash<typename  ::cpp2::MyEnum> : public apache::thrift::detail::enum_hash<typename  ::cpp2::MyEnum> {};
template<> struct equal_to<typename  ::cpp2::MyEnum> : public apache::thrift::detail::enum_equal_to<typename  ::cpp2::MyEnum> {};

} // std
namespace apache { namespace thrift {

template <> struct TEnumDataStorage< ::cpp2::MyEnum>;
template <> const std::size_t TEnumTraits< ::cpp2::MyEnum>::size;
template <> const folly::Range<const  ::cpp2::MyEnum*> TEnumTraits< ::cpp2::MyEnum>::values;
template <> const folly::Range<const folly::StringPiece*> TEnumTraits< ::cpp2::MyEnum>::names;
template <> const char* TEnumTraits< ::cpp2::MyEnum>::findName( ::cpp2::MyEnum value);
template <> bool TEnumTraits< ::cpp2::MyEnum>::findValue(const char* name,  ::cpp2::MyEnum* outValue);

template <> inline constexpr  ::cpp2::MyEnum TEnumTraits< ::cpp2::MyEnum>::min() {
  return  ::cpp2::MyEnum::MyValue1;
}

template <> inline constexpr  ::cpp2::MyEnum TEnumTraits< ::cpp2::MyEnum>::max() {
  return  ::cpp2::MyEnum::MyValue2;
}

}} // apache::thrift
namespace cpp2 {

class MyStruct final : private apache::thrift::detail::st::ComparisonOperators<MyStruct> {
 public:

  MyStruct() :
      MyIntField(0) {}
  // FragileConstructor for use in initialization lists only
  MyStruct(apache::thrift::FragileConstructor, int64_t MyIntField__arg, std::string MyStringField__arg);
  template <typename T__ThriftWrappedArgument__Ctor, typename... Args__ThriftWrappedArgument__Ctor>
  MyStruct(::apache::thrift::detail::argument_wrapper<1, T__ThriftWrappedArgument__Ctor> arg, Args__ThriftWrappedArgument__Ctor&&... args):
    MyStruct(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    MyIntField = arg.move();
    __isset.MyIntField = true;
  }
  template <typename T__ThriftWrappedArgument__Ctor, typename... Args__ThriftWrappedArgument__Ctor>
  MyStruct(::apache::thrift::detail::argument_wrapper<2, T__ThriftWrappedArgument__Ctor> arg, Args__ThriftWrappedArgument__Ctor&&... args):
    MyStruct(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    MyStringField = arg.move();
    __isset.MyStringField = true;
  }

  MyStruct(MyStruct&&) = default;

  MyStruct(const MyStruct&) = default;

  MyStruct& operator=(MyStruct&&) = default;

  MyStruct& operator=(const MyStruct&) = default;
  void __clear();
  int64_t MyIntField;
  std::string MyStringField;

  struct __isset {

    bool MyIntField;
    bool MyStringField;
  } __isset = {};
  bool operator==(const MyStruct& rhs) const;

  bool operator < (const MyStruct& rhs) const {
    if (!(MyIntField == rhs.MyIntField)) {
      return MyIntField < rhs.MyIntField;
    }
    if (!(MyStringField == rhs.MyStringField)) {
      return MyStringField < rhs.MyStringField;
    }
    (void)rhs;
    return false;
  }

  int64_t get_MyIntField() const {
    return MyIntField;
  }

  int64_t& set_MyIntField(int64_t MyIntField_) {
    MyIntField = MyIntField_;
    __isset.MyIntField = true;
    return MyIntField;
  }

  const std::string& get_MyStringField() const& {
    return MyStringField;
  }

  std::string get_MyStringField() && {
    return std::move(MyStringField);
  }

  template <typename T_MyStruct_MyStringField_struct_setter>
  std::string& set_MyStringField(T_MyStruct_MyStringField_struct_setter&& MyStringField_) {
    MyStringField = std::forward<T_MyStruct_MyStringField_struct_setter>(MyStringField_);
    __isset.MyStringField = true;
    return MyStringField;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  static void translateFieldName(FOLLY_MAYBE_UNUSED folly::StringPiece _fname, FOLLY_MAYBE_UNUSED int16_t& fid, FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype);
};

void swap(MyStruct& a, MyStruct& b);
extern template uint32_t MyStruct::read<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t MyStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t MyStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t MyStruct::read<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t MyStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t MyStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

} // cpp2
namespace apache { namespace thrift {

template <> inline void Cpp2Ops< ::cpp2::MyStruct>::clear( ::cpp2::MyStruct* obj) {
  return obj->__clear();
}

template <> inline constexpr apache::thrift::protocol::TType Cpp2Ops< ::cpp2::MyStruct>::thriftType() {
  return apache::thrift::protocol::T_STRUCT;
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::cpp2::MyStruct>::write(Protocol* proto,  ::cpp2::MyStruct const* obj) {
  return obj->write(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::cpp2::MyStruct>::read(Protocol* proto,  ::cpp2::MyStruct* obj) {
  return obj->read(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::cpp2::MyStruct>::serializedSize(Protocol const* proto,  ::cpp2::MyStruct const* obj) {
  return obj->serializedSize(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::cpp2::MyStruct>::serializedSizeZC(Protocol const* proto,  ::cpp2::MyStruct const* obj) {
  return obj->serializedSizeZC(proto);
}

}} // apache::thrift
namespace cpp2 {

} // cpp2
