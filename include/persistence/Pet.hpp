#pragma once

#include <hiberlite/hiberlite.h>

#include <string>
#include <vector>

#include "model/Pet.hpp"

namespace sandbox_cppcms {
namespace persistence {

class Pet : public model::Pet {
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive& ar) {
        ar & HIBERLITE_NVP(name);
        ar & HIBERLITE_NVP(photoUrls);
        ar & HIBERLITE_NVP(tags);
//        ar & HIBERLITE_NVP(status);
    }
};

} /* namespace persistence */
} /* namespace sandbox_cppcms */
