#pragma once

#include <string>
#include <vector>

enum TokenType {
	NUMBER,
	IDENTIFIER,
};

struct Token {
	TokenType token_type;
	std::string token_value;
};

class Lexer {
public:
	std::vector<Token> lex_file(std::string p_file_path);
	std::vector<Token> lex_string(std::string p_lines);
};
