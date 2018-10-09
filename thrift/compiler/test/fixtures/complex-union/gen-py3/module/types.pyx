#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from libcpp.memory cimport shared_ptr, make_shared, unique_ptr, make_unique
from libcpp.string cimport string
from libcpp cimport bool as cbool
from libcpp.iterator cimport inserter as cinserter
from cpython cimport bool as pbool
from libc.stdint cimport int8_t, int16_t, int32_t, int64_t, uint32_t
from cython.operator cimport dereference as deref, preincrement as inc
import thrift.py3.types
cimport thrift.py3.types
cimport thrift.py3.exceptions
from thrift.py3.types import NOTSET as __NOTSET
from thrift.py3.types cimport translate_cpp_enum_to_python
cimport thrift.py3.std_libcpp as std_libcpp
from thrift.py3.serializer cimport IOBuf
from thrift.py3.serializer import Protocol
cimport thrift.py3.serializer as serializer
from thrift.py3.serializer import deserialize, serialize
from folly.optional cimport cOptional

import sys
import itertools
from collections import Sequence, Set, Mapping, Iterable
import enum as __enum
import warnings
import builtins as _builtins




class ComplexUnionType(__enum.Enum):
    EMPTY = <int>cComplexUnion__type___EMPTY__
    intValue = <int>cComplexUnion__type_intValue
    stringValue = <int>cComplexUnion__type_stringValue
    intListValue = <int>cComplexUnion__type_intListValue
    stringListValue = <int>cComplexUnion__type_stringListValue
    typedefValue = <int>cComplexUnion__type_typedefValue
    stringRef = <int>cComplexUnion__type_stringRef

