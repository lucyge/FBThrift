#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from thrift.py3.server cimport ServiceInterface


cdef class RaiserInterface(ServiceInterface):
    cdef public bint _pass_context_doBland
    cdef public bint _pass_context_doRaise
    cdef public bint _pass_context_get200
    cdef public bint _pass_context_get500
    pass

