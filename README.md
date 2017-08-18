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

## Part 5: [Adding REST API Routes](doc/part/05.md)

## Part 6: [Adding Database](doc/part/06.md)

## Part 7: Adding Object-relational mapping (ORM)

- [Hiberlite ORM](https://github.com/paulftw/hiberlite) for SQLite3: relational and light, self-contained, high-reliability, embedded, full-featured, public-domain
    - The Good: lightweight, straightforward, open-source
    - The Bad: not yet fully featured, rather new and small
- Building: ... requires some tweaking
    - Get: `https://github.com/paulftw/hiberlite.git hiberlite --recursive && cd hiberlite`
    - Build: `make`
- Development:
    - Add: model file(s) [`pet.cpp`](include/model/pet.hpp)
        ```cpp
        class pet {
        public:
            int id;
            std::string name;
            std::vector<std::string> photoUrls;
            std::vector<std::string> tags;
            pet_status status;
        };
        ```
    - Add: database service [`database.cpp`](src/persistence/database.cpp)
        ```cpp
        database::database(const std::string & target)
                : db(target + std::string(".db")) {
            db.registerBeanClass<pet>();
        }
    
        template <class T, class C>
        T database::create(const T & pet) {
            C newPet(pet);
            hiberlite::bean_ptr<C> copiedBean = db.copyBean(newPet);
            T returnPet(*copiedBean);
            return returnPet;
        }
        ```
    - Add: test file(s) [`persistence_pet_tests.cpp`](test/src/persistence/persistence_pet_tests.cpp)
        ```cpp
        TEST_F(persistence_pet_tests, database_create_pet) {
            sandbox_cppcms::model::pet pet{1, "doggie", {}, {}, sandbox_cppcms::model::pet_status::sold};
            sandbox_cppcms::model::pet createdPet = service_database->create<sandbox_cppcms::model::pet, ::pet>(pet);
        
            EXPECT_EQ(createdPet.id, 1);
            EXPECT_STREQ(createdPet.name.c_str(), "doggie");
            EXPECT_EQ(createdPet.photoUrls.size(), 0);
            EXPECT_EQ(createdPet.tags.size(), 0);
            EXPECT_EQ(createdPet.status, sandbox_cppcms::model::pet_status::sold);
        }
        ```
    - GoTo, Configure, Build, Run, Test
