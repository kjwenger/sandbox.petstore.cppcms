#include <iostream>
#include <sstream>

#include <gtest/gtest.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Infos.hpp>

#include <json/value.h>

#define GET(url, out, code)\
{\
    curlpp::Cleanup cleanup;\
    curlpp::Easy request;\
    request.setOpt<curlpp::options::Url>(url);\
    std::list<std::string> header;\
    header.push_back("Content-Type: application/json");\
    request.setOpt(new curlpp::options::HttpHeader(header));\
    std::ostringstream os;\
    curlpp::options::WriteStream ws(&os);\
    request.setOpt(ws);\
    request.perform();\
    out.assign(os.str());\
    code = curlpp::infos::ResponseCode::get(request);\
}

#define PUT(url, in, out, code)\
{\
    curlpp::Cleanup cleanup;\
    curlpp::Easy request;\
    request.setOpt(new curlpp::options::CustomRequest("PUT"));\
    request.setOpt<curlpp::options::Url>(url);\
    std::list<std::string> header;\
    header.push_back("Content-Type: application/json");\
    request.setOpt(new curlpp::options::HttpHeader(header));\
    request.setOpt(new curlpp::options::PostFields(in));\
    request.setOpt(new curlpp::options::PostFieldSize(in.length()));\
    std::ostringstream os;\
    curlpp::options::WriteStream ws(&os);\
    request.setOpt(ws);\
    request.perform();\
    out.assign(os.str());\
    code = curlpp::infos::ResponseCode::get(request);\
}

#define POST(url, in, out, code)\
{\
    curlpp::Cleanup cleanup;\
    curlpp::Easy request;\
    request.setOpt<curlpp::options::Url>(url);\
    std::list<std::string> header;\
    header.push_back("Content-Type: application/json");\
    request.setOpt(new curlpp::options::HttpHeader(header));\
    request.setOpt(new curlpp::options::PostFields(in));\
    request.setOpt(new curlpp::options::PostFieldSize(in.length()));\
    std::ostringstream os;\
    curlpp::options::WriteStream ws(&os);\
    request.setOpt(ws);\
    request.perform();\
    out.assign(os.str());\
    code = curlpp::infos::ResponseCode::get(request);\
}

#define DELETE(url, api_key, out, code)\
{\
    curlpp::Cleanup cleanup;\
    curlpp::Easy request;\
    request.setOpt(new curlpp::options::CustomRequest("DELETE"));\
    request.setOpt<curlpp::options::Url>(url);\
    std::list<std::string> header;\
    header.push_back("Content-Type: application/json");\
    header.push_back("api_key: " + api_key);\
    request.setOpt(new curlpp::options::HttpHeader(header));\
    std::ostringstream os;\
    curlpp::options::WriteStream ws(&os);\
    request.setOpt(ws);\
    request.perform();\
    out.assign(os.str());\
    code = curlpp::infos::ResponseCode::get(request);\
}

class pet_tests : public ::testing::Test {
protected:
    virtual void SetUp() {
        cURLpp::initialize();
    }

    virtual void TearDown() {
        cURLpp::terminate();
    }
};

// POST /pet Add a new pet to the store
TEST_F(pet_tests, create_pet) {
    Json::Value pet;
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
TEST_F(pet_tests, get_pet) {
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
TEST_F(pet_tests, update_pet) {
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
TEST_F(pet_tests, delete_pet) {
    std::ostringstream os;
    std::string url("http://localhost:8910/v2/pet/2");
    std::string out;
    long code;
    DELETE(url, os.str(), out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(), "");
}

TEST_F(pet_tests, list_pet) {
    std::string url("http://localhost:8910/v2/pet");
    std::string out;
    long code;
    GET(url, out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(), "[{\"id\":1,\"name\":\"doggie\"}]");
}

// GET /pet/findByStatus Finds Pets by status           //
TEST_F(pet_tests, search_pet_by_status) {
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
TEST_F(pet_tests, search_pet_by_tags) {
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
