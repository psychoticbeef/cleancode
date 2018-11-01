#ifndef WORDCOUNT_HH
#define WORDCOUNT_HH

#include <algorithm>
#include <regex>
#include <set>
#include <string>
#include <vector>
#include "type.hh"

class WordCount {
   public:
    WordCount();
    const Type::Tokens get_tokens(const std::string& input);
    const Type::Tokens filter_tokens(const Type::Tokens& input,
                                     const Type::TokensSet& filter);

   private:
    const std::string m_pattern;
    const Type::Tokens split_string(const std::string& stringToSplit,
                                    const std::string& regexPattern);
};

#endif
