#include "token.h"
#include "macros.h"

#include "lexer/lexer.cpp"
#include "parser/parser.cpp"

#include <iostream>
#include <string>

#ifdef DEBUG_ENABLED
#include "test/test.cpp"
#endif


int main(int argc, char *argv[]) {
	CRASH_MSG_IF(argc < 2, "Not enough arguments.", 1);

#ifdef DEBUG_ENABLED
	if (std::string(argv[1]) == "--test") {
		CRASH_MSG_IF(argc < 3, "Not enough arguments. Usage: " << argv[0] << " --test <directory_path>.", 1);

		std::string directory_path = argv[2];

		Test *test_runner = new Test();
		return (int) test_runner->test_all(directory_path);
	}
#endif

	PRINT_DEBUG("[Main] Lexing...\n");

	Lexer *lexer = new Lexer();
	std::vector<Token> tokens = lexer->lex_file(argv[1]);

	CRASH_IF(tokens.empty(), 1);

	PRINT_DEBUG("[Main] Parsing...\n");

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
