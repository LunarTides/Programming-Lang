#include "lexer/lexer.cpp"
#include "macros.h"

#include <iostream>
#include <string>

int main(int argc, char **argv) {
	CRASH_MSG_IF(argc < 2, "Not enough arguments.", 1);

	Lexer *lexer = new Lexer();
	std::vector<Token> tokens = lexer->lex_file(argv[1]);

	CRASH_IF(tokens.empty(), 1);

	// Print all of the tokens for debugging.
	// TODO: Remove.
	for (Token &token : tokens) {
		std::cout << "{ " << token.token_type << ", " << token.token_value << " }" << std::endl;
	}

	return 0;
}
