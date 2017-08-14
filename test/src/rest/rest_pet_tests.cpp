#include <iostream>
#include <sstream>

#include <gtest/gtest.h>

#include <json/value.h>

#include "rest/http_macros.hpp"

#include "persistence/database.hpp"

#define VALUE_DOGGIE(pet) \
    pet["category"]["id"] = 1;\
    pet["category"]["name"] = "string";\
    pet["name"] = "doggie";\
    pet["photoUrls"][0] = "string";\
    pet["tag"][0]["id"] = 0;\
    pet["tag"][0]["name"] = "string";\
    pet["status"] = "available";\

#define VALUE_KITTIE(pet) \
    pet["id"] = 2;\
    pet["category"]["id"] = 0;\
    pet["category"]["name"] = "string";\
    pet["name"] = "kittie";\
    pet["photoUrls"][0] = "string";\
    pet["tag"]["id"] = 0;\
    pet["tag"]["name"] = "string";\
    pet["status"] = "new";\

#define PET_DOGGIE(pet) \
    pet.id = 1;\
    pet.name = "doggie";\
    pet.photoUrls = {"string"};\
    pet.status = sandbox_cppcms::model::pet_status::available;\

class rest_pet_tests : public ::testing::Test {
public:
    static void SetUpTestCase() {
        service_database = new sandbox_cppcms::persistence::database("petstore_dev");
//        std::cerr << "rest_pet_tests::SetUpTestCase() service_database: " << std::hex << service_database << std::dec << std::endl;
        service_database->init();
    }

    static void TearDownTestCase() {
//        std::cerr << "rest_pet_tests::TearDownTestCase() service_database: " << std::hex << service_database << std::dec << std::endl;
        delete service_database;
    }
protected:
    virtual void SetUp() {
        INITIALIZE()
        sandbox_cppcms::model::pet pet;
        PET_DOGGIE(pet)
        service_database->create(pet);
    }

    virtual void TearDown() {
        TERMINATE()
    }
};

// POST /pet Add a new pet to the store
TEST_F(rest_pet_tests, create_pet) {
    Json::Value pet;
    VALUE_KITTIE(pet)
    std::ostringstream os;
    os << pet.toStyledString();
    std::string url("http://localhost:8910/v2/pet");
    std::string out;
    long code;
    POST(url, os.str(), out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(), R"({"category":{"id":0,"name":"string"},"id":2,"name":"kittie","photoUrls":["string"],"status":"new","tag":{"id":0,"name":"string"}})");
}

// GET /pet/{petId} Find pet by ID                      //
TEST_F(rest_pet_tests, get_pet) {
    std::string url("http://localhost:8910/v2/pet/1");
    std::string out;
    long code;
    GET(url, out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(),
"{\"id\":1,\
\"name\":\"doggie\",\
\"photoUrls\":[\"string\"],\
\"status\":\"available\"\
}");
}

// PUT /pet Update an existing pet                      //
TEST_F(rest_pet_tests, update_pet) {
    Json::Value pet;
    pet["id"] = 2;
    pet["category"]["id"] = 0;
    pet["category"]["name"] = "string";
    pet["name"] = "kittie";
    pet["photoUrls"][0] = "string";
    pet["tag"]["id"] = 0;
    pet["tag"]["name"] = "string";
    pet["status"] = "available";
    std::ostringstream os;
    os << pet.toStyledString();
    std::string url("http://localhost:8910/v2/pet");
    std::string out;
    long code;
    PUT(url, os.str(), out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(), R"({"category":{"id":0,"name":"string"},"id":2,"name":"kittie","photoUrls":["string"],"status":"available","tag":{"id":0,"name":"string"}})");
}

// DELETE /pet/{petId} Deletes a pet                    //
TEST_F(rest_pet_tests, delete_pet) {
    std::ostringstream os;
    std::string url("http://localhost:8910/v2/pet/2");
    std::string out;
    long code;
    DELETE(url, os.str(), out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(), "");
}

TEST_F(rest_pet_tests, list_pets) {
    std::string url("http://localhost:8910/v2/pet");
    std::string out;
    long code;
    GET(url, out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(), "[{\"id\":1,\"name\":\"doggie\"}]");
}

// GET /pet/findByStatus Finds Pets by status           //
TEST_F(rest_pet_tests, search_pet_by_status) {
    std::string url("http://localhost:8910/v2/pet/findByStatus?status=available,new");
    std::string out;
    long code;
    GET(url, out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(),
"[{\"category\":{\"id\":0,\"name\":\"string\"},\
\"id\":1,\
\"name\":\"doggie\",\
\"photoUrls\":[\"string\"],\
\"status\":\"available\",\
\"tag\":[{\"id\":0,\"name\":\"string\"}]}]");
}

// GET /pet/findByTags Finds Pets by tags               //
TEST_F(rest_pet_tests, search_pet_by_tags) {
    std::string url("http://localhost:8910/v2/pet/findByTags?tags=string,foo,bar");
    std::string out;
    long code;
    GET(url, out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(),
"[{\"category\":{\"id\":0,\"name\":\"string\"},\
\"id\":1,\
\"name\":\"doggie\",\
\"photoUrls\":[\"string\"],\
\"status\":\"available\",\
\"tag\":[{\"id\":0,\"name\":\"string\"}]}]");
}
