#ifndef WORDCOUNT_HH
#define WORDCOUNT_HH

#include <algorithm>
#include <regex>
#include <set>
#include <string>
#include <vector>

class WordCount {
   public:
    WordCount();
    const std::vector<std::string> get_tokens(const std::string& input);
    const std::vector<std::string> filter_tokens(
        const std::vector<std::string>& input,
        const std::vector<std::string>& filter);
    const int get_word_count(const std::vector<std::string>& input);
    const int get_word_count_distinct(const std::vector<std::string>& input);

   private:
    const std::string m_pattern;
    const std::vector<std::string> split_string(
        const std::string& stringToSplit, const std::string& regexPattern);
};

#endif
