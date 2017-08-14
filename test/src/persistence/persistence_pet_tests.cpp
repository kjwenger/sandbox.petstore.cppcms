#include <gtest/gtest.h>

#include "persistence/Pet.hpp"
#include "persistence/database.hpp"

class persistence_pet_tests : public ::testing::Test {
protected:
    virtual void SetUp() {
        service_database = new sandbox_cppcms::persistence::database("petstore_test");
    }

    virtual void TearDown() {
        delete service_database;
    }
};

TEST_F(persistence_pet_tests, new_pet_initialized_zero) {
    sandbox_cppcms::persistence::Pet * pet = new sandbox_cppcms::persistence::Pet();

    EXPECT_EQ(pet->id, 0);
    EXPECT_STREQ(pet->name.c_str(), "");
    EXPECT_EQ(pet->photoUrls.size(), 0);
    EXPECT_EQ(pet->tags.size(), 0);

    delete pet;
}

TEST_F(persistence_pet_tests, new_pet_initialized_default) {
    sandbox_cppcms::persistence::Pet * pet = new sandbox_cppcms::persistence::Pet;

    delete pet;
}

// persistence_pet_tests.cpp:34:55: error: no matching function for call to ‘sandbox_cppcms::persistence::Pet::Pet(<brace-enclosed initializer list>)’
//     sandbox_cppcms::persistence::Pet pet{0, "", {}, {}};
//TEST_F(persistence_pet_tests, construct_pet_initialized_zero) {
//    sandbox_cppcms::persistence::Pet pet{0, "", {}, {}};
//
//    EXPECT_EQ(pet.id, 0);
//    EXPECT_STREQ(pet.name.c_str(), "");
//    EXPECT_EQ(pet.photoUrls.size(), 0);
//    EXPECT_EQ(pet.tags.size(), 0);
//}

TEST_F(persistence_pet_tests, construct_pet_initialized_default) {
    sandbox_cppcms::persistence::Pet pet;
}
