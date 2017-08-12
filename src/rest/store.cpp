#include "rest/store.hpp"

#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>
#include <cppcms/json.h>

#define STORE_ORDER(order) \
order["id"] = 2;\
order["petId"] = 1;\
order["quantity"] = 1;\
order["shipDate"] = "2017-08-12T16:23:07.307Z";\
order["status"] = "placed";\
order["complete"] = false;\

namespace sandbox_cppcms {

    store::store(cppcms::service& srv) : cppcms::application(srv) {
        dispatcher().map("POST", "/order", &store::create_store_order, this);
        dispatcher().map("GET", "/order/(\\d+)", &store::read_store_order, this, 1);
        dispatcher().map("DELETE", "/order/(\\d+)", &store::delete_store_order, this, 1);
        dispatcher().map("GET", "/inventory", &store::list_store_inventory, this);
    }

    store::~store() {

    }

    void store::list_store_inventory() {
        cppcms::json::value inventory;
        inventory["1"] = 1;
        inventory["123"] = 1;
        inventory["msvc"] = 1;
        inventory["sold"] = 29;
        inventory["jhjhjhj"] = 1;
        inventory["string"] = 4678;
        inventory["pending"] = 21;
        inventory["foo"] = 1;
        inventory["available"] = 810;
        inventory["aaaaaa"] = 1;
        inventory["dead"] = 1;
        inventory["vbsdbsdbsdbsd"] = 2;
        inventory["Sold"] = 1;

        response().out() << inventory;
    }

    void store::create_store_order() {
        std::pair<void *, size_t> raw_post_data = request().raw_post_data();
        std::string string((const char *) raw_post_data.first, raw_post_data.second);
        std::istringstream is(string);
        cppcms::json::value order;
        is >> order;
        order["id"] = 2;

        response().out() << order;
    }

    void store::read_store_order(int id) {
        cppcms::json::value order;
        STORE_ORDER(order)
        order["id"] = id;

        response().out() << order;
   }

    void store::delete_store_order(int id) {
        response().status(200);
    }

} /* namespace sandbox_cppcms */
