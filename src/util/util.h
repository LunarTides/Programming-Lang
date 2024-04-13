#pragma once

#include "../lexer/lexer.h"

#include <regex>
#include <string>
#include <vector>

namespace util {
bool is_number(const std::string &p_str);
int index_of(std::vector<Token> &p_tokens, Token &p_token);
} //namespace util
