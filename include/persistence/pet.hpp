#pragma once

#include <hiberlite/hiberlite.h>

#include <string>
#include <vector>

#include "model/pet.hpp"

class pet : public sandbox_cppcms::model::pet {
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive& ar) {
        ar & HIBERLITE_NVP(name);
        ar & HIBERLITE_NVP(photoUrls);
        ar & HIBERLITE_NVP(tags);
    }
public:
    pet();
    pet(const int id,
        const std::string & name,
        const std::vector<std::string> & photoUrls,
        const std::vector<std::string> & tags,
        const sandbox_cppcms::model::pet_status status);
    pet(const sandbox_cppcms::model::pet & origin);
};
