cmake_minimum_required(VERSION 2.6)
project(sandbox-cppcms)
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
        ${CMAKE_SOURCE_DIR}/usr/local/include
        ${CMAKE_SOURCE_DIR}/usr/include
        /usr/local/include
        /usr/include
)
target_link_libraries(sandbox-cppcms
        ${CMAKE_SOURCE_DIR}/usr/lib/libcppcms.so
        ${CMAKE_SOURCE_DIR}/usr/lib/libbooster.so
        pcre
)
