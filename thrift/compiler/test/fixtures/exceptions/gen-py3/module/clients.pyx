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

from module.clients_wrapper cimport cRaiserAsyncClient, cRaiserClientWrapper


cdef void Raiser_doBland_callback(
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

cdef void Raiser_doRaise_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* future
):
    cdef object pyfuture = <object> future
    if result.hasException[_module_types.cBanal]():
        pyfuture.set_exception(_module_types.Banal.create(try_make_shared_exception[_module_types.cBanal](result.exception())))
    elif result.hasException[_module_types.cFiery]():
        pyfuture.set_exception(_module_types.Fiery.create(try_make_shared_exception[_module_types.cFiery](result.exception())))
    elif result.hasException():
        try:
            raise_py_exception(result.exception())
        except Exception as ex:
            pyfuture.set_exception(ex)
    else:
        try:
            pyfuture.set_result(None)
        except Exception as ex:
            pyfuture.set_exception(ex)

cdef void Raiser_get200_callback(
    cFollyTry[string]&& result,
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
            pyfuture.set_result(result.value().decode('UTF-8'))
        except Exception as ex:
            pyfuture.set_exception(ex)

cdef void Raiser_get500_callback(
    cFollyTry[string]&& result,
    PyObject* future
):
    cdef object pyfuture = <object> future
    if result.hasException[_module_types.cFiery]():
        pyfuture.set_exception(_module_types.Fiery.create(try_make_shared_exception[_module_types.cFiery](result.exception())))
    elif result.hasException[_module_types.cBanal]():
        pyfuture.set_exception(_module_types.Banal.create(try_make_shared_exception[_module_types.cBanal](result.exception())))
    elif result.hasException():
        try:
            raise_py_exception(result.exception())
        except Exception as ex:
            pyfuture.set_exception(ex)
    else:
        try:
            pyfuture.set_result(result.value().decode('UTF-8'))
        except Exception as ex:
            pyfuture.set_exception(ex)


cdef class Raiser(thrift.py3.client.Client):

    def __cinit__(Raiser self):
        loop = asyncio.get_event_loop()
        self._deferred_headers = {}
        self._connect_future = loop.create_future()
        self._executor = get_executor()

    cdef const type_info* _typeid(Raiser self):
        return &typeid(cRaiserAsyncClient)

    @staticmethod
    cdef _module_Raiser_set_client(Raiser inst, shared_ptr[cRaiserClientWrapper] c_obj):
        """So the class hierarchy talks to the correct pointer type"""
        inst._module_Raiser_client = c_obj

    cdef _module_Raiser_reset_client(Raiser self):
        """So the class hierarchy resets the shared pointer up the chain"""
        self._module_Raiser_client.reset()

    def __dealloc__(Raiser self):
        if self._cRequestChannel or self._module_Raiser_client:
            print('client was not cleaned up, use the context manager', file=sys.stderr)

    async def __aenter__(Raiser self):
        await self._connect_future
        if self._cRequestChannel:
            Raiser._module_Raiser_set_client(
                self,
                makeClientWrapper[cRaiserAsyncClient, cRaiserClientWrapper](
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

    async def __aexit__(Raiser self, *exc):
        self._check_connect_future()
        loop = asyncio.get_event_loop()
        future = loop.create_future()
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._module_Raiser_client).disconnect(),
            closed_Raiser_py3_client_callback,
            <PyObject *>future
        )
        # To break any future usage of this client
        badfuture = loop.create_future()
        badfuture.set_exception(asyncio.InvalidStateError('Client Out of Context'))
        badfuture.exception()
        self._connect_future = badfuture
        await future
        self._module_Raiser_reset_client()

    def set_persistent_header(Raiser self, str key, str value):
        if not self._module_Raiser_client:
            self._deferred_headers[key] = value
            return

        cdef string ckey = <bytes> key.encode('utf-8')
        cdef string cvalue = <bytes> value.encode('utf-8')
        deref(self._module_Raiser_client).setPersistentHeader(ckey, cvalue)

    @cython.always_allow_keywords(True)
    async def doBland(
            Raiser self
    ):
        self._check_connect_future()
        __loop = asyncio.get_event_loop()
        __future = __loop.create_future()
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._module_Raiser_client).doBland(
            ),
            Raiser_doBland_callback,
            <PyObject *> __future
        )
        return await __future

    @cython.always_allow_keywords(True)
    async def doRaise(
            Raiser self
    ):
        self._check_connect_future()
        __loop = asyncio.get_event_loop()
        __future = __loop.create_future()
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._module_Raiser_client).doRaise(
            ),
            Raiser_doRaise_callback,
            <PyObject *> __future
        )
        return await __future

    @cython.always_allow_keywords(True)
    async def get200(
            Raiser self
    ):
        self._check_connect_future()
        __loop = asyncio.get_event_loop()
        __future = __loop.create_future()
        bridgeFutureWith[string](
            self._executor,
            deref(self._module_Raiser_client).get200(
            ),
            Raiser_get200_callback,
            <PyObject *> __future
        )
        return await __future

    @cython.always_allow_keywords(True)
    async def get500(
            Raiser self
    ):
        self._check_connect_future()
        __loop = asyncio.get_event_loop()
        __future = __loop.create_future()
        bridgeFutureWith[string](
            self._executor,
            deref(self._module_Raiser_client).get500(
            ),
            Raiser_get500_callback,
            <PyObject *> __future
        )
        return await __future



cdef void closed_Raiser_py3_client_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* fut,
):
    cdef object pyfuture = <object> fut
    pyfuture.set_result(None)