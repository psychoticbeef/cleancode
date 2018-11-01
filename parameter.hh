#ifndef PARAMETER_HH
#define PARAMETER_HH

#include <cstring>
#include <fstream>
#include <string>

class Parameter {
   private:
    Parameter();
    bool m_has_file;
    bool m_print_index;
    std::string m_filename;

   public:
    Parameter(int argc, char* argv[]);
    bool has_file();
    std::string get_filename();
    bool should_print_index();
};

#endif
