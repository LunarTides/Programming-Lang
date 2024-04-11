#include "lexer.h"
#include "../macros.h"
#include "../util/util.cpp"

#include <cctype>
#include <cstdio>
#include <fstream>
#include <regex>
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
	printf("%s", p_lines.c_str());

	std::vector<Token> tokens;

	// TODO: We should care about what seperator to use in different contexts.
	std::vector<std::string> words = resplit(p_lines, std::regex{ R"(\W+)" });

	for (std::string word : words) {
		Token token = lex_word(word);
		tokens.push_back(token);
	}

	return tokens;
}

Token Lexer::lex_word(std::string p_word) {
	Token token;

	// The token should always use the word as the value, regardless of the token type.
	token.token_value = p_word;

	if (is_number(p_word)) {
		token.token_type = TokenType::NUMBER;

		return token;
	}

	token.token_type = TokenType::IDENTIFIER;

	return token;

	//FAIL_MSG_IF(true, "Invalid token found at '" << p_word << "'", token);
}
