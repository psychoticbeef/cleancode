#include "dict.hh"
#include <iostream>

Dict::Dict(bool has_dict, std::string filename, bool index)
    : m_dictionary(), m_has_dict(false), m_index(false) {
    m_index = index;
    if (!has_dict) {
        return;
    }
    m_dictionary = Storage::getInstance().get_list(filename);
    if (m_dictionary.size() > 0) {
        m_has_dict = true;
    }
}

void Dict::set_tokens(Type::TokensSet tokens) {
    m_tokens = tokens;
}

std::string Dict::print() {
    std::stringstream ss;
    if (m_has_dict) {
        for (const auto &s : m_tokens) {
            const bool is_in = m_dictionary.find(s) != m_dictionary.end();
            ss << s;
            if (is_in) {
                ss << "*";
            }
            ss << std::endl;
        }
    } else if (m_index) {
        for (const auto &s : m_tokens) {
            ss << s << std::endl;
        }
    }
    return ss.str();
}
