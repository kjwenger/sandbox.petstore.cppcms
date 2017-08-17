cmake_minimum_required(VERSION 2.6)
project(sandbox-cppcms)
if (NOT DEFINED CMAKE_PREFIX_PATH)
    set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/usr)
endif (NOT DEFINED CMAKE_PREFIX_PATH)
file(GLOB INCLUDE
        include/*.hpp
)
file(GLOB SRC
        src/*.cpp
)
add_executable(sandbox-cppcms
        ${INCLUDE}
        ${SRC}
)
include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_PREFIX_PATH}/local/include
        ${CMAKE_PREFIX_PATH}/include
        /usr/local/include
        /usr/include
)
target_link_libraries(sandbox-cppcms
        ${CMAKE_PREFIX_PATH}/lib/libcppcms.so
        ${CMAKE_PREFIX_PATH}/lib/libbooster.so
        pcre
)
