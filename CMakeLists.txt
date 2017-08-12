cmake_minimum_required(VERSION 2.6)
project(sandbox-cppcms)
if (NOT DEFINED CMAKE_PREFIX_PATH)
    set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/usr)
endif (NOT DEFINED CMAKE_PREFIX_PATH)
file(GLOB SRC
        src/*.cpp
        src/rest/*.cpp
)
add_executable(sandbox-cppcms ${SRC})
include_directories(
        ${CMAKE_PREFIX_PATH}/include
        /usr/local/include
        /usr/include/jsoncpp
        /usr/include
        ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(sandbox-cppcms
        ${CMAKE_PREFIX_PATH}/lib/libcppcms.so
        ${CMAKE_PREFIX_PATH}/lib/libbooster.so
        pcre
)

add_subdirectory(scripts/thirdparty/googletest)
enable_testing()
file(GLOB TEST
        test/src/*.cpp
)
add_executable(sandbox-cppcms-test ${TEST})
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(sandbox-cppcms-test
        ${CMAKE_PREFIX_PATH}/lib/libcurlpp.a
        ${CMAKE_PREFIX_PATH}/lib/libcurl.a
        ${CMAKE_PREFIX_PATH}/lib/libz.a
        jsoncpp
        crypto
        ssl
        gtest
        gtest_main)
add_test(
        NAME sandbox-cppcms-test
        COMMAND sandbox-cppcms-test
)