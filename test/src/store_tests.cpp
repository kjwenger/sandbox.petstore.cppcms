#include <iostream>
#include <sstream>

#include <gtest/gtest.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Infos.hpp>

#include <json/value.h>

#include "macros.hpp"

class store_tests : public ::testing::Test {
protected:
    virtual void SetUp() {
        cURLpp::initialize();
    }

    virtual void TearDown() {
        cURLpp::terminate();
    }
};

// POST /store/store/order Place an order for a pet
TEST_F(store_tests, create_store_order) {
    Json::Value order;
    order["id"] = 2;
    order["petId"] = 1;
    order["quantity"] = 1;
    order["shipDate"] = "2017-08-12T16:23:07.307Z";
    order["status"] = "placed";
    order["complete"] = false;
    std::ostringstream os;
    os << order.toStyledString();
    std::string url("http://localhost:8910/v2/store/order");
    std::string out;
    long code;
    POST(url, os.str(), out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(),
R"({"complete":false,"id":2,"petId":1,"quantity":1,"shipDate":"2017-08-12T16:23:07.307Z","status":"placed"})");
}

// GET /store/store/order/{orderId} Find purchase order by ID
TEST_F(store_tests, get_store_order) {
    std::string url("http://localhost:8910/v2/store/order/1");
    std::string out;
    long code;
    GET(url, out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(),
"{\"complete\":false,\
\"id\":1,\
\"petId\":1,\
\"quantity\":1,\
\"shipDate\":\"2017-08-12T16:23:07.307Z\",\
\"status\":\"placed\"}");
}

// DELETE /store/store/order/{orderId} Delete purchase order by ID
TEST_F(store_tests, delete_store_order) {
    std::ostringstream os;
    std::string url("http://localhost:8910/v2/store/order/2");
    std::string out;
    long code;
    DELETE(url, os.str(), out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(), "");
}

// GET /store/store/inventory Returns pet inventories by status
TEST_F(store_tests, list_store_inventory) {
    std::string url("http://localhost:8910/v2/store/inventory");
    std::string out;
    long code;
    GET(url, out, code)

    EXPECT_EQ(code, 200L);
    EXPECT_STREQ(out.c_str(), "{\"1\":1,\"123\":1,\"Sold\":1,\"aaaaaa\":1,\"available\":810,\"dead\":1,\"foo\":1,\"jhjhjhj\":1,\"msvc\":1,\"pending\":21,\"sold\":29,\"string\":4678,\"vbsdbsdbsdbsd\":2}");
}
