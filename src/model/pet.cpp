#include "model/pet.hpp"

std::ostream & operator<<(std::ostream & os, const sandbox_cppcms::model::pet & pet) {
    return os << pet.id << ",\"" << pet.name << "\"";
}