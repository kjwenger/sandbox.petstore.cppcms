#include <exception>
#include <vector>
#include <iostream>

#include <gtest/gtest.h>

#define private public

#include "persistence/pet.hpp"
#include "persistence/database.hpp"
#include "persistence/persistence_exception.hpp"

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
    EXPECT_EQ(pet->status, sandbox_cppcms::model::pet_status::available);

    delete pet;
}

TEST_F(persistence_pet_tests, new_pet_initialized_default) {
    ::pet * pet = new ::pet;

    delete pet;
}

TEST_F(persistence_pet_tests, construct_pet_initialized_zero) {
    ::pet pet(0,
              "",
              std::vector<std::string>(),
              std::vector<std::string>(),
              sandbox_cppcms::model::pet_status::pending);

    EXPECT_EQ(pet.id, 0);
    EXPECT_STREQ(pet.name.c_str(), "");
    EXPECT_EQ(pet.photoUrls.size(), 0);
    EXPECT_EQ(pet.tags.size(), 0);
}

TEST_F(persistence_pet_tests, construct_pet_initialized_default) {
    ::pet pet;
}

TEST_F(persistence_pet_tests, hiberlite_get_class_name_for_pet) {
    std::string className = hiberlite::Database::getClassName<pet>();
                                                                                                                        std::cerr << "persistence_pet_tests::hiberlite_get_class_name_for_pet() className: " << className << std::endl;

    EXPECT_STREQ(className.c_str(), "pet");
}

TEST_F(persistence_pet_tests, database_create_pet) {
    sandbox_cppcms::model::pet pet{
            1,
            "doggie",
            {},
            {},
            sandbox_cppcms::model::pet_status::sold
    };
    sandbox_cppcms::model::pet createdPet = service_database->create<sandbox_cppcms::model::pet>(pet);
                                                                                                                        std::cerr << "persistence_pet_tests::database_create_pet() createdPet: " << createdPet << std::endl;

    EXPECT_EQ(createdPet.id, 1);
    EXPECT_STREQ(createdPet.name.c_str(), "doggie");
    EXPECT_EQ(createdPet.photoUrls.size(), 0);
    EXPECT_EQ(createdPet.tags.size(), 0);
    EXPECT_EQ(createdPet.status, sandbox_cppcms::model::pet_status::sold);

    std::vector<hiberlite::bean_ptr<::pet>> allBeans =
            service_database->db.getAllBeans<::pet>();
                                                                                                                        std::cerr << "persistence_pet_tests::database_create_pet() allBeans.size(): " << allBeans.size() << std::endl;
    EXPECT_EQ(allBeans.size(), 1);
}

TEST_F(persistence_pet_tests, database_read_pet) {
    sandbox_cppcms::model::pet pet{
            1,
            "doggie",
            {},
            {},
            sandbox_cppcms::model::pet_status::sold
    };
    sandbox_cppcms::model::pet createdPet = service_database->create<sandbox_cppcms::model::pet>(pet);
                                                                                                                        std::cerr << "persistence_pet_tests::database_read_pet() createdPet: " << createdPet << std::endl;

    sandbox_cppcms::model::pet readPet = service_database->read<sandbox_cppcms::model::pet>(createdPet.id);
    EXPECT_EQ(readPet.id, 1);
    EXPECT_STREQ(readPet.name.c_str(), "doggie");
    EXPECT_EQ(readPet.photoUrls.size(), 0);
    EXPECT_EQ(readPet.tags.size(), 0);
    EXPECT_EQ(readPet.status, sandbox_cppcms::model::pet_status::sold);
}

