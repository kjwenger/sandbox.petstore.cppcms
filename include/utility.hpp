#pragma once

#include <ostream>
#include <vector>
#include <string>

std::ostream & operator<<(std::ostream & os, const std::vector<std::basic_string<char, std::char_traits<char>>> & v);
