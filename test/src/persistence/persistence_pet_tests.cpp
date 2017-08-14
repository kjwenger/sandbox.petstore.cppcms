#include <exception>
#include <vector>
#include <iostream>

#include <gtest/gtest.h>

#define private public

#include "persistence/pet.hpp"
#include "persistence/database.hpp"

class persistence_pet_tests : public ::testing::Test {
public:
    static void SetUpTestCase() {
        service_database = new sandbox_cppcms::persistence::database("petstore_dev");
        std::cerr << "persistence_pet_tests::SetUpTestCase() service_database: " << std::hex << service_database << std::dec << std::endl;
        service_database->init();
    }

    static void TearDownTestCase() {
        std::cerr << "persistence_pet_tests::TearDownTestCase() service_database: " << std::hex << service_database << std::dec << std::endl;
        delete service_database;
    }
protected:
    virtual void SetUp() {
        std::cerr << "persistence_pet_tests::SetUpTestCase()" << std::endl;
        service_database->init();
    }

    virtual void TearDown() {
        std::cerr << "persistence_pet_tests::TearDown()" << std::endl;
    }
};

TEST_F(persistence_pet_tests, new_pet_initialized_zero) {
    pet * pet = new ::pet();

    EXPECT_EQ(pet->id, 0);
    EXPECT_STREQ(pet->name.c_str(), "");
    EXPECT_EQ(pet->photoUrls.size(), 0);
    EXPECT_EQ(pet->tags.size(), 0);

    delete pet;
}

TEST_F(persistence_pet_tests, new_pet_initialized_default) {
    pet * pet = new ::pet;

    delete pet;
}

// persistence_pet_tests.cpp:34:55: error: no matching function for call to ‘pet::pet(<brace-enclosed initializer list>)’
//     pet pet{0, "", {}, {}};
//TEST_F(persistence_pet_tests, construct_pet_initialized_zero) {
//    pet pet{0, "", {}, {}};
//
//    EXPECT_EQ(pet.id, 0);
//    EXPECT_STREQ(pet.name.c_str(), "");
//    EXPECT_EQ(pet.photoUrls.size(), 0);
//    EXPECT_EQ(pet.tags.size(), 0);
//}

TEST_F(persistence_pet_tests, construct_pet_initialized_default) {
    pet pet;
}

TEST_F(persistence_pet_tests, hiberlite_get_classname_for_pet) {
    std::string className = hiberlite::Database::getClassName<pet>();
    std::cerr << "persistence_pet_tests::hiberlite_get_classname_for_pet() className: " << className << std::endl;

    EXPECT_STREQ(className.c_str(), "pet");
}

TEST_F(persistence_pet_tests, database_create_pet) {
    try {
        sandbox_cppcms::model::pet pet{
                1,
                "doggie",
                {},
                {}
        };
        sandbox_cppcms::model::pet createdPet = service_database->create_pet(pet);
        std::cerr << "persistence_pet_tests::database_create_pet() createdPet: " << createdPet << std::endl;

        EXPECT_EQ(createdPet.id, 1);
        EXPECT_STREQ(createdPet.name.c_str(), "doggie");

        std::vector<hiberlite::bean_ptr<::pet>> allBeans =
                service_database->db.getAllBeans<::pet>();
        std::cerr << "persistence_pet_tests::database_create_pet() allBeans.size(): " << allBeans.size() << std::endl;
        EXPECT_EQ(allBeans.size(), 1);
    }
    catch (const std::exception & e) {
        std::cerr << "persistence_pet_tests::database_create_pet() e.what(): " << e.what() << std::endl;
    }
}

TEST_F(persistence_pet_tests, database_list_pets) {
    std::vector<sandbox_cppcms::model::pet> pets;
    service_database->list_pets(pets);
    std::cerr << "persistence_pet_tests::database_list_pets() pets.size(): " << pets.size() << std::endl;

    EXPECT_EQ(pets.size(), 0);
}
