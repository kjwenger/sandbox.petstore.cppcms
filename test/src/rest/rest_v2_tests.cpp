#include <iostream>

#include <gtest/gtest.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

class rest_v2_tests : public ::testing::Test {
protected:
    virtual void SetUp() {
        cURLpp::initialize();
    }

    virtual void TearDown() {
        cURLpp::terminate();
    }
};

TEST_F(rest_v2_tests, get_info)
{
    curlpp::Cleanup cleanup;
    curlpp::Easy request;
    request.setOpt<curlpp::options::Url>("http://localhost:8910/v2");
    std::ostringstream os;
    curlpp::options::WriteStream ws(&os);
    request.setOpt(ws);
    request.perform();

    EXPECT_STREQ(R"({"name":"sandbox-cppcms","version":"0.1.0"})", os.str().c_str());
}