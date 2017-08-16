#include "json_utility.hpp"

namespace sandbox_cppcms {
    const std::string json_utility::id("id");
    const std::string json_utility::name("name");
    const std::string json_utility::photoUrls("photoUrls");
    const std::string json_utility::tag("tag");
    const std::string json_utility::status("status");

    const std::vector<std::string> json_utility::pet_properties{
            json_utility::id,
            json_utility::name,
            json_utility::photoUrls,
            json_utility::tag,
            json_utility::status
    };
    const std::vector<std::string> json_utility::pet_list_properties{
            json_utility::id,
            json_utility::name
    };

    bool json_utility::is_property(const std::string & property, const std::vector<std::string> & properties) {
        std::find(properties.begin(), properties.end(), property) != properties.end();
    }

    cppcms::json::value & json_utility::copy(
            const sandbox_cppcms::model::pet & pet,
            cppcms::json::value & value,
            const std::vector<std::string> & properties) {
        if (is_property(id, properties)) value[id] = pet.id;
        if (is_property(name, properties)) value[name] = pet.name;
        int index = 0;
        if (is_property(photoUrls, properties)) for (
                    auto iterator = pet.photoUrls.begin(); iterator != pet.photoUrls.end(); iterator ++, index ++) {
            value[photoUrls][index] = *iterator;
        }
        if (is_property(tag, properties)) for (
                    auto iterator = pet.tags.begin(); iterator != pet.tags.end(); iterator ++, index ++) {
            value[tag][index] = *iterator;
        }
        if (is_property(status, properties)) value[status] = to_string(pet.status);
        return value;
    }

    cppcms::json::value & json_utility::copy(
            const std::vector<sandbox_cppcms::model::pet> & pets,
            cppcms::json::value & value,
            const std::vector<std::string> & properties) {

        int index = 0;
        for (auto iterator = pets.begin(); iterator != pets.end(); iterator ++, index ++) {
            json_utility::copy(*iterator, value[index], pet_list_properties);
        }
    }

    sandbox_cppcms::model::pet & json_utility::copy(
            const cppcms::json::value & value,
            sandbox_cppcms::model::pet & pet) {
                                                                                                                        std::cerr << "operator<<(.., " << value << ")" << std::endl;
                                                                                                                        std::cerr << "operator<<(.., ..) value[\"id\"].type(): " << value[id].type() << std::endl;
    pet.id = value[id].type() != cppcms::json::is_number ? 0: (int)value[id].number();
                                                                                                                        std::cerr << "operator<<(.., ..) pet.id: " << pet.id << std::endl;
                                                                                                                        std::cerr << "operator<<(.., ..) value[\"name\"].type(): " << value[name].type() << std::endl;
    pet.name = value[name].type() != cppcms::json::is_string ? "" : value[name].str();
                                                                                                                        std::cerr << "operator<<(.., ..) pet.name: " << pet.name << std::endl;
                                                                                                                        std::cerr << "operator<<(.., ..) value[\"photoUrls\"].type(): " << value[photoUrls].type() << std::endl;
        if (value[photoUrls].type() == cppcms::json::is_array) {
            const cppcms::json::array & photoUrls = value[json_utility::photoUrls].array();
            for (auto iterator = photoUrls.begin(); iterator != photoUrls.end(); iterator ++) {
                const cppcms::json::value & item = *iterator;
                                                                                                                        std::cerr << "operator<<(.., ..) item.type(): " << item.type() << std::endl;
                const std::string & photoUrl = item.type() != cppcms::json::is_string ? "" : item.str();
                                                                                                                        std::cerr << "operator<<(.., ..) photoUrl: " << photoUrl << std::endl;
                pet.photoUrls.push_back(photoUrl);
            }
        }
                                                                                                                        std::cerr << "operator<<(.., ..) value[\"tag\"].type(): " << value[tag].type() << std::endl;
        if (value[tag].type() == cppcms::json::is_array) {
            const cppcms::json::array & tags = value[tag].array();
            for (auto iterator = tags.begin(); iterator != tags.end(); iterator ++) {
                const cppcms::json::value & item = *iterator;
                                                                                                                        std::cerr << "operator<<(.., ..) item.type(): " << item.type() << std::endl;
                const std::string & tag = item.type() != cppcms::json::is_string ? "" : item.str();
                                                                                                                        std::cerr << "operator<<(.., ..) tag: " << tag << std::endl;
                pet.tags.push_back(tag);
            }
        }
        pet.status = to_pet_status(value[status].type() != cppcms::json::is_string ? "" : value[status].str());
                                                                                                                        std::cerr << "operator<<(.., ..) pet.status: " << pet.status << std::endl;
        return pet;
    }

} /* namespace sandbox_cppcms */
