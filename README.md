# sandbox.petstore.cppcms

Sandbox for C++/CppCMS/Boost PetStore

- Motivation: which technology is best ... is C++ old news?
    - A Bird's-Eye View: PetStore RESTful Web API implemented using ...
        - Reference API: [Swagger PetStore](http://petstore.swagger.io/)
        - Definition: [JSON](https://editor.swagger.io/) downloaded to [sandbox.petstore](https://github.com/kjwenger/sandbox.petstore/README.md)

## Part 1: [Setting up C++ Development](doc/part/01.md)

## Part 2: [Setting up CppCMS Framework](doc/part/02.md)

## Part 3: Setting up Cross-Compilation

- Make on Build System, Run on Target System:
    - Compiler Suite:
        - Itself compiled for Build Systems
        - Compiles Others for Target System
        - SDK/Libraries for Target System
    - Toolchains/SDKs:
        - From Package Management
        - From Downloads/Manual Installation
    - Target System of Choice for Talk: BeagleBoneBlack
        - Target Architecture: ARM HF (Hardware Floating Point)
        - Target OS: Linux
- Package Management:
    - Add Target Architecture: `dpkg --add-architecture armhf && apt update`
    - Install Compiler for Architecture: `apt install crossbuild-essential-armhf -y`
    - Install Dependencies for Architecture: `apt install libpcre3-dev:armhf zlib1g-dev:armhf libgcrypt11-dev:armhf libicu-dev:armhf -y`
- Project Management:
    - Provide Toolchain File: [`arm-linux-gnueabihf.cmake`](./toolchains/arm-linux-gnueabihf.cmake)
        ```cmake
        set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/usr/arm-linux-gnueabihf)        
        # which C and C++ compiler to use
        set(CMAKE_C_COMPILER  /usr/bin/arm-linux-gnueabihf-gcc)
        set(CMAKE_CXX_COMPILER /usr/bin/arm-linux-gnueabihf-g++)
        ```
        - In Themselves CMakeLists Files: mostly setting paths and executables names
        - Often Available On-line
    - Change: location of CppCMS, Booster and dependency headers
        ```cmake
        include_directories(
            ${CMAKE_PREFIX_PATH}/local/include
            ${CMAKE_PREFIX_PATH}/include
        )
        ```
    - Change: location of CppCMS, Booster and dependency libraries
        ```cmake
        target_link_libraries(sandbox-cppcms
            ${CMAKE_PREFIX_PATH}/lib/libcppcms.so
            ${CMAKE_PREFIX_PATH}/lib/libbooster.so
        )
        ```
- Development:
    - Create: destination directory `mkdir -p ./build-arm-linux-gnueabihf && cd ./build-arm-linux-gnueabihf`
    - Configure: `cmake -DCMAKE_TOOLCHAIN_FILE="${PROJECT_DIR}/toolchains/arm-linux-gnueabihf.cmake" -DCMAKE_INSTALL_PREFIX="${USR_DIR}/arm-linux-gnueabihf" ..`
    - Build: `make`
    - Deploy: `scp ./sandbox-cppcms <user>@<target_host>:/usr/local/bin`
