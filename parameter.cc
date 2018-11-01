#include "parameter.hh"

Parameter::Parameter(int argc, char* argv[])
    : m_has_file(false), m_print_index(false), m_filename() {
    if (argc < 2) {
        return;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-index")) {
            m_print_index = true;
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

std::string Parameter::get_filename() {
    return m_filename;
}

bool Parameter::should_print_index() {
    return m_print_index;
}
