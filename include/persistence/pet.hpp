#pragma once

#include <hiberlite/hiberlite.h>

#include <string>
#include <vector>

#include "model/pet.hpp"

enum class pet_status {
    available,
    pending,
    sold
};

class pet : public sandbox_cppcms::model::pet {
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive& ar) {
        ar & HIBERLITE_NVP(name);
//        ar & HIBERLITE_NVP(category);
        ar & HIBERLITE_NVP(photoUrls);
        ar & HIBERLITE_NVP(tags);
//        ar & HIBERLITE_NVP(status);
    }
};
