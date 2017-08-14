#include <iostream>
#include <sstream>

#include <sqlite3.h>

#include "persistence/database.hpp"
#include "persistence/persistence_exception.hpp"
#include "persistence/pet.hpp"

namespace sandbox_cppcms {
namespace persistence {

    database::database(const std::string & target)
            : db(target + std::string(".db")) {
//        std::cerr << "database::database(\"" << target << "\")" << std::endl;
        sqlite3_config(SQLITE_CONFIG_URI, 0);
        db.registerBeanClass<pet>();
    }

    database::~database() {

    }

    void database::list_pets(std::vector<model::pet> &pets) {
        std::vector<hiberlite::bean_ptr<pet>> allBeans =
                db.getAllBeans<pet>();
        pets.clear();
        for (auto // std::vector<hiberlite::bean_ptr<pet>>::iterator
                iterator = allBeans.begin();
                iterator != allBeans.end();
                iterator ++) {
            hiberlite::bean_ptr<::pet> & pet = *iterator;
            pets.push_back(model::pet{
                    pet->id,
                    pet->name,
                    pet->photoUrls,
                    pet->tags,
                    pet->status
            });
        }
    }

    model::pet database::create_pet(const model::pet & pet) {
        ::pet newPet(pet);
        hiberlite::bean_ptr<::pet> copiedBean = db.copyBean(newPet);
        model::pet returnPet(*copiedBean);
        return returnPet;
    }

    model::pet database::read_pet(int id) {
        hiberlite::bean_ptr<::pet> loadedBean = db.loadBean<::pet>((hiberlite::sqlid_t) id);
        std::cerr << "model::pet database::read_pet(" << id << ") loadedBean.destroyed(): " << loadedBean.destroyed() << std::endl;
        if (loadedBean.destroyed()) {
            std::ostringstream os;
            os << "Could not load bean with id: " << id;
            throw new persistence_exception(os.str());
        }
        std::cerr << "model::pet database::read_pet(" << id << ") *loadedBean: " << *loadedBean << std::endl;
        ::pet newPet;
        model::pet returnPet(*loadedBean);
        return returnPet;
    }

    model::pet database::update_pet(const model::pet & pet) {

    }

    model::pet database::delete_pet(int id) {
        hiberlite::bean_ptr<::pet> loadedBean = db.loadBean<::pet>((hiberlite::sqlid_t) id);
        model::pet returnPet(*loadedBean);
        loadedBean.destroy();
        return returnPet;
    }

    void database::init() {
        db.dropModel();
        db.createModel();
    }

} /* namespace persistence */
} /* namespace sandbox_cppcms */

sandbox_cppcms::persistence::database * service_database = nullptr;