cdef class ComplexUnion(thrift.py3.types.Union):
    def __init__(
        ComplexUnion self, *,
        intValue=None,
        str stringValue=None,
        intListValue=None,
        stringListValue=None,
        typedefValue=None,
        str stringRef=None
    ):
        if intValue is not None:
            if not isinstance(intValue, int):
                raise TypeError(f'intValue is not a { int !r}.')
            <int64_t> intValue

        self._cpp_obj = move(ComplexUnion._make_instance(
          NULL,
          intValue,
          stringValue,
          intListValue,
          stringListValue,
          typedefValue,
          stringRef,
        ))
        self._load_cache()

    @staticmethod
    def fromValue(value):
        if value is None:
            return ComplexUnion()
        if isinstance(value, int):
            if not isinstance(value, pbool):
                try:
                    <int64_t> value
                    return ComplexUnion(intValue=value)
                except OverflowError:
                    pass
        if isinstance(value, str):
            return ComplexUnion(stringValue=value)
        if isinstance(value, List__i64):
            return ComplexUnion(intListValue=value)
        if isinstance(value, List__string):
            return ComplexUnion(stringListValue=value)
        if isinstance(value, Map__i16_string):
            return ComplexUnion(typedefValue=value)
        if isinstance(value, str):
            return ComplexUnion(stringRef=value)
        raise ValueError(f"Unable to derive correct union field for value: {value}")

    @staticmethod
    cdef unique_ptr[cComplexUnion] _make_instance(
        cComplexUnion* base_instance,
        intValue,
        stringValue,
        intListValue,
        stringListValue,
        typedefValue,
        stringRef
    ) except *:
        cdef unique_ptr[cComplexUnion] c_inst = make_unique[cComplexUnion]()
        cdef bint any_set = False
        if intValue is not None:
            if any_set:
                raise TypeError("At most one field may be set when initializing a union")
            deref(c_inst).set_intValue(intValue)
            any_set = True
        if stringValue is not None:
            if any_set:
                raise TypeError("At most one field may be set when initializing a union")
            deref(c_inst).set_stringValue(stringValue.encode('UTF-8'))
            any_set = True
        if intListValue is not None:
            if any_set:
                raise TypeError("At most one field may be set when initializing a union")
            deref(c_inst).set_intListValue(<vector[int64_t]>deref(List__i64(intListValue)._cpp_obj))
            any_set = True
        if stringListValue is not None:
            if any_set:
                raise TypeError("At most one field may be set when initializing a union")
            deref(c_inst).set_stringListValue(<vector[string]>deref(List__string(stringListValue)._cpp_obj))
            any_set = True
        if typedefValue is not None:
            if any_set:
                raise TypeError("At most one field may be set when initializing a union")
            deref(c_inst).set_typedefValue(<cmap[int16_t,string]>deref(Map__i16_string(typedefValue)._cpp_obj))
            any_set = True
        if stringRef is not None:
            if any_set:
                raise TypeError("At most one field may be set when initializing a union")
            deref(c_inst).set_stringRef(string(deref((<str?>stringRef)._cpp_obj)))
            any_set = True
        # in C++ you don't have to call move(), but this doesn't translate
        # into a C++ return statement, so you do here
        return move_unique(c_inst)

    def __bool__(self):
        return self.type != ComplexUnionType.EMPTY

    @staticmethod
    cdef create(shared_ptr[cComplexUnion] cpp_obj):
        inst = <ComplexUnion>ComplexUnion.__new__(ComplexUnion)
        inst._cpp_obj = cpp_obj
        inst._load_cache()
        return inst

    @property
    def intValue(self):
        if self.type != ComplexUnionType.intValue:
            raise TypeError(f'Union contains a value of type {self.type.name}, not intValue')
        return self.value

    @property
    def stringValue(self):
        if self.type != ComplexUnionType.stringValue:
            raise TypeError(f'Union contains a value of type {self.type.name}, not stringValue')
        return self.value

    @property
    def intListValue(self):
        if self.type != ComplexUnionType.intListValue:
            raise TypeError(f'Union contains a value of type {self.type.name}, not intListValue')
        return self.value

    @property
    def stringListValue(self):
        if self.type != ComplexUnionType.stringListValue:
            raise TypeError(f'Union contains a value of type {self.type.name}, not stringListValue')
        return self.value

    @property
    def typedefValue(self):
        if self.type != ComplexUnionType.typedefValue:
            raise TypeError(f'Union contains a value of type {self.type.name}, not typedefValue')
        return self.value

    @property
    def stringRef(self):
        if self.type != ComplexUnionType.stringRef:
            raise TypeError(f'Union contains a value of type {self.type.name}, not stringRef')
        return self.value


    def __hash__(ComplexUnion self):
        if not self.__hash:
            self.__hash = hash((
                self.type,
                self.value,
            ))
        return self.__hash

    def __repr__(ComplexUnion self):
        return f'ComplexUnion(type={self.type.name}, value={self.value!r})'

    cdef _load_cache(ComplexUnion self):
        self.type = ComplexUnionType(<int>(deref(self._cpp_obj).getType()))
        if self.type == ComplexUnionType.EMPTY:
            self.value = None
        elif self.type == ComplexUnionType.intValue:
            self.value = deref(self._cpp_obj).get_intValue()
        elif self.type == ComplexUnionType.stringValue:
            self.value = bytes(deref(self._cpp_obj).get_stringValue()).decode('UTF-8')
        elif self.type == ComplexUnionType.intListValue:
            self.value = List__i64.create(make_shared[vector[int64_t]](deref(self._cpp_obj).get_intListValue()))
        elif self.type == ComplexUnionType.stringListValue:
            self.value = List__string.create(make_shared[vector[string]](deref(self._cpp_obj).get_stringListValue()))
        elif self.type == ComplexUnionType.typedefValue:
            self.value = Map__i16_string.create(make_shared[cmap[int16_t,string]](deref(self._cpp_obj).get_typedefValue()))
        elif self.type == ComplexUnionType.stringRef:
            if not deref(self._cpp_obj).get_stringRef():
                self.value = None
            else:
                self.value = str.create(aliasing_constructor_stringRef(self._cpp_obj, (deref(self._cpp_obj).get_stringRef()).get()))

    def get_type(ComplexUnion self):
        return self.type

    def __richcmp__(self, other, op):
        cdef int cop = op
        if cop not in (2, 3):
            raise TypeError("unorderable types: {}, {}".format(self, other))
        if not (
                isinstance(self, ComplexUnion) and
                isinstance(other, ComplexUnion)):
            if cop == 2:  # different types are never equal
                return False
            else:         # different types are always notequal
                return True

        cdef cComplexUnion cself = deref((<ComplexUnion>self)._cpp_obj)
        cdef cComplexUnion cother = deref((<ComplexUnion>other)._cpp_obj)
        cdef cbool cmp = cself == cother
        if cop == 2:
            return cmp
        return not cmp

    cdef bytes _serialize(ComplexUnion self, proto):
        cdef string c_str
        if proto is Protocol.COMPACT:
            serializer.CompactSerialize[cComplexUnion](deref(self._cpp_obj.get()), &c_str)
        elif proto is Protocol.BINARY:
            serializer.BinarySerialize[cComplexUnion](deref(self._cpp_obj.get()), &c_str)
        elif proto is Protocol.JSON:
            serializer.JSONSerialize[cComplexUnion](deref(self._cpp_obj.get()), &c_str)
        return <bytes> c_str

    cdef uint32_t _deserialize(ComplexUnion self, const IOBuf* buf, proto):
        cdef uint32_t needed
        self._cpp_obj = make_shared[cComplexUnion]()
        if proto is Protocol.COMPACT:
            needed = serializer.CompactDeserialize[cComplexUnion](buf, deref(self._cpp_obj.get()))
        elif proto is Protocol.BINARY:
            needed = serializer.BinaryDeserialize[cComplexUnion](buf, deref(self._cpp_obj.get()))
        elif proto is Protocol.JSON:
            needed = serializer.JSONDeserialize[cComplexUnion](buf, deref(self._cpp_obj.get()))
        # force a cache reload since the underlying data's changed
        self._load_cache()
        return needed

    def __reduce__(self):
        return (deserialize, (ComplexUnion, serialize(self)))


