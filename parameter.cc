#include "parameter.hh"

Parameter::Parameter(int argc, char * argv[]) :
m_has_file(false),
m_filename() {
    if (argc < 2) {
        return;
    }
    std::ifstream f(argv[1]);
    if (f.good()) {
        m_has_file = true;
    }
    m_filename = std::string(argv[1]);
}

bool Parameter::has_file() {
    return m_has_file;
}

std::string Parameter::get_filename() {
    return m_filename;
}
