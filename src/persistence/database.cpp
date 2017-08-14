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
        std::vector<hiberlite::bean_ptr<pet>> allBeans = db.getAllBeans<pet>();
        pets.clear();
        for (auto // std::vector<hiberlite::bean_ptr<pet>>::iterator
                iterator = allBeans.begin();
                iterator != allBeans.end();
                iterator ++) {
            hiberlite::bean_ptr<::pet> & bean_ptr = *iterator;
            pets.push_back(model::pet(*bean_ptr));
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
//        std::cerr << "model::pet database::read_pet(" << id << ") loadedBean.destroyed(): " << loadedBean.destroyed() << std::endl;
        if (loadedBean.destroyed()) {
            throw new persistence_exception();
        }
//        std::cerr << "model::pet database::read_pet(" << id << ") *loadedBean: " << *loadedBean << std::endl;
        model::pet returnPet(*loadedBean);
        return returnPet;
    }

    model::pet database::update_pet(const model::pet & pet) {
        hiberlite::bean_ptr<::pet> loadedBean = db.loadBean<::pet>((hiberlite::sqlid_t) pet.id);
        std::cerr << "model::pet database::update_pet(" << pet << ") loadedBean.destroyed(): " << loadedBean.destroyed() << std::endl;
        if (loadedBean.destroyed()) {
            throw new persistence_exception();
        }
        loadedBean->name = pet.name;
        loadedBean->photoUrls = pet.photoUrls;
        loadedBean->tags = pet.tags;
        loadedBean->status = pet.status;
        model::pet returnPet(*loadedBean);
        return returnPet;
    }

    model::pet database::delete_pet(int id) {
        hiberlite::bean_ptr<::pet> loadedBean = db.loadBean<::pet>((hiberlite::sqlid_t) id);
        std::cerr << "model::pet database::delete_pet(" << id << ") loadedBean.destroyed(): " << loadedBean.destroyed() << std::endl;
        if (loadedBean.destroyed()) {
            throw new persistence_exception();
        }
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