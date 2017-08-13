#include <gtest/gtest.h>

#include "model/Pet.hpp"

class model_pet_tests : public ::testing::Test {
protected:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }
};

TEST_F(model_pet_tests, new_pet_initialized_zero) {
    sandbox_cppcms::model::Pet * pet = new sandbox_cppcms::model::Pet();

    EXPECT_EQ(pet->id, 0);
    EXPECT_STREQ(pet->name.c_str(), "");
    EXPECT_EQ(pet->photoUrls.size(), 0);
    EXPECT_EQ(pet->tags.size(), 0);

    delete pet;
}

TEST_F(model_pet_tests, new_pet_initialized_default) {
    sandbox_cppcms::model::Pet * pet = new sandbox_cppcms::model::Pet;

    delete pet;
}

TEST_F(model_pet_tests, construct_pet_initialized_zero) {
    sandbox_cppcms::model::Pet pet{0, "", {}, {}};

    EXPECT_EQ(pet.id, 0);
    EXPECT_STREQ(pet.name.c_str(), "");
    EXPECT_EQ(pet.photoUrls.size(), 0);
    EXPECT_EQ(pet.tags.size(), 0);
}

TEST_F(model_pet_tests, construct_pet_initialized_default) {
    sandbox_cppcms::model::Pet pet;
}
