#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
from libcpp.memory cimport shared_ptr, make_shared, unique_ptr, make_unique
from libcpp.string cimport string
from libcpp cimport bool as cbool
from cpython cimport bool as pbool
from libc.stdint cimport int8_t, int16_t, int32_t, int64_t
from libcpp.vector cimport vector as vector
from libcpp.set cimport set as cset
from libcpp.map cimport map as cmap
from cython.operator cimport dereference as deref, typeid
from cpython.ref cimport PyObject
from thrift.py3.client cimport cRequestChannel_ptr, makeClientWrapper
from thrift.py3.exceptions cimport try_make_shared_exception, raise_py_exception
from folly cimport cFollyTry, cFollyUnit, c_unit
from libcpp.typeinfo cimport type_info
import thrift.py3.types
cimport thrift.py3.types
import thrift.py3.client
cimport thrift.py3.client
from folly.futures cimport bridgeFutureWith
from folly.executor cimport get_executor
cimport cython

import asyncio
import sys

cimport module.types as _module_types
import module.types as _module_types

from module.clients_wrapper cimport cNestedContainersAsyncClient, cNestedContainersClientWrapper


cdef void NestedContainers_mapList_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* future
):
    cdef object pyfuture = <object> future
    if result.hasException():
        try:
            raise_py_exception(result.exception())
        except Exception as ex:
            pyfuture.set_exception(ex)
    else:
        try:
            pyfuture.set_result(None)
        except Exception as ex:
            pyfuture.set_exception(ex)

cdef void NestedContainers_mapSet_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* future
):
    cdef object pyfuture = <object> future
    if result.hasException():
        try:
            raise_py_exception(result.exception())
        except Exception as ex:
            pyfuture.set_exception(ex)
    else:
        try:
            pyfuture.set_result(None)
        except Exception as ex:
            pyfuture.set_exception(ex)

cdef void NestedContainers_listMap_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* future
):
    cdef object pyfuture = <object> future
    if result.hasException():
        try:
            raise_py_exception(result.exception())
        except Exception as ex:
            pyfuture.set_exception(ex)
    else:
        try:
            pyfuture.set_result(None)
        except Exception as ex:
            pyfuture.set_exception(ex)

cdef void NestedContainers_listSet_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* future
):
    cdef object pyfuture = <object> future
    if result.hasException():
        try:
            raise_py_exception(result.exception())
        except Exception as ex:
            pyfuture.set_exception(ex)
    else:
        try:
            pyfuture.set_result(None)
        except Exception as ex:
            pyfuture.set_exception(ex)

cdef void NestedContainers_turtles_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* future
):
    cdef object pyfuture = <object> future
    if result.hasException():
        try:
            raise_py_exception(result.exception())
        except Exception as ex:
            pyfuture.set_exception(ex)
    else:
        try:
            pyfuture.set_result(None)
        except Exception as ex:
            pyfuture.set_exception(ex)


