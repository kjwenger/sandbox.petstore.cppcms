cmake_minimum_required(VERSION 2.6)
project(sandbox-cppcms)
if (NOT DEFINED CMAKE_PREFIX_PATH)
    set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/usr)
endif (NOT DEFINED CMAKE_PREFIX_PATH)
file(GLOB INCLUDE
        ../include/*.hpp
        ../include/model/*.hpp
        ../include/persistence/*.hpp
        ../include/rest/*.hpp
)
file(GLOB SRC_SHARED
        ../src/utility.cpp
        ../src/model/*.cpp
        ../src/persistence/*.cpp
)

add_subdirectory(thirdparty/curl)
add_subdirectory(thirdparty/curlpp)
add_subdirectory(thirdparty/jsoncpp)
add_subdirectory(thirdparty/googletest)
enable_testing()
file(GLOB TEST_INCLUDE
        include/rest/*.hpp
)
file(GLOB TEST_SRC
        src/model/*.cpp
        src/persistence/*.cpp
        src/rest/*.cpp
)
add_executable(sandbox-cppcms-test
        ${TEST_INCLUDE}
        ${SRC_SHARED}
        ${TEST_SRC}
)
target_include_directories(sandbox-cppcms-test PUBLIC
        ${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}
        include
)
target_link_libraries(sandbox-cppcms-test
        ${CMAKE_PREFIX_PATH}/lib/libcppcms.so
        ${CMAKE_PREFIX_PATH}/lib/libbooster.so
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
