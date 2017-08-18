# sandbox.petstore.cppcms

Sandbox for C++/CppCMS/Boost PetStore

- Motivation: which technology is best ... is C++ old news?
    - A Bird's-Eye View: PetStore RESTful Web API implemented using ...
        - Reference API: [Swagger PetStore](http://petstore.swagger.io/)
        - Definition: [JSON](https://editor.swagger.io/) downloaded to [sandbox.petstore](https://github.com/kjwenger/sandbox.petstore/README.md)

## Part 1: [Setting up C++ Development](doc/part/01.md)

## Part 2: [Setting up CppCMS Framework](doc/part/02.md)

## Part 3: [Setting up Cross-Compilation](doc/part/03.md)

## Part 4: [Setting up Testing](doc/part/04.md)

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