class VirtualComplexUnionType(__enum.Enum):
    EMPTY = <int>cVirtualComplexUnion__type___EMPTY__
    thingOne = <int>cVirtualComplexUnion__type_thingOne
    thingTwo = <int>cVirtualComplexUnion__type_thingTwo

cdef class VirtualComplexUnion(thrift.py3.types.Union):
    def __init__(
        VirtualComplexUnion self, *,
        str thingOne=None,
        str thingTwo=None
    ):
        self._cpp_obj = move(VirtualComplexUnion._make_instance(
          NULL,
          thingOne,
          thingTwo,
        ))
        self._load_cache()

    @staticmethod
    def fromValue(value):
        if value is None:
            return VirtualComplexUnion()
        if isinstance(value, str):
            return VirtualComplexUnion(thingOne=value)
        if isinstance(value, str):
            return VirtualComplexUnion(thingTwo=value)
        raise ValueError(f"Unable to derive correct union field for value: {value}")

    @staticmethod
    cdef unique_ptr[cVirtualComplexUnion] _make_instance(
        cVirtualComplexUnion* base_instance,
        thingOne,
        thingTwo
    ) except *:
        cdef unique_ptr[cVirtualComplexUnion] c_inst = make_unique[cVirtualComplexUnion]()
        cdef bint any_set = False
        if thingOne is not None:
            if any_set:
                raise TypeError("At most one field may be set when initializing a union")
            deref(c_inst).set_thingOne(thingOne.encode('UTF-8'))
            any_set = True
        if thingTwo is not None:
            if any_set:
                raise TypeError("At most one field may be set when initializing a union")
            deref(c_inst).set_thingTwo(thingTwo.encode('UTF-8'))
            any_set = True
        # in C++ you don't have to call move(), but this doesn't translate
        # into a C++ return statement, so you do here
        return move_unique(c_inst)

    def __bool__(self):
        return self.type != VirtualComplexUnionType.EMPTY

    @staticmethod
    cdef create(shared_ptr[cVirtualComplexUnion] cpp_obj):
        inst = <VirtualComplexUnion>VirtualComplexUnion.__new__(VirtualComplexUnion)
        inst._cpp_obj = cpp_obj
        inst._load_cache()
        return inst

    @property
    def thingOne(self):
        if self.type != VirtualComplexUnionType.thingOne:
            raise TypeError(f'Union contains a value of type {self.type.name}, not thingOne')
        return self.value

    @property
    def thingTwo(self):
        if self.type != VirtualComplexUnionType.thingTwo:
            raise TypeError(f'Union contains a value of type {self.type.name}, not thingTwo')
        return self.value


    def __hash__(VirtualComplexUnion self):
        if not self.__hash:
            self.__hash = hash((
                self.type,
                self.value,
            ))
        return self.__hash

    def __repr__(VirtualComplexUnion self):
        return f'VirtualComplexUnion(type={self.type.name}, value={self.value!r})'

    cdef _load_cache(VirtualComplexUnion self):
        self.type = VirtualComplexUnionType(<int>(deref(self._cpp_obj).getType()))
        if self.type == VirtualComplexUnionType.EMPTY:
            self.value = None
        elif self.type == VirtualComplexUnionType.thingOne:
            self.value = bytes(deref(self._cpp_obj).get_thingOne()).decode('UTF-8')
        elif self.type == VirtualComplexUnionType.thingTwo:
            self.value = bytes(deref(self._cpp_obj).get_thingTwo()).decode('UTF-8')

    def get_type(VirtualComplexUnion self):
        return self.type

    def __richcmp__(self, other, op):
        cdef int cop = op
        if cop not in (2, 3):
            raise TypeError("unorderable types: {}, {}".format(self, other))
        if not (
                isinstance(self, VirtualComplexUnion) and
                isinstance(other, VirtualComplexUnion)):
            if cop == 2:  # different types are never equal
                return False
            else:         # different types are always notequal
                return True

        cdef cVirtualComplexUnion cself = deref((<VirtualComplexUnion>self)._cpp_obj)
        cdef cVirtualComplexUnion cother = deref((<VirtualComplexUnion>other)._cpp_obj)
        cdef cbool cmp = cself == cother
        if cop == 2:
            return cmp
        return not cmp

    cdef bytes _serialize(VirtualComplexUnion self, proto):
        cdef string c_str
        if proto is Protocol.COMPACT:
            serializer.CompactSerialize[cVirtualComplexUnion](deref(self._cpp_obj.get()), &c_str)
        elif proto is Protocol.BINARY:
            serializer.BinarySerialize[cVirtualComplexUnion](deref(self._cpp_obj.get()), &c_str)
        elif proto is Protocol.JSON:
            serializer.JSONSerialize[cVirtualComplexUnion](deref(self._cpp_obj.get()), &c_str)
        return <bytes> c_str

    cdef uint32_t _deserialize(VirtualComplexUnion self, const IOBuf* buf, proto):
        cdef uint32_t needed
        self._cpp_obj = make_shared[cVirtualComplexUnion]()
        if proto is Protocol.COMPACT:
            needed = serializer.CompactDeserialize[cVirtualComplexUnion](buf, deref(self._cpp_obj.get()))
        elif proto is Protocol.BINARY:
            needed = serializer.BinaryDeserialize[cVirtualComplexUnion](buf, deref(self._cpp_obj.get()))
        elif proto is Protocol.JSON:
            needed = serializer.JSONDeserialize[cVirtualComplexUnion](buf, deref(self._cpp_obj.get()))
        # force a cache reload since the underlying data's changed
        self._load_cache()
        return needed

    def __reduce__(self):
        return (deserialize, (VirtualComplexUnion, serialize(self)))


