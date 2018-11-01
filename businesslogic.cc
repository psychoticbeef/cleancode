#include "businesslogic.hh"
#include "stopwords.hh"
#include "wordcount.hh"

std::pair<int, int> BusinessLogic::run(const std::string& input) {
    Stopwords sw;
    WordCount wc;

    auto tokens         = wc.get_tokens(input);
    auto stop_words     = sw.get_stop_words("stopwords.txt");
    auto filtered       = wc.filter_tokens(tokens, stop_words);
    auto count          = wc.get_word_count(filtered);
    auto count_distinct = wc.get_word_count_distinct(filtered);
    return std::make_pair(count, count_distinct);
}
