#include "test.h"

#include "../lexer/lexer.h"
#include "../macros.h"
#include "../parser/parser.h"

#include <filesystem>
#include <iostream>
#include <string>

bool Test::test_all(std::string p_directory_path) {
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();

	for (const std::filesystem::__cxx11::directory_entry &file : std::filesystem::recursive_directory_iterator(p_directory_path)) {
		if (file.path().extension().string() == "milo") {
			// Lex.
			PRINT_DEBUG("[Test] Lexing %s...\n", file.path().filename().c_str());
			std::vector<Token> tokens = lexer->lex_file(file.path().string());

			FAIL_MSG_IF(tokens.empty(), "[Test] Lexing failed. No tokens found.", false);

			// Parse.
			PRINT_DEBUG("[Test] Parsing %s...\n", file.path().filename().c_str());
			ParserError parse_error = parser->parse_tokens(tokens);

			FAIL_MSG_IF(parse_error != ParserError::NONE, "[Test] Parsing failed.", false);
		}
	}

	std::cout << "[Test] OK.\n"
			  << std::endl;
	return true;
}