cdef class List__i64:
    def __init__(self, items=None):
        if isinstance(items, List__i64):
            self._cpp_obj = (<List__i64> items)._cpp_obj
        else:
            self._cpp_obj = move(List__i64._make_instance(items))

    @staticmethod
    cdef create(shared_ptr[vector[int64_t]] c_items):
        inst = <List__i64>List__i64.__new__(List__i64)
        inst._cpp_obj = c_items
        return inst

    @staticmethod
    cdef unique_ptr[vector[int64_t]] _make_instance(object items) except *:
        cdef unique_ptr[vector[int64_t]] c_inst = make_unique[vector[int64_t]]()
        if items is not None:
            for item in items:
                if not isinstance(item, int):
                    raise TypeError(f"{item!r} is not of type int")
                <int64_t> item
                deref(c_inst).push_back(item)
        return move_unique(c_inst)

    def __add__(object self, object other):
        return type(self)(itertools.chain(self, other))

    def __getitem__(self, object index_obj):
        cdef shared_ptr[vector[int64_t]] c_inst
        cdef int64_t citem
        if isinstance(index_obj, slice):
            c_inst = make_shared[vector[int64_t]]()
            start_val = index_obj.start
            stop_val = index_obj.stop
            step_val = index_obj.step
            sz = deref(self._cpp_obj).size()

            if step_val == 0 or step_val is None:
                step_val = 1
            if step_val > 0:
                if start_val is None:
                    start_val = 0
                elif start_val > sz:
                    start_val = sz
                if stop_val is None:
                    stop_val = sz
                elif stop_val > sz:
                    stop_val = sz
            else:
                if start_val is None:
                    start_val = sz - 1
                elif start_val > sz - 1:
                    start_val = sz - 1
                if stop_val is None:
                    stop_val = -1
                elif stop_val > sz - 1:
                    stop_val = sz - 1

            index = start_val
            while ((step_val > 0 and index < stop_val) or
                   (step_val < 0 and index > stop_val)):
                citem = deref(self._cpp_obj.get())[index]
                deref(c_inst).push_back(citem)
                index += step_val
            return List__i64.create(c_inst)
        else:
            index = <int?>index_obj
            size = len(self)
            # Convert a negative index
            if index < 0:
                index = size + index
            if index >= size or index < 0:
                raise IndexError('list index out of range')
            citem = deref(self._cpp_obj.get())[index]
            return citem

    def __len__(self):
        return deref(self._cpp_obj).size()

    def __richcmp__(self, other, op):
        cdef int cop = op
        if cop not in (2, 3):
            raise TypeError("unorderable types: {}, {}".format(type(self), type(other)))
        if not (isinstance(self, Iterable) and isinstance(other, Iterable)):
            return cop != 2
        if (len(self) != len(other)):
            return cop != 2

        for one, two in zip(self, other):
            if one != two:
                return cop != 2

        return cop == 2

    def __hash__(self):
        if not self.__hash:
            self.__hash = hash(tuple(self))
        return self.__hash

    def __contains__(self, item):
        if not self:
            return False
        cdef int64_t citem = item
        cdef vector[int64_t] vec = deref(
            self._cpp_obj.get())
        return std_libcpp.find(vec.begin(), vec.end(), citem) != vec.end()

    def __iter__(self):
        if not self:
            raise StopIteration
        cdef int64_t citem
        for citem in deref(self._cpp_obj):
            yield citem

    def __repr__(self):
        if not self:
            return 'i[]'
        return f'i[{", ".join(map(repr, self))}]'

    def __reversed__(self):
        if not self:
            raise StopIteration
        cdef int64_t citem
        cdef vector[int64_t] vec = deref(
            self._cpp_obj.get())
        cdef vector[int64_t].reverse_iterator loc = vec.rbegin()
        while loc != vec.rend():
            citem = deref(loc)
            yield citem
            inc(loc)

    def index(self, item):
        if not self:
            raise ValueError(f'{item} is not in list')
        cdef int64_t citem = item
        cdef vector[int64_t] vec = deref(self._cpp_obj.get())
        cdef vector[int64_t].iterator loc = std_libcpp.find(vec.begin(), vec.end(), citem)
        if loc != vec.end():
            return <int64_t> std_libcpp.distance(vec.begin(), loc)
        raise ValueError(f'{item} is not in list')

    def count(self, item):
        if not self:
            return 0
        cdef int64_t citem = item
        cdef vector[int64_t] vec = deref(self._cpp_obj.get())
        return <int64_t> std_libcpp.count(vec.begin(), vec.end(), citem)


