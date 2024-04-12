#include "parser.h"
#include "../macros.h"

#include <algorithm>
#include <vector>

ParserError Parser::parse_tokens(std::vector<Token> &p_tokens) {
	for (Token token : p_tokens) {
		PRINT_DEBUG("Token: %d %s", token.token_type, token.token_value.c_str());

		// TODO: Don't hardcode this.
		if (token.token_type == TokenType::IDENTIFIER) {
			CRASH_MSG_IF(token.token_value != "print", "Only the `print` function is currently implemented. Strings are also not supported, and will generate this error.", 1);

			// TODO: Call functions from the inner-most scope, outwards.
			std::vector<Token> args = get_all_in_function(p_tokens, token);

			for (Token arg : args) {
				printf("%s", arg.token_value.c_str());
			}
		}
	}

	return ParserError::NONE;
}

std::vector<Token> get_all_in_function(std::vector<Token> &p_tokens, Token &p_token) {
	std::vector<Token> tokens;

	int position = index_of(p_tokens, p_token);

	CRASH_MSG_IF(position == -1, "Token cannot be found in the list of tokens. (BUG)", 1);

	int token_scope;
	int scope = 0;

	for (int i = 0; i < p_tokens.size(); i++) {
		Token token = p_tokens[i];

		if (token.token_type == TokenType::SYMBOL) {
			if (token.token_value == "(") {
				scope++;
			} else if (token.token_value == ")") {
				scope--;
			}
		}

		if (token == p_token) {
			token_scope = scope;
		}

		if (i > position + 1) {
			// This token is after the function call.
			if (
					token.token_type == TokenType::SYMBOL &&
					token.token_value == ")" &&
					scope == token_scope) {
				return tokens;
			}

			tokens.push_back(token);
		}
	}

	FAIL_MSG_IF(true, "Unclosed parentheses.", tokens);
}

int index_of(std::vector<Token> &p_tokens, Token &p_token) {
	auto it = std::find(p_tokens.begin(), p_tokens.end(), p_token);

	if (it != p_tokens.end()) {
		return it - p_tokens.begin();
	} else {
		return -1;
	}
}
