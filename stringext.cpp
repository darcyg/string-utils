#include "stringext.h"

std::vector<std::string> str_compact(const std::vector<std::string> &tokens) {
	std::vector<std::string> compacted;

	for (size_t i = 0; i < tokens.size(); ++i) {
		if (!tokens[i].empty()) {
			compacted.push_back(tokens[i]);
		}
	}

	return compacted;
}

std::vector<std::string> str_split(const std::string &str, const std::string &delim, const bool trim_empty) {
	size_t pos, last_pos = 0, len;
	std::vector<std::string> tokens;

	while (true) {
		pos = str.find(delim, last_pos);
		if (pos == std::string::npos) {
			pos = str.size();
		}

		len = pos - last_pos;
		if (!trim_empty || len != 0) {
			tokens.push_back(str.substr(last_pos, len));
		}

		if (pos == str.size()) {
			break;
		}
		else {
			last_pos = pos + delim.size();
		}
	}

	return tokens;
}

std::string str_join(const std::vector<std::string> &tokens, const std::string &delim, const bool trim_empty) {
	if (trim_empty) {
		return str_join(str_compact(tokens), delim, false);
	}
	else {
		std::stringstream ss;
		for (size_t i = 0; i < tokens.size() - 1; ++i) {
			ss << tokens[i] << delim;
		}
		ss << tokens[tokens.size() - 1];

		return ss.str();
	}
}

std::string str_trim(const std::string &str) {

	std::string blank = "\r\n\t ";
	size_t begin = str.size(), end = 0;
	for (size_t i = 0; i < str.size(); ++i) {
		if (blank.find(str[i]) == std::string::npos) {
			begin = i;
			break;
		}
	}

	for (size_t i = str.size(); i > 0; --i) {
		if (blank.find(str[i - 1]) == std::string::npos) {
			end = i - 1;
			break;
		}
	}

	if (begin >= end) {
		return "";
	}
	else {
		return str.substr(begin, end - begin + 1);
	}
}

std::string str_repeat(const std::string &str, unsigned int times) {
	std::stringstream ss;
	for (unsigned int i = 0; i < times; ++i) {
		ss << str;
	}
	return ss.str();
}

std::string str_toupper(const std::string &str) {
	std::string s(str);
	std::transform(s.begin(), s.end(), s.begin(), toupper);
	return s;
}

std::string str_tolower(const std::string &str) {
	std::string s(str);
	std::transform(s.begin(), s.end(), s.begin(), tolower);
	return s;
}

std::string str_readfile(const std::string &filepath) {
	std::ifstream ifs(filepath.c_str());
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
	ifs.close();
	return content;
}

bool str_writefile(const std::string &filepath, const std::string &content) {
	std::ofstream examplefile(filepath.c_str());
	if (examplefile.is_open()) {
		examplefile << content;
		examplefile.close();
		return true;
	}
	return false;
}

std::string str_replace(const std::string &str, const std::string &strsrc, const std::string &strdst)
{
	std::string s(str);
	std::string::size_type pos = 0;
	std::string::size_type srclen = strsrc.size();
	std::string::size_type dstlen = strdst.size();
	while ((pos = s.find(strsrc, pos)) != std::string::npos)
	{
		s.replace(pos, srclen, strdst);
		pos += dstlen;
	}
	return s;
}

std::string str_replaceall(const std::string &source, const std::string &target, const std::string &replacement) {
	return str_join(str_split(source, target, false), replacement, false);
}

std::string str_between(const std::string &str, const std::string &left, const std::string &right) {
	size_t left_pos, right_pos, last_pos = 0;
	left_pos = str.find(left, last_pos);
	if (left_pos == std::string::npos)
		return "";
	last_pos = left_pos + left.size();
	right_pos = str.find(right, last_pos);
	if (right_pos == std::string::npos)
		return "";
	return str.substr(left_pos + left.size(), right_pos - left_pos - left.size());
}

std::vector<std::string> str_between_array(const std::string &str, const std::string &left, const std::string &right, const bool trim_empty) {
	size_t left_pos, right_pos, last_pos = 0, len;
	std::vector<std::string> result;
	while (true) {
		left_pos = str.find(left, last_pos);
		if (left_pos == std::string::npos) {
			break;
		}
		else
		{
			last_pos = left_pos + left.size();
			right_pos = str.find(right, last_pos);
			if (right_pos == std::string::npos) {
				break;
			}
			len = right_pos - left_pos - left.size();
			if (len != 0 || !trim_empty)
			{
				result.push_back(str.substr(last_pos, len));
			}
		}
		last_pos = right_pos + right.size();
	}
	return result;
}

std::string str_to_hex(const std::string &str)
{
	std::ostringstream oss;
	oss << std::hex;
	oss << std::setfill('0');
	oss << std::uppercase;//ด๓ะด
	for (size_t i = 0; i < str.length(); i++)
	{
		unsigned char c = str[i];
		oss << "0x" << std::setw(2) << (unsigned int)c;
		if (i < (str.length() - 1))
			oss << ' ';
	}
	return oss.str();
}

std::string str_left(const std::string &str, const std::string &left)
{
	std::string s(str);
	size_t pos, last_pos = 0;
	pos = s.find(left, last_pos);
	if (pos != std::string::npos)
		return s.substr(0, pos);
	else
		return "";
}

std::string str_right(const std::string &str, const std::string &right)
{
	std::string s(str);
	size_t pos, last_pos = 0;
	pos = s.find(right, last_pos);
	if (pos != std::string::npos)
	{
		pos += right.length();
		return s.substr(pos, str.length() - pos);
	}		
	else
		return "";
}
