#include "rest/pet.hpp"

#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>
#include <cppcms/json.h>

namespace sandbox_cppcms {

pet::pet(cppcms::service &srv) : cppcms::application(srv) {
    dispatcher().map("GET", "", &pet::enumerate_pet, this);
    dispatcher().map("POST", "", &pet::create_pet, this);
    dispatcher().map("GET", "/(\\d+)", &pet::read_pet, this, 1);
    dispatcher().map("PUT", "/(\\d+)", &pet::update_pet, this, 1);
    dispatcher().map("DELETE", "/(\\d+)", &pet::delete_pet, this, 1);
};

pet::~pet() {

}

void pet::enumerate_pet() {
    cppcms::json::value pet;

    response().out() << pet;
}

void pet::create_pet() {
    cppcms::json::value pet;

    response().out() << pet;
}

void pet::read_pet(int id) {
    cppcms::json::value pet;

    response().out() << pet;
}

void pet::update_pet(int id) {
    cppcms::json::value pet;

    response().out() << pet;
}

void pet::delete_pet(int id) {
    cppcms::json::value pet;

    response().out() << pet;
}

} /* namespace sandbox_cppcms */
