#include <gtest/gtest.h>

#include "model/pet.hpp"

class model_pet_tests : public ::testing::Test {
protected:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }
};

TEST_F(model_pet_tests, new_pet_initialized_zero) {
    sandbox_cppcms::model::pet * pet = new sandbox_cppcms::model::pet();

    EXPECT_EQ(pet->id, 0);
    EXPECT_STREQ(pet->name.c_str(), "");
    EXPECT_EQ(pet->photoUrls.size(), 0);
    EXPECT_EQ(pet->tags.size(), 0);
    EXPECT_EQ(pet->status, sandbox_cppcms::model::pet_status::available);

    delete pet;
}

TEST_F(model_pet_tests, new_pet_initialized_default) {
    sandbox_cppcms::model::pet * pet = new sandbox_cppcms::model::pet;

    delete pet;
}

TEST_F(model_pet_tests, construct_pet_initialized_zero) {
    sandbox_cppcms::model::pet pet{
            0,
            "",
            {},
            {},
            sandbox_cppcms::model::pet_status::pending
    };

    EXPECT_EQ(pet.id, 0);
    EXPECT_STREQ(pet.name.c_str(), "");
    EXPECT_EQ(pet.photoUrls.size(), 0);
    EXPECT_EQ(pet.tags.size(), 0);
    EXPECT_EQ(pet.status, sandbox_cppcms::model::pet_status::pending);
}

TEST_F(model_pet_tests, construct_pet_initialized_default) {
    sandbox_cppcms::model::pet pet;
}
