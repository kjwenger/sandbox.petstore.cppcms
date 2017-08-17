# sandbox.cppcms

Sandbox for C++/CppCMS/Boost PetStore

- Motivation: which technology is best ... is C++ old news?
    - A Bird's-Eye View: PetStore RESTful Web API implemented using ...
        - Reference API: [Swagger PetStore](http://petstore.swagger.io/)
        - Definition: [JSON](https://editor.swagger.io/) downloaded to [sandbox.petstore](https://github.com/kjwenger/sandbox.petstore/README.md)
    - [GoLang](https://golang.org/)/[Revel](https://revel.github.io/): goes from _Embedded_ to _Cloud_, replacing C++?
        - Code (auto-generated): [sandbox.petstore.golang](https://github.com/kjwenger/sandbox.petstore.golang/README.md)
    - [Elixir](https://elixir-lang.org/)/[Phoenix](http://phoenixframework.org/): *the* Formula from _Embedded_ bis _Cloud_? Ruby on Rails w/o Ruby?
        - Code (auto-generated): [sandbox.petstore.erlang](https://github.com/kjwenger/sandbox.petstore.erlang/README.md)
    - [C++](http://www.stroustrup.com/4th.html)/[CppCMS](http://cppcms.com/wikipp/en/page/main): _Embedded_, _Cloud_, anything! ... but at what price?
        - Code (auto-generated): [sandbox.petstore.cppcms](https://github.com/kjwenger/sandbox.petstore.cppcms/README.md)
    - [Kotlin](https://kotlinlang.org/)/[Spring](https://spring.io/): _Embedded_? Certainly _Cloud_! Simpler than [Java Enterprise Edition](http://www.oracle.com/technetwork/java/javaee/overview/index.html)?
        - Code (by Bernhard): [spring-kotlin-swagger-petstore](https://github.com/hubuu/spring-kotlin-swagger-petstore)
    - [Node.js](https://nodejs.org/en/): _Cloud_, yes! _Embedded_, maybe?
        - Code (auto-generated): [sandbox.petstore.nodejs](https://github.com/kjwenger/sandbox.petstore.nodejs/README.md)
    - Add Language/Framework Here: let's do it!
        - Code (and share it): [github.com](https://github.com)

## Part 1: Setting up C++ Development

- Language: strange choice ... wrong choice?
    - The Good
        - Fast: ... supposedly fastest [object-oriented](https://en.wikipedia.org/wiki/Object-oriented_programming) language
        - Standards: ... like [Boost Libraries](http://www.boost.org/)
        - Libraries: ... like [Boost Libraries](http://www.boost.org/)
        - Tested: ... not only by time and [Google Test](https://github.com/google/googletest/blob/master/README.md10)
        - Small: ... [strip it down](http://ptspts.blogspot.de/2013/12/how-to-make-smaller-c-and-c-binaries.html) to kilobytes
        - Stable: ... it can be
        - Versatile: ... some restrictions may apply
            - On almost every OS
        - Universal: ... runs basically everywhere
            -  Cross-Platform
        - Modern: ... amazingly, yes
            - Automatic Types: `auto i = 1, n = 10; auto text = "ok";`
            - Generic Programming: `template <typename T> int toInt(const T & from);`
            - Functional Programming: `std::function` and lambdas `[&](int i){ return i * i; }`
            - Monadic Programming: `std::optional`
    - The Bad
        - (Too) Many:
            - Compilers:
                - [LLVM compiler infrastructure = clang](https://clang.llvm.org/)
                - [GCC, the GNU Compiler Collection = gcc, g++](https://gcc.gnu.org/)
            - Builders:
                - [CMake](https://cmake.org/)
                - [Autotools](https://www.gnu.org/software/automake/manual/automake.html)
            - Standards:
                - [POSIX](http://standards.ieee.org/develop/wg/POSIX.html)
                - [C++17,C++1z](https://en.wikipedia.org/wiki/C%2B%2B17)
                - [C++14](https://en.wikipedia.org/wiki/C%2B%2B14), ...
            - [Libraries](http://en.cppreference.com/w/cpp/links/libs):
                - [Boost](http://www.boost.org/)
                - [Qt](https://www.qt.io/)
        - Not in My Browser!
    - The Ugly
        - From C
- Package Management: from OS - `apt`
    - The Good
        - Built into OS ... or saddled onto
        - Support of multiple Architectures
        - [Debian](https://www.debian.org/) rules
    - The Bad
        - Frequent Clashes
        - Repository Hell: [FrankenDebian](https://wiki.debian.org/DontBreakDebian)
        - [Ubuntu](https://www.ubuntu.com/) sucks at Cross-Compiling
    - The How
        - Install Prerequisites:
            - Network Tools: `apt install curl, wget`
            - Build Tools: `apt install build-essential, cmake, gcc, g++`
            - Libraries: `apt install libssl-dev, ...`
            - Version Control: `apt install git, subversion`
- Project Management: CMake - because it works!
    - The Good
        - Supported:
            - IDE [CLion](https://www.jetbrains.com/clion/specials/clion/clion.html?gclid=EAIaIQobChMI95v5srXc1QIVRjwbCh0FdwfBEAAYASAAEgJ-CPD_BwE&gclsrc=aw.ds.ds&dclid=CJ2pu7S13NUCFcelUQod1n4G_Q)
            - Good Community
                - Blogs, Forums, StackOverflow
                - Many Add-ons
        - Accepted:
            - Used by [C++ Projects](https://en.wikipedia.org/wiki/CMake#Applications_that_use_CMake) World-Wide
        - Powerful:
            - Multi-Module/Target Projects
        - Structured:
            - Hierarchical
        - Simple: ... simpler than `make`, _Auto-tools_
            - Intuitive Build Script Language
    - The Bad
        - Learning Curve
        - Discrepancies in Package Management
    - The How
        - Maintain Build File
        - Configure
        - Make
- Development: ... show me some code!
    - Write: build file [`CMakeLists.txt`](./CMakeLists.txt)
        ```cmake
        cmake_minimum_required(VERSION 2.6)
        project(sandbox-cppcms)
        add_executable(sandbox-cppcms src/main.cpp)
        ```
    - Add: source file [`main.cpp`](./src/main.cpp)
        ```cpp
        int main(int argc, const char* argv[]) {
            return 0;
        }
        ```
    - Create: destination directory `mkdir -p ./build && cd ./build`
    - Configure: `cmake ..`
    - Build: `make`
    - Run: `./sandbox-cppcms`

## Part 2: Setting up CppCMS Framework

- Strange Name ... Weird Choice? not a Content Management System (CMS) ... never heard
    - The [Rationale](http://cppcms.com/wikipp/en/page/rationale)
    - The Good
        - Fast: ... [real fast](http://cppcms.com/wikipp/en/page/benchmarks_all)
        - Standards: ... can use [Boost](http://www.boost.org/)
        - Small: ... use Booster (a reduced Boost)
        - Stable: ... not seen it crash once
        - Intuitive: ... comparatively `dispatcher().map("PUT", "/todo/(\\d+)", &my_app::update_todo, this, 1);`
    - The Bad
        - Slow: ... to develop for
        - Limited Support
        - No Standard: ... in itself ... [Wt](https://www.webtoolkit.eu/wt), and others compete
    - The Ugly
        - Long Release Cycles:
- Building:
    - Get: `git clone https://github.com/artyom-beilis/cppcms.git && cd cppcms`
    - Prepare: `apt install libpcre3-dev zlib1g-dev libgcrypt11-dev libicu-dev`
    - Create: destination directory `mkdir -p ./build && cd ./build`
    - Configure: `cmake ..`
    - Build: `make`
- Development: ... show me more code!
    - Add REST API:
        - Declarations: header file [`rests.hpp`](./include/rests.hpp)
            ```cpp
            class rests : public cppcms::application {
            public:
                rests(cppcms::service& srv);
                virtual ~rests();
            
                void get_info();
            };    
            ```
        - Definitions: source file  [`rests.cpp`](./include/rests.cpp)
            ```cpp
            rests::rests(cppcms::service& srv) : cppcms::application(srv) {
                dispatcher().map("GET","", &rests::get_info, this);
            };
            
            void rests::get_info() {
                cppcms::json::value info;
                info["name"] = "sandbox-cppcms";
                info["version"] = "0.1.0";
            
                response().out() << info;
            }    
            ```
    - Modify: build file [`CMakeLists.txt`](./CMakeLists.txt)
        - Add: REST API headers and sources
            ```cmake
            file(GLOB INCLUDE include/*.hpp)
            file(GLOB SRC src/*.cpp)
            add_executable(sandbox-cppcms ${INCLUDE} ${SRC})
            include_directories(${CMAKE_SOURCE_DIR}/include)
            ```
        - Add: CppCMS, Booster and dependency headers
            ```cmake
            include_directories(
                    ${CMAKE_SOURCE_DIR}/usr/local/include
                    ${CMAKE_SOURCE_DIR}/usr/include
                    /usr/local/include
                    /usr/include
            )
            ```
        - Add: CppCMS, Booster and dependency libraries
            ```cmake
            target_link_libraries(sandbox-cppcms
                    ${CMAKE_SOURCE_DIR}/usr/lib/libcppcms.so
                    ${CMAKE_SOURCE_DIR}/usr/lib/libbooster.so
                    pcre
            )
            ```
    - Create: settings [`config.json`](./config.json)
        ```json
        {
          "service": {"api": "http", "port": 8910},
          "http": {"script_names": ["/"]}
        }
        ```
    - GoTo: destination directory `mkdir -p ./build && cd ./build`
    - Configure: `cmake ..`
    - Build: `make`
    - Run: `./sandbox-cppcms -c ../config.json`
- Future Improvements:
    - Add CppCMS as Git Sub-module: `./thridparty/cppcms`
    - Add CppCMS to CMake Build File as Sub-directory: `add_subdirectory(thridparty/cppcms)`

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

## Part 4: Setting up Testing

- Test Driven Development
    - In C++ More .. Most Necessary
    - Good Available Test Frameworks
        - [Google Test](https://github.com/google/googletest/blob/master/README.md10)
        - Boost Test
        - CppUnit
    - IDE/CLion Support: at least for Google Test
- Package Management: ... possible but better building from source
    - Install Dependencies: `apt install gtest -y`
    - Install Helper Libraries: `apt install libcurl-dev -y`
- Building: ... not even that is really needed ... use _CMake_ sub-directory inclusion
    - Get: `git clone https://github.com/google/googletest.git && cd googletest`
    - Create: destination directory `mkdir -p ./build && cd ./build`
    - Configure: `cmake ..`
    - Build: `make`
- Project Management:
    - Modify: build file [`CMakeLists.txt`](./CMakeLists.txt)
        - Add Sub-Directory: `add_subdirectory(scripts/thirdparty/googletest)`
        - Enable Testing: `enable_testing()`
        - Add Test Source Files: `file(GLOB TEST test/src/*.cpp)`
        - Add Test Target (Binary): `add_executable(sandbox-cppcms-test ${TEST})`
        - Set Target Link Libraries: `target_link_libraries(sandbox-cppcms-test gtest gtest_main)`
        - Add Test: `add_test(NAME sandbox-cppcms-test COMMAND sandbox-cppcms-test)`
- Development: ... he tests me!
    - Add: test source file [`rest_test.cpp`](test/src/rest_test.cpp)
        ```cpp
        TEST_F(rest_test, rest_test_case)
        {
            curlpp::Cleanup cleanup;
            curlpp::Easy request;
            request.setOpt<curlpp::options::Url>("http://localhost:8910/rest");
            std::ostringstream os;
            curlpp::options::WriteStream ws(&os);
            request.setOpt(ws);
            request.perform();
        
            EXPECT_STREQ(R"({"name":"sandbox-cppcms","version":"0.1.0"})", os.str().c_str());
        }
        ```
    - GoTo: destination directory `mkdir -p ./build && cd ./build`
    - Configure: `cmake ..`
    - Build: `make`
    - Run: `./sandbox-cppcms -c ../config.json &`
    - Test: `./sandbox-cppcms-test`
        ```
        Running main() from gtest_main.cc
        [==========] Running 1 test from 1 test case.
        [----------] Global test environment set-up.
        [----------] 1 test from rest_test
        [ RUN      ] rest_test.rest_test_case
        [       OK ] rest_test.rest_test_case (7 ms)
        [----------] 1 test from rest_test (7 ms total)
        
        [----------] Global test environment tear-down
        [==========] 1 test from 1 test case ran. (7 ms total)
        [  PASSED  ] 1 test.
        ```
        
## Part 5: Adding REST API Routes

- Applications and Mappings
    - Hierarchical Structuring
    - URL/Parameter Pattern Matching
    - Invoking Handler Methods of Application Class
- Project Management:
    - Modify: build file [`CMakeLists.txt`](./CMakeLists.txt)
        - Add REST API Source Files
        - Add Test Source Files
- Development: ... give it a rest!
    - Add: source file(s) [`pet.cpp`](src/rest/pet.cpp)
        ```cpp
        pet::pet(cppcms::service &srv) : cppcms::application(srv) {
            dispatcher().map("GET", "/(\\d+)", &pet::read_pet, this, 1);
        }
        void pet::read_pet(int id) {
            cppcms::json::value pet;
            pet["id"] = id;
            pet["name"] = "doggie";
            pet["photoUrls"][0] = "string";
            pet["status"] = "available";
    
            response().out() << pet;
        }
        ```
    - Add: test file(s) [`pet_tests.cpp`](test/src/pet_tests.cpp)
        ```cpp
        TEST_F(pet_tests, get_pet) {
            std::string url("http://localhost:8910/v2/pet/1"), out;
            long code;
            GET(url, out, code)
        
            EXPECT_EQ(code, 200L);
            EXPECT_STREQ(out.c_str(),
        "{\"category\":{\"id\":0,\"name\":\"string\"},\
        \"id\":1,\
        \"name\":\"doggie\",\
        \"photoUrls\":[\"string\"],\
        \"status\":\"available\",\
        \"tag\":[{\"id\":0,\"name\":\"string\"}]}");
        }
        ```
    - GoTo, Configure, Build, Run, Test

## Part 6: Adding Database

- Database [SQLite3](https://sqlite.org/index.html): relational and light, self-contained, high-reliability, embedded, full-featured, public-domain
    - [Appropriate Uses For SQLite](https://sqlite.org/whentouse.html)
- Database Change Management [Sqitch](http://sqitch.org/)
    - Not Migration-Style