#include <iostream>
#include <iterator>

#include "utility.hpp"

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
    bool pet::operator==(const pet & that) const {
        return &that == this ||
                that.id == this->id ||
                that.name == this->name ||
                that.photoUrls == this->photoUrls ||
                that.tags == this->tags ||
                that.status == this->status;
    }

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
                                                                                                                        std::cerr << "to_pet_status(" << string << ")" << std::endl;
    sandbox_cppcms::model::pet_status result;
    if (string == to_string(sandbox_cppcms::model::pet_status::available))
        result = sandbox_cppcms::model::pet_status::available;
    else if (string == to_string(sandbox_cppcms::model::pet_status::pending))
        result = sandbox_cppcms::model::pet_status::pending;
    else if (string == to_string(sandbox_cppcms::model::pet_status::sold))
        result = sandbox_cppcms::model::pet_status::sold;
    else
        result = sandbox_cppcms::model::pet_status::available;
                                                                                                                        std::cerr << "to_pet_status(...) result: " << result << std::endl;
    return result;
}

std::ostream & operator<<(std::ostream & os, const sandbox_cppcms::model::pet_status & pet_status) {
    return os << to_string(pet_status);
}

std::ostream & operator<<(std::ostream & os, const sandbox_cppcms::model::pet & pet) {
    return os << pet.id << ","
              << pet.name << ",["
              << pet.photoUrls << "],["
              << pet.tags << "],"
              << pet.status;
}

std::ostream & operator<<(std::ostream & os, const std::vector<sandbox_cppcms::model::pet> & pets) {
//    std::copy(pets.begin(), pets.end(), std::ostream_iterator<sandbox_cppcms::model::pet>(os, ";"));
    for (auto iterator = pets.begin(); iterator != pets.end(); iterator ++) {
        if (iterator != pets.begin()) os << ";";
        os << *iterator;
    }
    return os;
}
