#include <iostream>

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

#define FAIL_MSG_IF(cond, msg, return_value)        \
	if (unlikely(cond)) {                           \
		std::cerr << "ERROR: " << msg << std::endl; \
		return return_value;                        \
	}

#define FAIL_IF(cond, return_value)                                             \
	if (unlikely(cond)) {                                                       \
		std::cerr << "ERROR: Condition '" << #cond << "' failed." << std::endl; \
		return return_value;                                                    \
	}

#define CRASH_MSG_IF(cond, msg, error_code)                          \
	if (unlikely(cond)) {                                            \
		std::cerr << "FATAL: " << msg << " Exiting..." << std::endl; \
		exit(error_code);                                            \
	}

#define CRASH_IF(cond, error_code)                                                         \
	if (unlikely(cond)) {                                                                  \
		std::cerr << "FATAL: Condition '" << #cond << "' failed. Exiting..." << std::endl; \
		exit(error_code);                                                                  \
	}
