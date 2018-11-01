#include "storage.hh"

bool Storage::file_exists(const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

const std::set<std::string> Storage::get_list(
    const std::string& filename) {
    std::set<std::string> result;
    if (!file_exists(filename))
        return result;
    // TODO: check file readability
    std::fstream filter;
    filter.open(filename, std::ios::in);
    std::string line;
    while (getline(filter, line)) {
        result.insert(line);
    }
    filter.close();
    return result;
}
