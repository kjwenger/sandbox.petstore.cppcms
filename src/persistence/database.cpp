#include <iostream>
#include <sstream>

#include <sqlite3.h>

#include "persistence/database.hpp"
#include "persistence/persistence_exception.hpp"
#include "persistence/pet.hpp"
#include "persistence/user.hpp"

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

    template <class T, class C>
    void database::list(std::vector<T> &pets) {
        std::vector<hiberlite::bean_ptr<pet>> allBeans = db.getAllBeans<C>();
        pets.clear();
        for (auto // std::vector<hiberlite::bean_ptr<C>>::iterator
                iterator = allBeans.begin();
                iterator != allBeans.end();
                iterator ++) {
            hiberlite::bean_ptr<C> & bean_ptr = *iterator;
            pets.push_back(T(*bean_ptr));
        }
    }

    template <class T, class C>
    T database::create(const T & pet) {
        C newPet(pet);
        hiberlite::bean_ptr<C> copiedBean = db.copyBean(newPet);
        T returnPet(*copiedBean);
        return returnPet;
    }

    template <class T, class C>
    T database::read(int id) {
        hiberlite::bean_ptr<C> loadedBean = db.loadBean<C>((hiberlite::sqlid_t) id);
//        std::cerr << "T database::read(" << id << ") loadedBean.destroyed(): " << loadedBean.destroyed() << std::endl;
        if (loadedBean.destroyed()) {
            throw new persistence_exception();
        }
//        std::cerr << "T database::read(" << id << ") *loadedBean: " << *loadedBean << std::endl;
        T returnPet(*loadedBean);
        return returnPet;
    }

    template <class T, class C>
    T database::update(const T & pet) {
        hiberlite::bean_ptr<C> loadedBean = db.loadBean<C>((hiberlite::sqlid_t) pet.id);
//        std::cerr << "T database::update(" << pet << ") loadedBean.destroyed(): " << loadedBean.destroyed() << std::endl;
        if (loadedBean.destroyed()) {
            throw new persistence_exception();
        }
        T returnPet(*loadedBean);
        return returnPet;
    }

    template <class T, class C>
    T database::delet(int id) {
        hiberlite::bean_ptr<C> loadedBean = db.loadBean<C>((hiberlite::sqlid_t) id);
//        std::cerr << "T database::delete(" << id << ") loadedBean.destroyed(): " << loadedBean.destroyed() << std::endl;
        if (loadedBean.destroyed()) {
            throw new persistence_exception();
        }
        T returnPet(*loadedBean);
        loadedBean.destroy();
        return returnPet;
    }

    void database::init() {
        db.dropModel();
        db.createModel();
    }

    template <>
    model::pet database::update<model::pet, ::pet>(const model::pet & pet) {
        hiberlite::bean_ptr<::pet> loadedBean = db.loadBean<::pet>((hiberlite::sqlid_t) pet.id);
//        std::cerr << "model::pet database::update(" << pet << ") loadedBean.destroyed(): " << loadedBean.destroyed() << std::endl;
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
    template <>
    model::user database::update<model::user, ::user>(const model::user & user) {
        hiberlite::bean_ptr<::user> loadedBean = db.loadBean<::user>((hiberlite::sqlid_t) user.id);
//        std::cerr << "model::user database::update(" << user << ") loadedBean.destroyed(): " << loadedBean.destroyed() << std::endl;
        if (loadedBean.destroyed()) {
            throw new persistence_exception();
        }
        loadedBean->username = user.username;
        loadedBean->firstName = user.firstName;
        loadedBean->lastName = user.lastName;
        loadedBean->email = user. email;
        loadedBean->password = user.password;
        loadedBean->phone = user.phone;
        loadedBean->userStatus = user.userStatus;
        model::user returnPet(*loadedBean);
        return returnPet;
    }

    template model::pet database::create<model::pet, ::pet>(const model::pet & pet);
    template model::pet database::read<model::pet, ::pet>(int id);
    template model::pet database::update<model::pet, ::pet>(const model::pet & pet);
    template model::pet database::delet<model::pet, ::pet>(int id);
    template void database::list<model::pet, ::pet>(std::vector<model::pet> & pets);

} /* namespace persistence */
} /* namespace sandbox_cppcms */

sandbox_cppcms::persistence::database * service_database = nullptr;