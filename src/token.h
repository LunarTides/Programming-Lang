#pragma once

#include <string>

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

inline bool operator==(Token a, Token b) {
	return (
			a.token_type == b.token_type &&
			a.token_value == b.token_value &&
			a.token_index == b.token_index);
}