Sequence.register(List__i64)

cdef class List__string:
    def __init__(self, items=None):
        if isinstance(items, List__string):
            self._cpp_obj = (<List__string> items)._cpp_obj
        else:
            self._cpp_obj = move(List__string._make_instance(items))

    @staticmethod
    cdef create(shared_ptr[vector[string]] c_items):
        inst = <List__string>List__string.__new__(List__string)
        inst._cpp_obj = c_items
        return inst

    @staticmethod
    cdef unique_ptr[vector[string]] _make_instance(object items) except *:
        cdef unique_ptr[vector[string]] c_inst = make_unique[vector[string]]()
        if items is not None:
            for item in items:
                if not isinstance(item, str):
                    raise TypeError(f"{item!r} is not of type str")
                deref(c_inst).push_back(item.encode('UTF-8'))
        return move_unique(c_inst)

    def __add__(object self, object other):
        return type(self)(itertools.chain(self, other))

    def __getitem__(self, object index_obj):
        cdef shared_ptr[vector[string]] c_inst
        cdef string citem
        if isinstance(index_obj, slice):
            c_inst = make_shared[vector[string]]()
            start_val = index_obj.start
            stop_val = index_obj.stop
            step_val = index_obj.step
            sz = deref(self._cpp_obj).size()

            if step_val == 0 or step_val is None:
                step_val = 1
            if step_val > 0:
                if start_val is None:
                    start_val = 0
                elif start_val > sz:
                    start_val = sz
                if stop_val is None:
                    stop_val = sz
                elif stop_val > sz:
                    stop_val = sz
            else:
                if start_val is None:
                    start_val = sz - 1
                elif start_val > sz - 1:
                    start_val = sz - 1
                if stop_val is None:
                    stop_val = -1
                elif stop_val > sz - 1:
                    stop_val = sz - 1

            index = start_val
            while ((step_val > 0 and index < stop_val) or
                   (step_val < 0 and index > stop_val)):
                citem = deref(self._cpp_obj.get())[index]
                deref(c_inst).push_back(citem)
                index += step_val
            return List__string.create(c_inst)
        else:
            index = <int?>index_obj
            size = len(self)
            # Convert a negative index
            if index < 0:
                index = size + index
            if index >= size or index < 0:
                raise IndexError('list index out of range')
            citem = deref(self._cpp_obj.get())[index]
            return bytes(citem).decode('UTF-8')

    def __len__(self):
        return deref(self._cpp_obj).size()

    def __richcmp__(self, other, op):
        cdef int cop = op
        if cop not in (2, 3):
            raise TypeError("unorderable types: {}, {}".format(type(self), type(other)))
        if not (isinstance(self, Iterable) and isinstance(other, Iterable)):
            return cop != 2
        if (len(self) != len(other)):
            return cop != 2

        for one, two in zip(self, other):
            if one != two:
                return cop != 2

        return cop == 2

    def __hash__(self):
        if not self.__hash:
            self.__hash = hash(tuple(self))
        return self.__hash

    def __contains__(self, item):
        if not self:
            return False
        cdef string citem = item.encode('UTF-8')
        cdef vector[string] vec = deref(
            self._cpp_obj.get())
        return std_libcpp.find(vec.begin(), vec.end(), citem) != vec.end()

    def __iter__(self):
        if not self:
            raise StopIteration
        cdef string citem
        for citem in deref(self._cpp_obj):
            yield bytes(citem).decode('UTF-8')

    def __repr__(self):
        if not self:
            return 'i[]'
        return f'i[{", ".join(map(repr, self))}]'

    def __reversed__(self):
        if not self:
            raise StopIteration
        cdef string citem
        cdef vector[string] vec = deref(
            self._cpp_obj.get())
        cdef vector[string].reverse_iterator loc = vec.rbegin()
        while loc != vec.rend():
            citem = deref(loc)
            yield bytes(citem).decode('UTF-8')
            inc(loc)

    def index(self, item):
        if not self:
            raise ValueError(f'{item} is not in list')
        cdef string citem = item.encode('UTF-8')
        cdef vector[string] vec = deref(self._cpp_obj.get())
        cdef vector[string].iterator loc = std_libcpp.find(vec.begin(), vec.end(), citem)
        if loc != vec.end():
            return <int64_t> std_libcpp.distance(vec.begin(), loc)
        raise ValueError(f'{item} is not in list')

    def count(self, item):
        if not self:
            return 0
        cdef string citem = item.encode('UTF-8')
        cdef vector[string] vec = deref(self._cpp_obj.get())
        return <int64_t> std_libcpp.count(vec.begin(), vec.end(), citem)


