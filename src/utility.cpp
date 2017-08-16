#pragma once

#include <iterator>

#include "utility.hpp"

std::ostream & operator<<(std::ostream & os, const std::vector<std::string> & v) {
    std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(os, ","));
    return os;
}