TEST_F(persistence_pet_tests, database_update_pet) {
    sandbox_cppcms::model::pet pet{
            1,
            "doggie",
            {},
            {},
            sandbox_cppcms::model::pet_status::sold
    };
    sandbox_cppcms::model::pet updatePet{
            1,
            "kittie",
            {},
            {},
            sandbox_cppcms::model::pet_status::pending
    };
    sandbox_cppcms::model::pet createdPet = service_database->create<sandbox_cppcms::model::pet>(pet);
                                                                                                                        std::cerr << "persistence_pet_tests::database_read_pet() createdPet: " << createdPet << std::endl;

    {
        sandbox_cppcms::model::pet readPet = service_database->read<sandbox_cppcms::model::pet>(createdPet.id);
        EXPECT_EQ(readPet.id, 1);
        EXPECT_STREQ(readPet.name.c_str(), "doggie");
        EXPECT_EQ(readPet.photoUrls.size(), 0);
        EXPECT_EQ(readPet.tags.size(), 0);
        EXPECT_EQ(readPet.status, sandbox_cppcms::model::pet_status::sold);

        sandbox_cppcms::model::pet updatedPet = service_database->update<sandbox_cppcms::model::pet>(updatePet);
        EXPECT_EQ(updatedPet.id, 1);
        EXPECT_STREQ(updatedPet.name.c_str(), "kittie");
        EXPECT_EQ(updatedPet.photoUrls.size(), 0);
        EXPECT_EQ(updatedPet.tags.size(), 0);
        EXPECT_EQ(updatedPet.status, sandbox_cppcms::model::pet_status::pending);
    }

    {
        sandbox_cppcms::model::pet readPet = service_database->read<sandbox_cppcms::model::pet>(updatePet.id);
        EXPECT_EQ(readPet.id, 1);
        EXPECT_STREQ(readPet.name.c_str(), "kittie");
        EXPECT_EQ(readPet.photoUrls.size(), 0);
        EXPECT_EQ(readPet.tags.size(), 0);
        EXPECT_EQ(readPet.status, sandbox_cppcms::model::pet_status::pending);
    }
}

TEST_F(persistence_pet_tests, database_delete_pet) {
    sandbox_cppcms::model::pet pet{
            1,
            "doggie",
            {},
            {},
            sandbox_cppcms::model::pet_status::sold
    };
    sandbox_cppcms::model::pet createdPet = service_database->create<sandbox_cppcms::model::pet>(pet);
                                                                                                                        std::cerr << "persistence_pet_tests::database_delete_pet() createdPet: " << createdPet << std::endl;

    {
        sandbox_cppcms::model::pet readPet = service_database->read<sandbox_cppcms::model::pet>(createdPet.id);
                                                                                                                        std::cerr << "persistence_pet_tests::database_delete_pet() readPet: " << readPet << std::endl;
        EXPECT_EQ(readPet.id, 1);
        EXPECT_STREQ(readPet.name.c_str(), "doggie");
        EXPECT_EQ(readPet.photoUrls.size(), 0);
        EXPECT_EQ(readPet.tags.size(), 0);
        EXPECT_EQ(readPet.status, sandbox_cppcms::model::pet_status::sold);

        service_database->delet<sandbox_cppcms::model::pet>(readPet.id);
                                                                                                                        std::cerr << "persistence_pet_tests::database_delete_pet() service_database->delet<sandbox_cppcms::model::pet>(readPet.id);" << std::endl;
    }

    {
        try {
            sandbox_cppcms::model::pet readPet =
                    service_database->read<sandbox_cppcms::model::pet>(createdPet.id);
                                                                                                                        std::cerr << "persistence_pet_tests::database_delete_pet() readPet: " << readPet << std::endl;
            FAIL();
        }
        catch (...) {
            // all is well
        }
        try {
            service_database->delet<sandbox_cppcms::model::pet>(createdPet.id);
                                                                                                                        std::cerr << "persistence_pet_tests::database_delete_pet() service_database->delet<sandbox_cppcms::model::pet>(readPet.id);" << std::endl;
            FAIL();
        }
        catch (...) {
            // all is well
        }
    }
}

TEST_F(persistence_pet_tests, database_list_pets) {
    std::vector<sandbox_cppcms::model::pet> pets;
    service_database->list<sandbox_cppcms::model::pet>(pets);
                                                                                                                        std::cerr << "persistence_pet_tests::database_list_pets() pets.size(): " << pets.size() << std::endl;

    EXPECT_EQ(pets.size(), 0);
}
