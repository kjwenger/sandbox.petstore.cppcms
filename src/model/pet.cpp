#include <iostream>

#include "model/pet.hpp"

namespace sandbox_cppcms {
namespace model {

    pet::pet()
        : id(0)
        , name("")
        , photoUrls({})
        , tags({})
        , status(pet_status::available) { }
    pet::pet(
            const int id,
            const std::string & name,
            const std::vector<std::string> & photoUrls,
            const std::vector<std::string> & tags,
            const model::pet_status status)
        : id(id)
        , name(name)
        , photoUrls(photoUrls)
        , tags(tags)
        , status(status) { }
    pet::pet(const sandbox_cppcms::model::pet & origin)
        : id(origin.id)
        , name(origin.name)
        , photoUrls(origin.photoUrls)
        , tags(origin.tags)
        , status(origin.status) { }

} /* namespace model */
} /* namespace sandbox_cppcms */

const std::string & to_string(const sandbox_cppcms::model::pet_status & pet_status) {
    switch (pet_status) {
        case sandbox_cppcms::model::pet_status::available:
            static std::string available("available");
            return available;
        case sandbox_cppcms::model::pet_status::pending:
            static std::string pending("pending");
            return pending;
        case sandbox_cppcms::model::pet_status::sold:
            static std::string sold("sold");
            return sold;
    }
}

sandbox_cppcms::model::pet_status to_pet_status(const std::string & string) {
                                                                                                                        //std::cerr "to_pet_status(" << string << ")" << std::endl;
    sandbox_cppcms::model::pet_status result;
    if (string == to_string(sandbox_cppcms::model::pet_status::available))
        result = sandbox_cppcms::model::pet_status::available;
    else if (string == to_string(sandbox_cppcms::model::pet_status::pending))
        result = sandbox_cppcms::model::pet_status::pending;
    else if (string == to_string(sandbox_cppcms::model::pet_status::sold))
        result = sandbox_cppcms::model::pet_status::sold;
    else
        result = sandbox_cppcms::model::pet_status::available;
                                                                                                                        //std::cerr "to_pet_status(..) result: " << result << std::endl;
    return result;
}

std::ostream & operator<<(std::ostream & os, const sandbox_cppcms::model::pet_status & pet_status) {
    return os << to_string(pet_status);
}

std::ostream & operator<<(std::ostream & os, const sandbox_cppcms::model::pet & pet) {
    return os << pet.id << ",\"" << pet.name << "\"";
}

cppcms::json::value & operator<<(cppcms::json::value & value, const sandbox_cppcms::model::pet & pet) {
    value["id"] = pet.id;
    value["name"] = pet.name;
    int index = 0;
    for (auto
            iterator = pet.photoUrls.begin();
            iterator != pet.photoUrls.end();
            iterator ++, index ++) {
        value["photoUrls"][index] = *iterator;
    }
    for (auto
            iterator = pet.tags.begin();
            iterator != pet.tags.end();
            iterator ++, index ++) {
        value["tag"][index] = *iterator;
    }
    value["status"] = to_string(pet.status);
    return value;
}

sandbox_cppcms::model::pet & operator<<(sandbox_cppcms::model::pet & pet, const cppcms::json::value & value) {
                                                                                                                        //std::cerr "operator<<(.., " << value << ")" << std::endl;
                                                                                                                        //std::cerr "operator<<(.., ..) value[\"id\"].type(): " << value["id"].type() << std::endl;
    pet.id = value["id"].type() != cppcms::json::is_number ? 0: (int)value["id"].number();
                                                                                                                        //std::cerr "operator<<(.., ..) pet.id: " << pet.id << std::endl;
                                                                                                                        //std::cerr "operator<<(.., ..) value[\"name\"].type(): " << value["name"].type() << std::endl;
    pet.name = value["name"].type() != cppcms::json::is_string ? "" : value["name"].str();
                                                                                                                        //std::cerr "operator<<(.., ..) pet.name: " << pet.name << std::endl;
                                                                                                                        //std::cerr "operator<<(.., ..) value[\"photoUrls\"].type(): " << value["photoUrls"].type() << std::endl;
    if (value["photoUrls"].type() == cppcms::json::is_array) {
        const cppcms::json::array & photoUrls = value["photoUrls"].array();
        for (auto iterator = photoUrls.begin(); iterator != photoUrls.end(); iterator ++) {
            const cppcms::json::value & item = *iterator;
                                                                                                                        //std::cerr "operator<<(.., ..) item.type(): " << item.type() << std::endl;
            const std::string & photoUrl = item.type() != cppcms::json::is_string ? "" : item.str();
                                                                                                                        //std::cerr "operator<<(.., ..) photoUrl: " << photoUrl << std::endl;
            pet.photoUrls.push_back(photoUrl);
        }
    }
                                                                                                                        //std::cerr "operator<<(.., ..) value[\"tag\"].type(): " << value["tag"].type() << std::endl;
    if (value["tag"].type() == cppcms::json::is_array) {
        const cppcms::json::array & tags = value["tag"].array();
        for (auto iterator = tags.begin(); iterator != tags.end(); iterator ++) {
            const cppcms::json::value & item = *iterator;
                                                                                                                        //std::cerr "operator<<(.., ..) item.type(): " << item.type() << std::endl;
            const std::string & tag = item.type() != cppcms::json::is_string ? "" : item.str();
                                                                                                                        //std::cerr "operator<<(.., ..) tag: " << tag << std::endl;
            pet.tags.push_back(tag);
        }
    }
    pet.status = to_pet_status(value["status"].type() != cppcms::json::is_string ? "" : value["status"].str());
                                                                                                                        //std::cerr "operator<<(.., ..) pet.status: " << pet.status << std::endl;
    return pet;
}
