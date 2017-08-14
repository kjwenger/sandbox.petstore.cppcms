#include <string>
#include <vector>
#include <iostream>
#include <hiberlite/hiberlite.h>

using namespace std;
using namespace hiberlite;

//namespace domain { // namespaces don't work in bean classes
    class person {
        friend class hiberlite::access;

        template<class Archive>
        void hibernate(Archive &ar) {
            ar & HIBERLITE_NVP(name);
            ar & HIBERLITE_NVP(age);
            ar & HIBERLITE_NVP(bio);
        }

    public:
        string name;
        double age;
        vector<string> bio;
    };
//}
HIBERLITE_EXPORT_CLASS(person)
//HIBERLITE_EXPORT_CLASS(domain::person)

int main(int argc, char* argv[]) {
    std::cerr << "main()" << std::endl;
    Database db("sqlite3.db");
    db.registerBeanClass<person>();
//    db.registerBeanClass<domain::person>();
    db.dropModel();
    db.createModel();
    person x;
    x.name="Amanda";
    x.age=21;
    x.bio.push_back("born 1987");
    hiberlite::bean_ptr<person> p = db.copyBean(x);
    std::cerr << "main() p->name:" << p->name << std::endl;
    std::cerr << "main() p->age:" << p->age << std::endl;
    return 0;
}
