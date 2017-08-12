#include <iostream>
#include <sstream>

#include <gtest/gtest.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Infos.hpp>

#include <json/value.h>

#include "macros.hpp"

class user_tests : public ::testing::Test {
protected:
    virtual void SetUp() {
        cURLpp::initialize();
    }

    virtual void TearDown() {
        cURLpp::terminate();
    }
};

// POST /user Add a new user to the store
TEST_F(user_tests, create_user) {
    Json::Value user;
    user["id"] = 2;
    user["category"]["id"] = 0;
    user["category"]["name"] = "string";
    user["name"] = "kittie";
    user["photoUrls"][0] = "string";
    user["tag"]["id"] = 0;
    user["tag"]["name"] = "string";
    user["status"] = "new";
    std::ostringstream os;
    os << user.toStyledString();
    std::string url("http://localhost:8910/v2/user");
    std::string out;
    long code;
    POST(url, os.str(), out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(), R"({"category":{"id":0,"name":"string"},"id":2,"name":"kittie","photoUrls":["string"],"status":"new","tag":{"id":0,"name":"string"}})");
}

// GET /user/{userId} Find user by ID                      //
TEST_F(user_tests, get_user) {
    std::string url("http://localhost:8910/v2/user/string");
    std::string out;
    long code;
    GET(url, out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(), "{"
            "\"email\":\"string\","
            "\"firstName\":\"string\","
            "\"id\":1,"
            "\"lastName\":\"string\","
            "\"password\":\"string\","
            "\"phone\":\"string\","
            "\"userStatus\":0,"
            "\"username\":\"string\""
        "}");
}

// PUT /user Update an existing user                      //
TEST_F(user_tests, update_user) {
    Json::Value user;
    user["id"] = 1;\
    user["username"] = "string";\
    user["firstName"] = "string";\
    user["lastName"] = "string";\
    user["email"] = "string";\
    user["password"] = "string";\
    user["phone"] = "string";\
    user["userStatus"] = 2;\
    std::ostringstream os;
    os << user.toStyledString();
    std::string url("http://localhost:8910/v2/user/string");
    std::string out;
    long code;
    PUT(url, os.str(), out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(), "{"
            "\"email\":\"string\","
            "\"firstName\":\"string\","
            "\"id\":1,"
            "\"lastName\":\"string\","
            "\"password\":\"string\","
            "\"phone\":\"string\","
            "\"userStatus\":2,"
            "\"username\":\"string\""
        "}");
}

// DELETE /user/{userId} Deletes a user                    //
TEST_F(user_tests, delete_user) {
    std::ostringstream os;
    std::string url("http://localhost:8910/v2/user/string");
    std::string out;
    long code;
    DELETE(url, os.str(), out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(), "");
}
