# sandbox.petstore.cppcms

Sandbox for C++/CppCMS/Boost PetStore

- Motivation: which technology is best ... is C++ old news?
    - A Bird's-Eye View: PetStore RESTful Web API implemented using ...
        - Reference API: [Swagger PetStore](http://petstore.swagger.io/)
        - Definition: [JSON](https://editor.swagger.io/) downloaded to [sandbox.petstore](https://github.com/kjwenger/sandbox.petstore/README.md)

## Part 1: [Setting up C++ Development](doc/part/01.md)

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
