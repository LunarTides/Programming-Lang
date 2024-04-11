#pragma once

#include <regex>
#include <string>
#include <vector>

std::vector<std::string> resplit(const std::string &p_str, const std::regex &p_seperation_regex);
bool is_number(const std::string &p_str);
