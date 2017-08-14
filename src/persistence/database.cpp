#include <iostream>

#include "persistence/database.hpp"

#include "persistence/Pet.hpp"

namespace sandbox_cppcms {
namespace persistence {

database::database(const std::string & target)
        : db(target + std::string(".db")) {
    std::cerr << "database::database(\"" << target << "\")" << std::endl;
    db.registerBeanClass<persistence::Pet>();
}

database::~database() {

}

void database::list_pets(std::vector<model::Pet> &pets) {
    std::vector<hiberlite::bean_ptr<persistence::Pet>> allBeans =
            db.getAllBeans<persistence::Pet>();
//    pets.clear();
//    for (std::vector<hiberlite::bean_ptr<persistence::Pet>>::iterator
//            iterator = allBeans.begin();
//            iterator != allBeans.end();
//            iterator ++) {
//        hiberlite::bean_ptr<persistence::Pet> & pet = *iterator;
//        pets.push_back(model::Pet{
//                pet->id,
//                pet->name
////                pet->photoUrls,
////                pet->tags
//        });
//    }
}

model::Pet database::create_pet(const model::Pet & pet) {
    persistence::Pet newPet;
    newPet.id = pet.id;
    newPet.name = pet.name;
//    newPet.photoUrls = pet.photoUrls;
//    newPet.tags = pet.tags;
    hiberlite::bean_ptr<persistence::Pet> copiedBean = db.copyBean(newPet);
    newPet.id = copiedBean->id;
    newPet.name = copiedBean->name;
//    newPet.photoUrls = copiedBean->photoUrls;
//    newPet.tags = copiedBean->tags;
    return newPet;
}

void database::init() {
    db.dropModel();
    db.createModel();
}

} /* namespace persistence */
} /* namespace sandbox_cppcms */

sandbox_cppcms::persistence::database * service_database = nullptr;