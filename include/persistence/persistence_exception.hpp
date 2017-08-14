#pragma once

#include <string>
#include <exception>

namespace sandbox_cppcms {
namespace persistence {

    class database;

    class persistence_exception : public std::exception {
        friend class database;
    private:
        persistence_exception(const std::string & what);
        persistence_exception(const persistence_exception & origin);
    };

} /* namespace persistence */
} /* namespace sandbox_cppcms */
