# toolchain-clang.cmake - Clang CMake toolchain file
#
# Copyright (C) 2015, ARM Limited, All Rights Reserved
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may
# not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# This file is part of the Optimized Routines project

cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set(CMAKE_SYSTEM_NAME Linux)

#set(triple aarch64-linux-gnu)
# The gcc toolchain root folder. This could be your linaro-gcc folder, or /usr/.
set(gcc-root /usr)

# This clang needs to be recent!
set(CMAKE_C_COMPILER /usr/bin/clang)
#set(CMAKE_C_COMPILER_TARGET ${triple})
set(CMAKE_C_COMPILER_EXTERNAL_TOOLCHAIN ${gcc-root})

set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_CXX_COMPILER_TARGET ${triple})
set(CMAKE_CXX_COMPILER_EXTERNAL_TOOLCHAIN ${gcc-root})

if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.5)
    message(STATUS "Warning: clang version < 3.5.0 is known to be problematic")
endif()

#set(CMAKE_FIND_ROOT_PATH ${gcc-root}/aarch64-linux-gnu)
#set(CMAKE_SYSROOT ${gcc-root}/aarch64-linux-gnu/libc)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# This is a workaround since the LLVM optimiser breaks the code we use to raise
# exceptions. This forces exceptions to be raised by invoking the C99 function
# feraiseexcept with appropriate arguments.
# WARNING! Setting this with other compilers may cause exceptions to be raised
# multiple times or result in other unwanted behaviour!
add_definitions(-DCLANG_EXCEPTIONS)

# <a href="https://raw.githubusercontent.com/ARM-software/optimized-routines/master/toolchain-clang.cmake">toolchain-clang.cmake</a>