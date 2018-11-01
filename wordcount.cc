#include "wordcount.hh"

WordCount::WordCount() : m_pattern("([^\\w-]+)") {
}

const std::vector<std::string> WordCount::split_string(
    const std::string& stringToSplit, const std::string& regexPattern) {
    std::vector<std::string> result;
    const std::regex rgx(regexPattern);
    std::sregex_token_iterator iter(stringToSplit.begin(), stringToSplit.end(),
                                    rgx, -1);
    for (std::sregex_token_iterator end; iter != end; ++iter) {
        result.push_back(iter->str());
    }
    if (result.size() >= 1 && result.at(0) == "")
        result.erase(result.begin());
    return result;
}

const std::vector<std::string> WordCount::get_tokens(const std::string& input) {
    return split_string(input, m_pattern);
}

const std::vector<std::string> WordCount::filter_tokens(
    const std::vector<std::string>& input,
    const std::set<std::string>& filter) {
    std::vector<std::string> result;
    std::copy_if(input.begin(), input.end(), std::back_inserter(result),
                 [filter](std::string in) {
                     return std::find(filter.begin(), filter.end(), in) ==
                            filter.end();
                 });
    return result;
}
