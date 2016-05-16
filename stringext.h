#ifndef stringext_h__
#define stringext_h__

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iomanip>

std::vector<std::string> str_compact(const std::vector<std::string> &tokens);

std::vector<std::string> str_split(const std::string &str, const std::string &delim, const bool trim_empty = false);

std::string str_join(const std::vector<std::string> &tokens, const std::string &delim, const bool trim_empty = false);

std::string str_trim(const std::string &str);

std::string str_repeat(const std::string &str, unsigned int times);

std::string str_toupper(const std::string &str);

std::string str_tolower(const std::string &str);

std::string str_readfile(const std::string &filepath);

bool str_writefile(const std::string &filepath, const std::string &content);

std::string str_replace(const std::string &str, const std::string &strsrc, const std::string &strdst);

std::string str_replaceall(const std::string &source, const std::string &target, const std::string &replacement);

std::string str_between(const std::string &str, const std::string &left, const std::string &right);

std::vector<std::string> str_between_array(const std::string &str, const std::string &left, const std::string &right, const bool trim_empty = false);

std::string str_to_hex(const std::string &str);

std::string str_left(const std::string &str, const std::string &left);

std::string str_right(const std::string &str, const std::string &right);

#endif // stringext_h__
