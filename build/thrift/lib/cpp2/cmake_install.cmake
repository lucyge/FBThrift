# Install script for directory: /home/hemant/fbthrift/thrift/lib/cpp2

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/hemant/fbthrift/build/lib/libthriftfrozen2.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/hemant/fbthrift/build/lib/libthriftprotocol.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include//home/hemant/fbthrift/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/gen-cpp2" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include//home/hemant/fbthrift/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/gen-cpp2" FILES_MATCHING REGEX "/[^/]*\\.tcc$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/hemant/fbthrift/build/lib/libthriftcpp2.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/async" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/async" FILES_MATCHING REGEX "/[^/]*\\.tcc$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/frozen" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/frozen" FILES_MATCHING REGEX "/[^/]*\\.tcc$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/gen-cpp2" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/gen-cpp2" FILES_MATCHING REGEX "/[^/]*\\.tcc$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/protocol" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/protocol" FILES_MATCHING REGEX "/[^/]*\\.tcc$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/security" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/security" FILES_MATCHING REGEX "/[^/]*\\.tcc$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/server" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/server" FILES_MATCHING REGEX "/[^/]*\\.tcc$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/transport" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/transport" FILES_MATCHING REGEX "/[^/]*\\.tcc$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/util" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/thrift/lib/cpp2" TYPE DIRECTORY FILES "/home/hemant/fbthrift/thrift/lib/cpp2/util" FILES_MATCHING REGEX "/[^/]*\\.tcc$")
endif()

