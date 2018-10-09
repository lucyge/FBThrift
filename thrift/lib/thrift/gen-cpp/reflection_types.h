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

#include <unordered_map>

namespace apache { namespace thrift { namespace reflection {

enum Type {
  TYPE_VOID = 0,
  TYPE_STRING = 1,
  TYPE_BOOL = 2,
  TYPE_BYTE = 3,
  TYPE_I16 = 4,
  TYPE_I32 = 5,
  TYPE_I64 = 6,
  TYPE_DOUBLE = 7,
  TYPE_ENUM = 8,
  TYPE_LIST = 9,
  TYPE_SET = 10,
  TYPE_MAP = 11,
  TYPE_STRUCT = 12,
  TYPE_SERVICE = 13,
  TYPE_PROGRAM = 14,
  TYPE_FLOAT = 15,
};

using _Type_EnumMapFactory = apache::thrift::detail::TEnumMapFactory<Type, int>;

extern const _Type_EnumMapFactory::ValuesToNamesMapType _Type_VALUES_TO_NAMES;

extern const _Type_EnumMapFactory::NamesToValuesMapType _Type_NAMES_TO_VALUES;

}}} // namespace
namespace apache { namespace thrift {
template <> struct TEnumDataStorage< ::apache::thrift::reflection::Type>;
template <> const std::size_t TEnumTraits< ::apache::thrift::reflection::Type>::size;
template <> const folly::Range<const  ::apache::thrift::reflection::Type*> TEnumTraits< ::apache::thrift::reflection::Type>::values;
template <> const folly::Range<const folly::StringPiece*> TEnumTraits< ::apache::thrift::reflection::Type>::names;
template <> inline constexpr  ::apache::thrift::reflection::Type TEnumTraits< ::apache::thrift::reflection::Type>::min() {
return  ::apache::thrift::reflection::Type::TYPE_VOID;
}
template <> inline constexpr  ::apache::thrift::reflection::Type TEnumTraits< ::apache::thrift::reflection::Type>::max() {
return  ::apache::thrift::reflection::Type::TYPE_FLOAT;
}
}} // apache::thrift

namespace apache { namespace thrift { namespace reflection {

class StructField;

class DataType;

class Schema;

void swap(StructField &a, StructField &b);

class StructField final : public apache::thrift::TStructType<StructField> {
 public:

  static const uint64_t _reflection_id = 214309804125196972U;
  static void _reflection_register(::apache::thrift::reflection::Schema&);
  StructField() : isRequired(0), type(0), order(0) {
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit StructField(
    ::apache::thrift::detail::argument_wrapper<1, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    StructField(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    isRequired = arg.move();
    __isset.isRequired = true;
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit StructField(
    ::apache::thrift::detail::argument_wrapper<2, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    StructField(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    type = arg.move();
    __isset.type = true;
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit StructField(
    ::apache::thrift::detail::argument_wrapper<3, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    StructField(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    name = arg.move();
    __isset.name = true;
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit StructField(
    ::apache::thrift::detail::argument_wrapper<4, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    StructField(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    annotations = arg.move();
    __isset.annotations = true;
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit StructField(
    ::apache::thrift::detail::argument_wrapper<5, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    StructField(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    order = arg.move();
    __isset.order = true;
  }

  StructField(const StructField&) = default;
  StructField& operator=(const StructField& src)= default;
  StructField(StructField&&) = default;
  StructField& operator=(StructField&&) = default;

  void __clear();
  bool isRequired;
  int64_t type;
  std::string name;
  std::unordered_map<std::string, std::string>  annotations;
  int16_t order;

  struct __isset {
    __isset() { __clear(); } 
    void __clear() {
      isRequired = false;
      type = false;
      name = false;
      annotations = false;
      order = false;
    }
    bool isRequired;
    bool type;
    bool name;
    bool annotations;
    bool order;
  } __isset;

  bool operator == (const StructField &) const;
  bool operator != (const StructField& rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const StructField & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  static void translateFieldName(
      folly::StringPiece _fname,
      int16_t& fid,
      apache::thrift::protocol::TType& _ftype);
};

class StructField;
void merge(const StructField& from, StructField& to);
void merge(StructField&& from, StructField& to);
void swap(DataType &a, DataType &b);

class DataType final : public apache::thrift::TStructType<DataType> {
 public:

  static const uint64_t _reflection_id = 4733295045172396908U;
  static void _reflection_register(::apache::thrift::reflection::Schema&);
  DataType() : mapKeyType(0), valueType(0) {
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit DataType(
    ::apache::thrift::detail::argument_wrapper<1, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    DataType(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    name = arg.move();
    __isset.name = true;
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit DataType(
    ::apache::thrift::detail::argument_wrapper<2, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    DataType(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    fields = arg.move();
    __isset.fields = true;
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit DataType(
    ::apache::thrift::detail::argument_wrapper<3, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    DataType(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    mapKeyType = arg.move();
    __isset.mapKeyType = true;
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit DataType(
    ::apache::thrift::detail::argument_wrapper<4, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    DataType(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    valueType = arg.move();
    __isset.valueType = true;
  }
  template <
    typename T__ThriftWrappedArgument__Ctor,
    typename... Args__ThriftWrappedArgument__Ctor
  >
  explicit DataType(
    ::apache::thrift::detail::argument_wrapper<5, T__ThriftWrappedArgument__Ctor> arg,
    Args__ThriftWrappedArgument__Ctor&&... args
  ):
    DataType(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    enumValues = arg.move();
    __isset.enumValues = true;
  }

  DataType(const DataType&) = default;
  DataType& operator=(const DataType& src)= default;
  DataType(DataType&&) = default;
  DataType& operator=(DataType&&) = default;

  void __clear();
  std::string name;
  std::unordered_map<int16_t, StructField>  fields;
  int64_t mapKeyType;
  int64_t valueType;
  std::unordered_map<std::string, int32_t>  enumValues;

  struct __isset {
    __isset() { __clear(); } 
    void __clear() {
      name = false;
      fields = false;
      mapKeyType = false;
      valueType = false;
      enumValues = false;
    }
    bool name;
    bool fields;
    bool mapKeyType;
    bool valueType;
    bool enumValues;
  } __isset;

  bool operator == (const DataType &) const;
  bool operator != (const DataType& rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataType & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  static void translateFieldName(
      folly::StringPiece _fname,
      int16_t& fid,
      apache::thrift::protocol::TType& _ftype);
};

class DataType;
void merge(const DataType& from, DataType& to);
void merge(DataType&& from, DataType& to);
void swap(Schema &a, Schema &b);

class Schema final : public apache::thrift::TStructType<Schema> {
 public:

  static const uint64_t _reflection_id = 6902704939566307148U;
  static void _reflection_register(::apache::thrift::reflection::Schema&);
  Schema() {
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
    dataTypes = arg.move();
    __isset.dataTypes = true;
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
    names = arg.move();
    __isset.names = true;
  }

  Schema(const Schema&) = default;
  Schema& operator=(const Schema& src)= default;
  Schema(Schema&&) = default;
  Schema& operator=(Schema&&) = default;

  void __clear();
  std::unordered_map<int64_t, DataType>  dataTypes;
  std::unordered_map<std::string, int64_t>  names;

  struct __isset {
    __isset() { __clear(); } 
    void __clear() {
      dataTypes = false;
      names = false;
    }
    bool dataTypes;
    bool names;
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
}}} // namespace

#include "thrift/lib/thrift/gen-cpp/reflection_types.tcc"
