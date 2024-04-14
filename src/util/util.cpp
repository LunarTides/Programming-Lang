#include "util.h"

#include "../token.h"

namespace util {
bool is_number(const std::string &p_str) {
	char *p;
	strtol(p_str.c_str(), &p, 10);
	return *p == 0;
}

int index_of(std::vector<Token> &p_tokens, Token &p_token) {
	auto it = std::find(p_tokens.begin(), p_tokens.end(), p_token);

	if (it != p_tokens.end()) {
		return it - p_tokens.begin();
	} else {
		return -1;
	}
}
} //namespace util
