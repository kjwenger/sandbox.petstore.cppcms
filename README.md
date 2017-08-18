# sandbox.petstore.cppcms

Sandbox for C++/CppCMS/Boost PetStore

- Motivation: which technology is best ... is C++ old news?
    - A Bird's-Eye View: PetStore RESTful Web API implemented using ...
        - Reference API: [Swagger PetStore](http://petstore.swagger.io/)
        - Definition: [JSON](https://editor.swagger.io/) downloaded to [sandbox.petstore](https://github.com/kjwenger/sandbox.petstore/README.md)

## Part 1: [Setting up C++ Development](doc/part/01.md)

## Part 2: [Setting up CppCMS Framework](doc/part/02.md)

## Part 3: [Setting up Cross-Compilation](doc/part/03.md)

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
- Building: ... not even that is really needed ... use CMake sub-directory inclusion
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