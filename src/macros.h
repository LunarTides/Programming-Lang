#pragma once

#include <iostream>

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

#define FAIL_MSG_IF(cond, msg, return_value)        				\
	if (unlikely(cond)) {          									\
						/* Red, Bold */								\
		std::cerr << "\n\033[31;1mERROR: " << msg << "\033[0m\n\n"; \
		return return_value;                        				\
	}

#define FAIL_IF(cond, return_value)                                             		  \
	if (unlikely(cond)) {                                                       		  \
					/* Red, Bold */ 													  \
		std::cerr << "\n\033[31;1mERROR: Condition '" << #cond << "' failed.\033[0m\n\n"; \
		return return_value;                                                    		  \
	}

#define CRASH_MSG_IF(cond, msg, error_code)                          			 \
	if (unlikely(cond)) {                                            			 \
					/* Red, Bold, Underline */ 									 \
		std::cerr << "\n\033[31;1;4mFATAL: " << msg << " Exiting...\033[0m\n\n"; \
		exit(error_code);                                            			 \
	}

#define CRASH_IF(cond, error_code)                                                  \
	if (unlikely(cond)) {                                                           \
					/* Red, Bold, Underline */ 										\
		std::cerr << "\n\033[31;1;4mFATAL: Condition '" << #cond << "' failed. Exiting...\033[0m\n\n"; \
		exit(error_code);                                                           \
	}

#ifdef DEBUG_ENABLED
#define PRINT_DEBUG(...) \
	printf(__VA_ARGS__)
#else
#define PRINT_DEBUG(...) \
	{}
#endif
