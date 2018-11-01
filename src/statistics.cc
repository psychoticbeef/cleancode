#include "statistics.hh"

Statistics::Statistics(Type::Tokens tokens) {
    m_tokens = tokens;
    for (const auto &token : tokens) {
        m_tokens_unique.insert(token);
    }
}

size_t Statistics::get_token_count() {
    return m_tokens.size();
}

size_t Statistics::get_token_count_unique() {
    return m_tokens_unique.size();
}

float Statistics::get_average_word_length(Type::Tokens t) {
    size_t result = std::accumulate(
        t.begin(), t.end(), 0,
        [](size_t sum, const std::string& elem) { return sum + elem.size(); });
    if (t.size() == 0) {
        return std::numeric_limits<float>::quiet_NaN();
    }
    return result / t.size();
}

std::string Statistics::print() {
    std::stringstream ss;
    ss << "Number of words: " << get_token_count()
       << ", unique: " << get_token_count_unique()
       << "; average word length: " << get_average_word_length(m_tokens);

    return ss.str();
}

Type::TokensSet Statistics::get_unique() {
    return m_tokens_unique;
}
