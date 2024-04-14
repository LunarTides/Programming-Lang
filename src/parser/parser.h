#pragma once

#include <vector>

#include "../lexer/lexer.h"

enum ParserError {
	NONE,
};

class Parser {
public:
	ParserError parse_tokens(std::vector<Token> &p_tokens);
	std::vector<Token> get_all_args_in_function(std::vector<Token> &p_tokens, Token &p_token);
};
