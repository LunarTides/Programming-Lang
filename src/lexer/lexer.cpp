#include "lexer.h"
#include "../macros.h"
#include "../util/util.cpp"

#include <fstream>
#include <regex>
#include <string>
#include <vector>

bool operator==(Token a, Token b) {
	return (
			a.token_type == b.token_type &&
			a.token_value == b.token_value &&
			a.token_index == b.token_index);
}

std::vector<Token> Lexer::lex_file(std::string p_file_path) {
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
	PRINT_DEBUG("%s", p_lines.c_str());

	std::vector<Token> tokens;
	std::vector<std::string> words;

	std::string current_word;

	for (char &c : p_lines) {
		if (std::regex_match(&c, std::regex{ R"([\W]+)" }) || c == '(' || c == ')') {
			PRINT_DEBUG("Regex char: %c.\n", c);

			words.push_back(current_word);
			words.push_back(std::string(1, c));

			current_word.clear();
			continue;
		}

		PRINT_DEBUG("Normal char: %c, ", c);
		current_word.push_back(c);
	}

	for (std::string word : words) {
		Token token = lex_word(word, tokens.size());
		tokens.push_back(token);
	}

	return tokens;
}

Token Lexer::lex_word(std::string p_word, size_t p_token_index) {
	Token token;

	// The token should always use the word as the value, regardless of the token type.
	token.token_value = p_word;
	token.token_index = p_token_index;

	// TODO: Add strings.
	if (is_number(p_word)) {
		token.token_type = TokenType::NUMBER;
	} else if (std::regex_match(p_word, std::regex{ R"(\W+)" })) {
		token.token_type = TokenType::SYMBOL;
	} else {
		token.token_type = TokenType::IDENTIFIER;
	}

	return token;

	//FAIL_MSG_IF(true, "Invalid token found at '" << p_word << "'", token);
}
