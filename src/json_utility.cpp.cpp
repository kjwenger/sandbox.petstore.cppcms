#include "json_utility.hpp"

namespace sandbox_cppcms {

    cppcms::json::value & json_utility::copy(cppcms::json::value & value, const sandbox_cppcms::model::pet & pet) {
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
    sandbox_cppcms::model::pet & json_utility::copy(sandbox_cppcms::model::pet & pet, const cppcms::json::value & value) {
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

} /* namespace sandbox_cppcms */
