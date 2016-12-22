# Install script for directory: /home/osboxes/Documents/code/CppUTest/src/CppUTestExt

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
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
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
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/CppUTestExt" TYPE FILE FILES
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/CodeMemoryReportFormatter.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/IEEE754ExceptionsPlugin.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/MemoryReportAllocator.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/MockExpectedCall.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/MockCheckedExpectedCall.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/MockExpectedCallsList.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/MockSupportPlugin.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/MemoryReportFormatter.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/MockFailure.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/MockSupport.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/MockSupport_c.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/GMock.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/GTest.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/MemoryReporterPlugin.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/OrderedTest.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/GTestConvertor.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/MockActualCall.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/MockCheckedActualCall.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/MockNamedValue.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTestExt/MockSupport.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/osboxes/Documents/code/CppUTest/src/CppUTestExt/libCppUTestExt.a")
endif()

