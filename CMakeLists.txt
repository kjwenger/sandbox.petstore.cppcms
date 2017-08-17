cmake_minimum_required(VERSION 2.6)
project(sandbox-cppcms)
#set(CMAKE_VERBOSE_MAKEFILE true)
if (NOT DEFINED CMAKE_PREFIX_PATH)
    set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/usr)
endif (NOT DEFINED CMAKE_PREFIX_PATH)
#include(CheckCXXCompilerFlag)
#check_cxx_compiler_flag(-std=c++17 HAVE_FLAG_STD_CXX17)
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS ON)
file(GLOB INCLUDE
        include/*.hpp
        include/model/*.hpp
        include/persistence/*.hpp
        include/rest/*.hpp
)
file(GLOB SRC
        src/*.cpp
        src/rest/*.cpp
)
file(GLOB SRC_SHARED
        src/model/*.cpp
        src/persistence/*.cpp
)
add_executable(sandbox-cppcms
        ${INCLUDE}
        ${SRC}
        ${SRC_SHARED}
)
include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_PREFIX_PATH}/local/include
        ${CMAKE_PREFIX_PATH}/include
        /usr/local/include
        /usr/include/jsoncpp
        /usr/include
)
find_package(Threads)
target_link_libraries(sandbox-cppcms
        ${CMAKE_PREFIX_PATH}/lib/libcppcms.so
        ${CMAKE_PREFIX_PATH}/lib/libbooster.so
        ${CMAKE_PREFIX_PATH}/lib/libhiberlite.a
        ${CMAKE_PREFIX_PATH}/lib/libz.a
        ${CMAKE_PREFIX_PATH}/lib/libpcre.a
        ${CMAKE_THREAD_LIBS_INIT}
        dl
)

add_subdirectory(scripts/thirdparty/googletest)
enable_testing()
file(GLOB TEST_INCLUDE
        test/include/rest/*.hpp
)
file(GLOB TEST_SRC
        test/src/model/*.cpp
        test/src/persistence/*.cpp
        test/src/rest/*.cpp
)
add_executable(sandbox-cppcms-test
        ${TEST_INCLUDE}
        ${SRC_SHARED}
        ${TEST_SRC}
)
target_include_directories(sandbox-cppcms-test PUBLIC
        ${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}
        test/include
)
target_link_libraries(sandbox-cppcms-test
        ${CMAKE_PREFIX_PATH}/lib/libhiberlite.a
        ${CMAKE_PREFIX_PATH}/lib/libcurlpp.a
        ${CMAKE_PREFIX_PATH}/lib/libcurl.a
        ${CMAKE_PREFIX_PATH}/lib/libz.a
        gtest_main
        gtest
        jsoncpp
        crypto
        ssl
        dl)
add_test(
        NAME sandbox-cppcms-test
        COMMAND sandbox-cppcms-test
)
