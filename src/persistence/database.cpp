#include "persistence/database.hpp"

#include "persistence/Pet.hpp"

namespace sandbox_cppcms {
namespace persistence {

database::database(const std::string & target)
        : db(target + std::string(".db")) {
    db.registerBeanClass<persistence::Pet>();
}

database::~database() {

}

void database::list_pets(std::vector<model::Pet> &pets) {
    std::vector<hiberlite::bean_ptr<persistence::Pet>> allBeans =
            db.getAllBeans<persistence::Pet>();
    pets.clear();
    for (std::vector<hiberlite::bean_ptr<persistence::Pet>>::const_iterator
            iterator = allBeans.begin();
            iterator != allBeans.end();
            iterator ++) {
        const hiberlite::bean_ptr<persistence::Pet> & pet = *iterator;
//        pets.push_back(model::Pet{*pet->id});
    }
}

//Pet & database::createPet(const Pet const & pet) {
//    hiberlite::bean_ptr<sandbox_cppcms::Pet> copiedBean = db.copyBean(pet);
//    *copiedBean;
//}

void database::init() {
    db.dropModel();
    db.createModel();
}

} /* namespace persistence */
} /* namespace sandbox_cppcms */

extern sandbox_cppcms::persistence::database * service_database = nullptr;