Sequence.register(List__string)

cdef class Map__i16_string:
    def __init__(self, items=None):
        if isinstance(items, Map__i16_string):
            self._cpp_obj = (<Map__i16_string> items)._cpp_obj
        else:
            self._cpp_obj = move(Map__i16_string._make_instance(items))

    @staticmethod
    cdef create(shared_ptr[cmap[int16_t,string]] c_items):
        inst = <Map__i16_string>Map__i16_string.__new__(Map__i16_string)
        inst._cpp_obj = c_items
        return inst

    @staticmethod
    cdef unique_ptr[cmap[int16_t,string]] _make_instance(object items) except *:
        cdef unique_ptr[cmap[int16_t,string]] c_inst = make_unique[cmap[int16_t,string]]()
        if items is not None:
            for key, item in items.items():
                if not isinstance(key, int):
                    raise TypeError(f"{key!r} is not of type int")
                <int16_t> key
                if not isinstance(item, str):
                    raise TypeError(f"{item!r} is not of type str")

                deref(c_inst).insert(cpair[int16_t,string](key,item.encode('UTF-8')))
        return move_unique(c_inst)

    def __getitem__(self, key):
        if not self:
            raise KeyError(f'{key}')
        cdef int16_t ckey = key
        cdef cmap[int16_t,string].iterator iter = deref(
            self._cpp_obj).find(ckey)
        if iter == deref(self._cpp_obj).end():
            raise KeyError(f'{key}')
        cdef string citem = deref(iter).second
        return bytes(citem).decode('UTF-8')

    def __len__(self):
        return deref(self._cpp_obj).size()

    def __iter__(self):
        if not self:
            raise StopIteration
        cdef int16_t citem
        for pair in deref(self._cpp_obj):
            citem = pair.first
            yield citem

    def __richcmp__(self, other, op):
        cdef int cop = op
        if cop not in (2, 3):
            raise TypeError("unorderable types: {}, {}".format(type(self), type(other)))
        if not (isinstance(self, Mapping) and isinstance(other, Mapping)):
            return cop != 2
        if (len(self) != len(other)):
            return cop != 2

        for key in self:
            if key not in other:
                return cop != 2
            if other[key] != self[key]:
                return cop != 2

        return cop == 2

    def __hash__(self):
        if not self.__hash:
            self.__hash = hash(tuple(self.items()))
        return self.__hash

    def __repr__(self):
        if not self:
            return 'i{}'
        return f'i{{{", ".join(map(lambda i: f"{repr(i[0])}: {repr(i[1])}", self.items()))}}}'



    def __contains__(self, key):
        cdef int16_t ckey = key
        return deref(self._cpp_obj).count(ckey) > 0

    def get(self, key, default=None):
        if not self:
            return default
        cdef int16_t ckey = key
        cdef cmap[int16_t,string].iterator iter = \
            deref(self._cpp_obj).find(ckey)
        if iter == deref(self._cpp_obj).end():
            return default
        cdef string citem = deref(iter).second
        return bytes(citem).decode('UTF-8')

    def keys(self):
        return self.__iter__()

    def values(self):
        if not self:
            raise StopIteration
        cdef string citem
        for pair in deref(self._cpp_obj):
            citem = pair.second
            yield bytes(citem).decode('UTF-8')

    def items(self):
        if not self:
            raise StopIteration
        cdef int16_t ckey
        cdef string citem
        for pair in deref(self._cpp_obj):
            ckey = pair.first
            citem = pair.second

            yield (ckey, bytes(citem).decode('UTF-8'))



Mapping.register(Map__i16_string)

containerTypedef = Map__i16_string