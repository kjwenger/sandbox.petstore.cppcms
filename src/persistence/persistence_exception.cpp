
#include "persistence/persistence_exception.hpp"

namespace sandbox_cppcms {
namespace persistence {

    persistence_exception::persistence_exception(const std::string & what) : std::exception() { }

    persistence_exception::persistence_exception(const char * what) : std::exception() { }

    persistence_exception::persistence_exception(const persistence_exception & origin)
        : std::exception(origin) { }

    const char* persistence_exception::what() const throw() {
        return "Could not load bean";;
    }

} /* namespace persistence */
} /* namespace sandbox_cppcms */
