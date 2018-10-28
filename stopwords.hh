#ifndef STOPWORDS_H
#define STOPWORDS_H

#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

class Stopwords {
public:
	std::string read_input();
	void output(int count, int count_distinct);
	bool file_exists(const std::string& name);
	const std::vector<std::string> get_stop_words(const std::string& filename);
	const std::vector<std::string> split_string(const std::string& stringToSplit, const std::string& regexPattern);
	const std::vector<std::string> get_tokens(const std::string& input);
	const std::vector<std::string> filter_tokens(const std::vector<std::string>& input, const std::vector<std::string>& filter);
	const int get_word_count(const std::vector<std::string>& input);
	const int get_word_count_distinct(const std::vector<std::string>& input);
	const std::pair<int, int> run(const std::string& input);
};

#endif
