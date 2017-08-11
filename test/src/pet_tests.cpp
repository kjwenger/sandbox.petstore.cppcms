#include <iostream>

#include <gtest/gtest.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

class pet_tests : public ::testing::Test {
protected:
    virtual void SetUp() {
        cURLpp::initialize();
    }

    virtual void TearDown() {
        cURLpp::terminate();
    }
};

TEST_F(pet_tests, get_pet)
{
    curlpp::Cleanup cleanup;
    curlpp::Easy request;
    request.setOpt<curlpp::options::Url>("http://localhost:8910/v2/pet/1");
    std::ostringstream os;
    curlpp::options::WriteStream ws(&os);
    request.setOpt(ws);
    request.perform();

    EXPECT_STREQ(R"({"id":1,"category":{"id":1,"name":"string"},"name":"doggie","photoUrls":["string"],"tags":[{"id":1,"name":"string"}],"status":"available"})",
            os.str().c_str());
}