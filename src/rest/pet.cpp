#include <utility>                 // std::pair<T, C>
#include <string>                  // std::string
#include <sstream>                 // std::istringstream
#include <algorithm>               // std::find

#include <cppcms/url_dispatcher.h> // dispatcher()
#include <cppcms/url_mapper.h>     // mapper()
#include <cppcms/http_request.h>   // request()
#include <cppcms/http_response.h>  // response()
#include <cppcms/json.h>           // cppcms::json::value

#include "rest/pet.hpp"

#define PET_DOGGIE(pet) \
    pet["category"]["id"] = 0;\
    pet["category"]["name"] = "string";\
    pet["name"] = "doggie";\
    pet["photoUrls"][0] = "string";\
    pet["tag"][0]["id"] = 0;\
    pet["tag"][0]["name"] = "string";\
    pet["status"] = "available";\

namespace sandbox_cppcms {

    pet::pet(cppcms::service &srv) : cppcms::application(srv) {
        dispatcher().map("POST", "", &pet::create_pet, this);
        dispatcher().map("GET", "/(\\d+)", &pet::read_pet, this, 1);
        dispatcher().map("PUT", "", &pet::update_pet, this);
        dispatcher().map("DELETE", "/(\\d+)", &pet::delete_pet, this, 1);
        dispatcher().map("GET", "", &pet::list_pets, this);
        dispatcher().map("GET", "/findByStatus", &pet::search_pet_by_status, this);
        dispatcher().map("GET", "/findByTags", &pet::search_pet_by_tags, this);
    }

    pet::~pet() {

    }

    void pet::create_pet() {
        std::pair<void *, size_t> raw_post_data = request().raw_post_data();
        std::string string((const char *) raw_post_data.first, raw_post_data.second);
        std::istringstream is(string);
        cppcms::json::value pet;
        is >> pet;

        response().out() << pet;
    }

    void pet::read_pet(int id) {
        cppcms::json::value pet;
        pet["id"] = id;\
        PET_DOGGIE(pet)

        response().out() << pet;
    }

    void pet::update_pet() {
        std::pair<void *, size_t> raw_post_data = request().raw_post_data();
        std::string content((const char *) raw_post_data.first, raw_post_data.second);
        std::cerr << "pet::update_pet() content: " << content << std::endl;
        std::istringstream is(content);
        cppcms::json::value pet;
        is >> pet;
        std::cerr << "pet::update_pet() pet: " << pet << std::endl;

        response().out() << pet;
    }

    void pet::delete_pet(int id) {
        response().status(200);
    }

    void pet::list_pets() {
        cppcms::json::value pets;
        pets[0]["id"] = 1;
        pets[0]["name"] = "doggie";

        response().out() << pets;
    }

    void pet::search_pet_by_status() {
        const std::string & query_string = request().query_string();
        std::cerr << "pet::search_pet_by_status() query_string: " << query_string << std::endl;
        const std::string equals("=");
        size_t end;
        std::string statuses;
        if ((end = query_string.find(equals)) != std::string::npos) {
            size_t count = query_string.length() - end - 1;
            statuses = query_string.substr(end + 1, count);
        }
        std::cerr << "pet::search_pet_by_status() statuses: " << statuses << std::endl;
        std::vector<std::string> tokens;
        const std::string comma(",");
        size_t begin = 0;
        while ((end = statuses.find(comma, begin)) != std::string::npos) {
            std::string token = statuses.substr(begin, end - begin);
            tokens.push_back(token);
            begin = end + 1;
        }
        if (begin < statuses.length()) {
            std::string token = statuses.substr(begin, statuses.length() - begin);
            tokens.push_back(token);
        }
        std::ostringstream os;
        std::copy(tokens.begin(), tokens.end(), std::ostream_iterator<std::string>(os, ","));
        std::cerr << "pet::search_pet_by_status() tokens: " << os.str() << std::endl;

        cppcms::json::value pets;
        pets[0]["id"] = 1;\
        PET_DOGGIE(pets[0])
        const std::string & status = pets[0]["status"].str();
        std::cerr << "pet::search_pet_by_status() status: " << status << std::endl;
        if (std::find(tokens.begin(), tokens.end(), status) != tokens.end()) {
            response().out() << pets;
        } else {
            response().out() << "[]";
        }
    }

    void pet::search_pet_by_tags() {
        const std::string & query_string = request().query_string();
        std::cerr << "pet::search_pet_by_tag() query_string: " << query_string << std::endl;
        const std::string equals("=");
        size_t end;
        std::string tags;
        if ((end = query_string.find(equals)) != std::string::npos) {
            size_t count = query_string.length() - end - 1;
            tags = query_string.substr(end + 1, count);
        }
        std::cerr << "pet::search_pet_by_tag() tags: " << tags << std::endl;
        std::vector<std::string> tokens;
        const std::string comma(",");
        size_t begin = 0;
        while ((end = tags.find(comma, begin)) != std::string::npos) {
            std::string token = tags.substr(begin, end - begin);
            tokens.push_back(token);
            begin = end + 1;
        }
        if (begin < tags.length()) {
            std::string token = tags.substr(begin, tags.length() - begin);
            tokens.push_back(token);
        }
        std::ostringstream os;
        std::copy(tokens.begin(), tokens.end(), std::ostream_iterator<std::string>(os, ","));
        std::cerr << "pet::search_pet_by_tag() tokens: " << os.str() << std::endl;

        cppcms::json::value pets;
        pets[0]["id"] = 1;
        PET_DOGGIE(pets[0])
        const std::string & tag = pets[0]["tag"][0]["name"].str();
        std::cerr << "pet::search_pet_by_tag() tag: " << tag << std::endl;
        if (std::find(tokens.begin(), tokens.end(), tag) != tokens.end()) {
            response().out() << pets;
        } else {
            response().out() << "[]";
        }
    }

} /* namespace sandbox_cppcms */
