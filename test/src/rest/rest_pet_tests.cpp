#include <iostream>
#include <sstream>

#include <gtest/gtest.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Infos.hpp>

#include <json/value.h>

#include "macros.hpp"

class rest_pet_tests : public ::testing::Test {
protected:
    virtual void SetUp() {
        cURLpp::initialize();
    }

    virtual void TearDown() {
        cURLpp::terminate();
    }
};

// POST /pet Add a new pet to the store
TEST_F(rest_pet_tests, create_pet) {
    Json::Value pet;
    pet["id"] = 2;
    pet["category"]["id"] = 0;
    pet["category"]["name"] = "string";
    pet["name"] = "kittie";
    pet["photoUrls"][0] = "string";
    pet["tag"]["id"] = 0;
    pet["tag"]["name"] = "string";
    pet["status"] = "new";
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
"{\"category\":{\"id\":0,\"name\":\"string\"},\
\"id\":1,\
\"name\":\"doggie\",\
\"photoUrls\":[\"string\"],\
\"status\":\"available\",\
\"tag\":[{\"id\":0,\"name\":\"string\"}]}");
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

TEST_F(rest_pet_tests, list_pet) {
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
