#include "util.h"
#include <cstdio>
#include <regex>

// https://stackoverflow.com/a/28142357
std::vector<std::string> resplit(const std::string &p_str, const std::regex &p_seperation_regex) {
	std::sregex_token_iterator iter(p_str.begin(), p_str.end(), p_seperation_regex, -1);
	std::sregex_token_iterator end;
	return { iter, end };
}

bool is_number(const std::string &p_str) {
	char *p;
	strtol(p_str.c_str(), &p, 10);
	return *p == 0;
}
