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

#include "model/pet.hpp"

#include "json_utility.hpp"

#include "persistence/database.hpp"
#include "persistence/pet.hpp"

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
                                                                                                                        std::cerr << "pet::create_pet() ........................................" << std::endl;
        try {
            std::pair<void *, size_t> raw_post_data = request().raw_post_data();
            std::string content((const char *) raw_post_data.first, raw_post_data.second);
                                                                                                                        std::cerr << "pet::create_pet() content: " << content << std::endl;
            std::istringstream is(content);
            cppcms::json::value value;
            is >> value;
                                                                                                                        std::cerr << "pet::create_pet() value: " << value << std::endl;
            model::pet pet;
            json_utility::copy(value, pet);
                                                                                                                        std::cerr << "pet::create_pet() pet: " << pet << std::endl;
            model::pet created = service_database->create<model::pet>(pet);
                                                                                                                        std::cerr << "pet::create_pet() created: " << created << std::endl;
            cppcms::json::value result;
            json_utility::copy(created, result);
                                                                                                                        std::cerr << "pet::create_pet() result: " << result << std::endl;

            response().status(201);
            response().out() << result;
        }
        catch (...) {
            response().status(500);
        }
    }

    void pet::read_pet(int id) {
                                                                                                                        std::cerr << "pet::read_pet(" << id << ") ........................................" << std::endl;
        try {
            model::pet pet = service_database->read<model::pet>(id);
                                                                                                                        std::cerr << "pet::read_pet(...) pet: " << pet << std::endl;
            cppcms::json::value value;
            json_utility::copy(pet, value);
                                                                                                                        std::cerr << "pet::read_pet(...) value: " << value << std::endl;
            response().out() << value;
        }
        catch (...) {
            response().status(404);
        }
    }

    void pet::update_pet() {
                                                                                                                        std::cerr << "pet::update_pet() ........................................" << std::endl;
        try {
            std::pair<void *, size_t> raw_post_data = request().raw_post_data();
            std::string content((const char *) raw_post_data.first, raw_post_data.second);
                                                                                                                        std::cerr << "pet::update_pet() content: " << content << std::endl;
            std::istringstream is(content);
            cppcms::json::value value;
            is >> value;
                                                                                                                        std::cerr << "pet::update_pet() value: " << value << std::endl;
            model::pet pet;
            json_utility::copy(value, pet);
                                                                                                                        std::cerr << "pet::update_pet() pet: " << pet << std::endl;
            try {
                service_database->update<model::pet>(pet);
            }
            catch (...) {
                response().status(404);
                return;
            }
            model::pet updated = service_database->update<model::pet>(pet);
                                                                                                                        std::cerr << "pet::update_pet() updated: " << updated << std::endl;
            cppcms::json::value result;
            json_utility::copy(updated, result);
                                                                                                                        std::cerr << "pet::update_pet()                                                                                                                         std::cerr << \"pet::update_pet() updated: \" << updated << std::endl;: " << result << std::endl;
            response().out() << result;
        }
        catch (...) {
            response().status(500);
        }
    }

    void pet::delete_pet(int id) {
                                                                                                                        std::cerr << "pet::delete_pet(" << id << ") ........................................" << std::endl;
        try {
            service_database->delet<model::pet>(id);
            response().status(200);
        }
        catch (...) {
            response().status(404);
        }
    }

    void pet::list_pets() {
                                                                                                                        std::cerr << "pet::list_pets() ........................................" << std::endl;
        try {
            std::vector<model::pet> pets;
            service_database->list<model::pet>(pets);
                                                                                                                        std::cerr << "pet::list_pets() pets: " << pets << std::endl;
            cppcms::json::value value;
            json_utility::copy(pets, value);

            response().out() << value;
        }
        catch (...) {
            response().status(500);
        }
        cppcms::json::value value;
        value[0]["id"] = 1;
        value[0]["name"] = "doggie";

        response().out() << value;
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

        cppcms::json::value value;
        value[0]["id"] = 1;\
        PET_DOGGIE(value[0])
        const std::string & status = value[0]["status"].str();
                                                                                                                        std::cerr << "pet::search_pet_by_status() status: " << status << std::endl;
        if (std::find(tokens.begin(), tokens.end(), status) != tokens.end()) {
            response().out() << value;
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

        cppcms::json::value value;
        value[0]["id"] = 1;
        PET_DOGGIE(value[0])
        const std::string & tag = value[0]["tag"][0]["name"].str();
                                                                                                                        std::cerr << "pet::search_pet_by_tag() tag: " << tag << std::endl;
        if (std::find(tokens.begin(), tokens.end(), tag) != tokens.end()) {
            response().out() << value;
        } else {
            response().out() << "[]";
        }
    }

} /* namespace sandbox_cppcms */
