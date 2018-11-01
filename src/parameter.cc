#include "parameter.hh"

Parameter::Parameter(int argc, char* argv[])
    : m_has_file(false),
      m_use_dict(false),
      m_print_index(false),
      m_filename(),
      m_dict() {
    if (argc < 2) {
        return;
    }

    char const* const dict = "-dict=";

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-index") == 0) {
            m_print_index = true;
        } else if (strncmp(argv[i], dict, strlen(dict)) == 0) {
            m_use_dict = true;
            m_dict     = std::string(&(argv[i])[strlen(dict)]);
        } else {
            std::ifstream f(argv[i]);
            if (f.good()) {
                m_has_file = true;
            }
            m_filename = std::string(argv[i]);
        }
    }
}

bool Parameter::has_file() {
    return m_has_file;
}

std::string& Parameter::get_filename() {
    return m_filename;
}

bool Parameter::use_dict() {
    return m_use_dict;
}

std::string& Parameter::get_dict_filename() {
    return m_dict;
}

bool Parameter::should_print_index() {
    return m_print_index;
}

std::string Parameter::print() {
    std::stringstream ss;
    ss << "index: " << should_print_index() << " dict: " << use_dict()
       << " dictfile: \"" << get_dict_filename() << "\" file: \""
       << get_filename() << "\"";
    return ss.str();
}
