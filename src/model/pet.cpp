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

std::ostream & operator<<(std::ostream & os, const sandbox_cppcms::model::pet & pet) {
    return os << pet.id << ",\"" << pet.name << "\"";
}