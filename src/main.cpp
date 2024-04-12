#include "lexer/lexer.cpp"
#include "parser/parser.cpp"
#include "macros.h"

#include <iostream>
#include <string>

int main(int argc, char **argv) {
	CRASH_MSG_IF(argc < 2, "Not enough arguments.", 1);

	PRINT_DEBUG("Lexing...\n");

	Lexer *lexer = new Lexer();
	std::vector<Token> tokens = lexer->lex_file(argv[1]);

	CRASH_IF(tokens.empty(), 1);

#ifdef DEBUG_ENABLED
	// Print all of the tokens for debugging.
	// TODO: Remove.
	for (Token &token : tokens) {
		std::cout << "{ " << token.token_type << ", " << token.token_value << " }" << std::endl;
	}

	printf("Parsing...\n");
#endif

	Parser *parser = new Parser();
	ParserError parse_error = parser->parse_tokens(tokens);

	if (parse_error == ParserError::NONE) {
		std::cerr << "\nProgram finished successfully.\n";
		return 0;
	} else {
		std::cerr << "An error occoured when parsing the program.";
		return 1;
	}

	return 0;
}
