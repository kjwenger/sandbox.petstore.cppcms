#pragma once

#include <vector>

#include <hiberlite/hiberlite.h>

#include "model/pet.hpp"

namespace sandbox_cppcms {
namespace persistence {

class database {
public:
    database(const std::string & target);
    virtual ~database();

    model::pet create_pet(const model::pet & pet);
    void list_pets(std::vector<model::pet> & pets);
private:
    void init();

    hiberlite::Database db;
};

} /* namespace persistence */
} /* namespace sandbox_cppcms */

extern sandbox_cppcms::persistence::database * service_database;