#include <iostream>
#include <sstream>

#include <gtest/gtest.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Infos.hpp>

#include <json/value.h>

#include "macros.hpp"

#define USER(user)\
    user["id"] = 1;\
    user["username"] = "string";\
    user["firstName"] = "string";\
    user["lastName"] = "string";\
    user["email"] = "string";\
    user["password"] = "string";\
    user["phone"] = "string";\
    user["userStatus"] = 0;\

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
    USER(user)
    std::ostringstream os;
    os << user.toStyledString();
    std::string url("http://localhost:8910/v2/user");
    std::string out;
    long code;
    POST(url, os.str(), out, code)

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

// POST /user/createWithArray Creates list of users with given input array
TEST_F(user_tests, create_user_with_array) {
    Json::Value users;
    USER(users[0])
    std::ostringstream os;
    os << users.toStyledString();
    std::string url("http://localhost:8910/v2/user");
    std::string out;
    long code;
    POST(url, os.str(), out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(), "[{"
            "\"email\":\"string\","
            "\"firstName\":\"string\","
            "\"id\":1,"
            "\"lastName\":\"string\","
            "\"password\":\"string\","
            "\"phone\":\"string\","
            "\"userStatus\":0,"
            "\"username\":\"string\""
        "}]");
}

// POST /user/createWithList Creates list of users with given input array
TEST_F(user_tests, create_user_with_list) {
    Json::Value users;
    USER(users[0])
    std::ostringstream os;
    os << users.toStyledString();
    std::string url("http://localhost:8910/v2/user");
    std::string out;
    long code;
    POST(url, os.str(), out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(), "[{"
            "\"email\":\"string\","
            "\"firstName\":\"string\","
            "\"id\":1,"
            "\"lastName\":\"string\","
            "\"password\":\"string\","
            "\"phone\":\"string\","
            "\"userStatus\":0,"
            "\"username\":\"string\""
        "}]");
}

// GET /user/login Logs user into the system
TEST_F(user_tests, login_user) {
    std::string url("http://localhost:8910/v2/user/login?username=string&password=string");
    std::string out;
    long code;
    GET(url, out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(), "\"string\"");
}

// GET /user/logout Logs out current logged in user session
TEST_F(user_tests, logout_user) {
    std::string url("http://localhost:8910/v2/user/logout");
    std::string out;
    long code;
    GET(url, out, code)

    EXPECT_EQ(code, 200L);
}

// GET /user/{userId} Find user by ID
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

// PUT /user Update an existing user
TEST_F(user_tests, update_user) {
    Json::Value user;
    USER(user)
    user["userStatus"] = 2;
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

// DELETE /user/{userId} Deletes a user
TEST_F(user_tests, delete_user) {
    std::ostringstream os;
    std::string url("http://localhost:8910/v2/user/string");
    std::string out;
    long code;
    DELETE(url, os.str(), out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(), "");
}
