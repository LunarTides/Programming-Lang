#include "lexer.h"
#include "macros.h"

#include <cstdio>
#include <fstream>
#include <string>
#include <vector>

std::vector<Token> Lexer::lex_file(std::string p_file_path) {
	printf("Lexing file %s...\n", p_file_path.c_str());

	std::string lines;
	std::ifstream file(p_file_path);

	CRASH_MSG_IF(!file.is_open(), "Invalid file.", 1)

	std::string line;
	while (getline(file, line)) {
		lines.append(line + "\n");
	}

	file.close();

	return lex_string(lines);
}

std::vector<Token> Lexer::lex_string(std::string p_lines) {
	// TODO: Implement.
	printf("%s", p_lines.c_str());

	std::vector<Token> tokens;

	Token test_token;
	test_token.token_type = TokenType::IDENTIFIER;
	test_token.token_value = "Hi";
	tokens.push_back(test_token);

	return tokens;
}
