#include "stopwords.hh"

bool Stopwords::file_exists(const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

const std::vector<std::string> Stopwords::get_stop_words(
    const std::string& filename) {
    std::vector<std::string> result;
    if (!file_exists(filename))
        return result;
    std::fstream filter;
    filter.open(filename, std::ios::in);
    std::string line;
    while (getline(filter, line)) {
        result.push_back(line);
    }
    return result;
    filter.close();
}
