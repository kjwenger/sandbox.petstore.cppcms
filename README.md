# sandbox.petstore.cppcms

Sandbox for C++/CppCMS/Boost PetStore

- Motivation: which technology is best ... is C++ old news?
    - A Bird's-Eye View: PetStore RESTful Web API implemented using ...
        - Reference API: [Swagger PetStore](http://petstore.swagger.io/)
        - Definition: [JSON](https://editor.swagger.io/) downloaded to [sandbox.petstore](https://github.com/kjwenger/sandbox.petstore/README.md)
    - [GoLang](https://golang.org/)/[Revel](https://revel.github.io/): goes from _Embedded_ to _Cloud_, replacing C++?
        - Code (auto-generated): [sandbox.petstore.golang](https://github.com/kjwenger/sandbox.petstore.golang/README.md)
    - [Erlang](https://www.erlang.org/): It Scales!
        - Code (auto-generated): [sandbox.petstore.erlang](https://github.com/kjwenger/sandbox.petstore.erlang/README.md)
    - [Elixir](https://elixir-lang.org/)/[Phoenix](http://phoenixframework.org/): **the** Formula from _Embedded_ bis _Cloud_? Ruby on Rails w/o Ruby?
        - Code (auto-generated): [sandbox.petstore.phoenix](https://github.com/kjwenger/sandbox.petstore.phoenix/README.md)
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
        - Standards: ... such as [C++98](http://www.cplusplus.com/doc/oldtutorial/)
        - Libraries: ... such as [Boost Libraries](http://www.boost.org/)
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
