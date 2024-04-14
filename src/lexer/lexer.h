#pragma once

#include "../token.h"

#include <string>
#include <vector>

class Lexer {
public:
	std::vector<Token> lex_file(std::string p_file_path);
	std::vector<Token> lex_lines(std::string p_lines);
	Token lex_word(std::string p_word, size_t p_token_index);
};
