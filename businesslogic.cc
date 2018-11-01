#include "businesslogic.hh"
#include "stopwords.hh"
#include "wordcount.hh"

Statistics BusinessLogic::run(const std::string& input) {
    Stopwords sw;
    WordCount wc;

    auto tokens     = wc.get_tokens(input);
    auto stop_words = sw.get_stop_words("stopwords.txt");
    auto filtered   = wc.filter_tokens(tokens, stop_words);

    return Statistics(filtered);
}
