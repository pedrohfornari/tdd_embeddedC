# Install script for directory: /home/osboxes/Documents/code/CppUTest/src/CppUTest

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/CppUTest" TYPE FILE FILES
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/CommandLineArguments.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/PlatformSpecificFunctions.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/TestMemoryAllocator.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/CommandLineTestRunner.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/PlatformSpecificFunctions_c.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/TestOutput.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/CppUTestConfig.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/SimpleString.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/TestPlugin.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/JUnitTestOutput.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/TeamCityTestOutput.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/StandardCLibrary.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/TestRegistry.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/MemoryLeakDetector.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/TestFailure.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/TestResult.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/MemoryLeakDetectorMallocMacros.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/TestFilter.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/TestTestingFixture.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/MemoryLeakDetectorNewMacros.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/TestHarness.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/Utest.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/MemoryLeakWarningPlugin.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/TestHarness_c.h"
    "/home/osboxes/Documents/code/CppUTest/include/CppUTest/UtestMacros.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/osboxes/Documents/code/CppUTest/src/CppUTest/libCppUTest.a")
endif()

