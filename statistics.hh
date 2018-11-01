#ifndef STATISTICS_HH
#define STATISTICS_HH

#include <numeric>
#include <sstream>
#include "iprintable.hh"
#include "type.hh"

class Statistics : public IPrintable {
   private:
    Statistics();
    Type::Tokens m_tokens;
    Type::TokensSet m_tokens_unique;

   public:
    Statistics(Type::Tokens tokens);
    size_t get_token_count();
    size_t get_token_count_unique();
    float get_average_word_length(Type::Tokens t);
    std::string print() override;
};

#endif
