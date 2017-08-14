#include <iostream>

#include "persistence/pet.hpp"

pet::pet() : sandbox_cppcms::model::pet() { }

pet::pet(
        const int id,
        const std::string & name,
        const std::vector<std::string> & photoUrls,
        const std::vector<std::string> & tags,
        const sandbox_cppcms::model::pet_status status)
    : sandbox_cppcms::model::pet(id, name, photoUrls, tags, status) { }

pet::pet(const sandbox_cppcms::model::pet & origin)
    : sandbox_cppcms::model::pet(origin) { }

HIBERLITE_EXPORT_CLASS(pet)
