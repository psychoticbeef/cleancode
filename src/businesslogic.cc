#include "businesslogic.hh"

Statistics BusinessLogic::run(const std::string& input) {
    WordCount wc;

    auto tokens     = wc.get_tokens(input);
    auto stop_words = Storage::getInstance().get_list("stopwords.txt");
    auto filtered   = wc.filter_tokens(tokens, stop_words);
    auto statistics = Statistics(filtered);

    return statistics;
}
