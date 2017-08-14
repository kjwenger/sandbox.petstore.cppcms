#include <iostream>

#include <sqlite3.h>

#include "persistence/database.hpp"

#include "persistence/pet.hpp"

namespace sandbox_cppcms {
namespace persistence {

database::database(const std::string & target)
        : db(target + std::string(".db")) {
    std::cerr << "database::database(\"" << target << "\")" << std::endl;
    sqlite3_config(SQLITE_CONFIG_URI, 0);
    db.registerBeanClass<pet>();
}

database::~database() {

}

void database::list_pets(std::vector<model::pet> &pets) {
    std::vector<hiberlite::bean_ptr<pet>> allBeans =
            db.getAllBeans<pet>();
    pets.clear();
    for (std::vector<hiberlite::bean_ptr<pet>>::iterator
            iterator = allBeans.begin();
            iterator != allBeans.end();
            iterator ++) {
        hiberlite::bean_ptr<pet> & pet = *iterator;
        pets.push_back(model::pet{
                pet->id,
                pet->name,
                pet->photoUrls,
                pet->tags
        });
    }
}

model::pet database::create_pet(const model::pet & pet) {
    ::pet newPet;
    newPet.id = pet.id;
    newPet.name = pet.name;
    newPet.photoUrls = pet.photoUrls;
    newPet.tags = pet.tags;
    hiberlite::bean_ptr<::pet> copiedBean = db.copyBean(newPet);
    newPet.id = copiedBean->id;
    newPet.name = copiedBean->name;
    newPet.photoUrls = copiedBean->photoUrls;
    newPet.tags = copiedBean->tags;
    return newPet;
}

void database::init() {
    db.dropModel();
    db.createModel();
}

} /* namespace persistence */
} /* namespace sandbox_cppcms */

sandbox_cppcms::persistence::database * service_database = nullptr;