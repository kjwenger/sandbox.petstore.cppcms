#include "model/Pet.hpp"

std::ostream & operator<<(std::ostream & os, const sandbox_cppcms::model::Pet & pet) {
    return os << pet.id << ",\"" << pet.name << "\"";
}