cdef class NestedContainers(thrift.py3.client.Client):

    def __cinit__(NestedContainers self):
        loop = asyncio.get_event_loop()
        self._deferred_headers = {}
        self._connect_future = loop.create_future()
        self._executor = get_executor()

    cdef const type_info* _typeid(NestedContainers self):
        return &typeid(cNestedContainersAsyncClient)

    @staticmethod
    cdef _module_NestedContainers_set_client(NestedContainers inst, shared_ptr[cNestedContainersClientWrapper] c_obj):
        """So the class hierarchy talks to the correct pointer type"""
        inst._module_NestedContainers_client = c_obj

    cdef _module_NestedContainers_reset_client(NestedContainers self):
        """So the class hierarchy resets the shared pointer up the chain"""
        self._module_NestedContainers_client.reset()

    def __dealloc__(NestedContainers self):
        if self._cRequestChannel or self._module_NestedContainers_client:
            print('client was not cleaned up, use the context manager', file=sys.stderr)

    async def __aenter__(NestedContainers self):
        await self._connect_future
        if self._cRequestChannel:
            NestedContainers._module_NestedContainers_set_client(
                self,
                makeClientWrapper[cNestedContainersAsyncClient, cNestedContainersClientWrapper](
                    self._cRequestChannel
                ),
            )
            self._cRequestChannel.reset()
        else:
            raise asyncio.InvalidStateError('Client context has been used already')
        for key, value in self._deferred_headers.items():
            self.set_persistent_header(key, value)
        self._deferred_headers = None
        return self

    async def __aexit__(NestedContainers self, *exc):
        self._check_connect_future()
        loop = asyncio.get_event_loop()
        future = loop.create_future()
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._module_NestedContainers_client).disconnect(),
            closed_NestedContainers_py3_client_callback,
            <PyObject *>future
        )
        # To break any future usage of this client
        badfuture = loop.create_future()
        badfuture.set_exception(asyncio.InvalidStateError('Client Out of Context'))
        badfuture.exception()
        self._connect_future = badfuture
        await future
        self._module_NestedContainers_reset_client()

    def set_persistent_header(NestedContainers self, str key, str value):
        if not self._module_NestedContainers_client:
            self._deferred_headers[key] = value
            return

        cdef string ckey = <bytes> key.encode('utf-8')
        cdef string cvalue = <bytes> value.encode('utf-8')
        deref(self._module_NestedContainers_client).setPersistentHeader(ckey, cvalue)

    @cython.always_allow_keywords(True)
    async def mapList(
            NestedContainers self,
            foo not None
    ):
        if not isinstance(foo, _module_types.Map__i32_List__i32):
            foo = _module_types.Map__i32_List__i32(foo)
        self._check_connect_future()
        __loop = asyncio.get_event_loop()
        __future = __loop.create_future()
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._module_NestedContainers_client).mapList(
                cmap[int32_t,vector[int32_t]](deref(_module_types.Map__i32_List__i32(foo)._cpp_obj.get())),
            ),
            NestedContainers_mapList_callback,
            <PyObject *> __future
        )
        return await __future

    @cython.always_allow_keywords(True)
    async def mapSet(
            NestedContainers self,
            foo not None
    ):
        if not isinstance(foo, _module_types.Map__i32_Set__i32):
            foo = _module_types.Map__i32_Set__i32(foo)
        self._check_connect_future()
        __loop = asyncio.get_event_loop()
        __future = __loop.create_future()
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._module_NestedContainers_client).mapSet(
                cmap[int32_t,cset[int32_t]](deref(_module_types.Map__i32_Set__i32(foo)._cpp_obj.get())),
            ),
            NestedContainers_mapSet_callback,
            <PyObject *> __future
        )
        return await __future

    @cython.always_allow_keywords(True)
    async def listMap(
            NestedContainers self,
            foo not None
    ):
        if not isinstance(foo, _module_types.List__Map__i32_i32):
            foo = _module_types.List__Map__i32_i32(foo)
        self._check_connect_future()
        __loop = asyncio.get_event_loop()
        __future = __loop.create_future()
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._module_NestedContainers_client).listMap(
                vector[cmap[int32_t,int32_t]](deref(_module_types.List__Map__i32_i32(foo)._cpp_obj.get())),
            ),
            NestedContainers_listMap_callback,
            <PyObject *> __future
        )
        return await __future

    @cython.always_allow_keywords(True)
    async def listSet(
            NestedContainers self,
            foo not None
    ):
        if not isinstance(foo, _module_types.List__Set__i32):
            foo = _module_types.List__Set__i32(foo)
        self._check_connect_future()
        __loop = asyncio.get_event_loop()
        __future = __loop.create_future()
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._module_NestedContainers_client).listSet(
                vector[cset[int32_t]](deref(_module_types.List__Set__i32(foo)._cpp_obj.get())),
            ),
            NestedContainers_listSet_callback,
            <PyObject *> __future
        )
        return await __future

    @cython.always_allow_keywords(True)
    async def turtles(
            NestedContainers self,
            foo not None
    ):
        if not isinstance(foo, _module_types.List__List__Map__i32_Map__i32_Set__i32):
            foo = _module_types.List__List__Map__i32_Map__i32_Set__i32(foo)
        self._check_connect_future()
        __loop = asyncio.get_event_loop()
        __future = __loop.create_future()
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._module_NestedContainers_client).turtles(
                vector[vector[cmap[int32_t,cmap[int32_t,cset[int32_t]]]]](deref(_module_types.List__List__Map__i32_Map__i32_Set__i32(foo)._cpp_obj.get())),
            ),
            NestedContainers_turtles_callback,
            <PyObject *> __future
        )
        return await __future



cdef void closed_NestedContainers_py3_client_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* fut,
):
    cdef object pyfuture = <object> fut
    pyfuture.set_result(None)
