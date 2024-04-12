#pragma once

#include <string>
#include <vector>

enum TokenType {
	NUMBER,
	SYMBOL,
	IDENTIFIER,
};

struct Token {
	TokenType token_type;
	std::string token_value;
	int token_index;
};

class Lexer {
public:
	std::vector<Token> lex_file(std::string p_file_path);
	std::vector<Token> lex_string(std::string p_lines);
	Token lex_word(std::string p_word, size_t p_token_index);
};

bool operator==(Token a, Token b);
