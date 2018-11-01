#ifndef PARAMETER_HH
#define PARAMETER_HH

#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include "iprintable.hh"

class Parameter : public IPrintable {
   private:
    Parameter();
    bool m_has_file;
    bool m_use_dict;
    bool m_print_index;
    std::string m_filename;
    std::string m_dict;

   public:
    Parameter(int argc, char* argv[]);
    bool has_file();
    std::string get_filename();
    bool use_dict();
    std::string get_dict_filename();
    bool should_print_index();
    std::string print() override;
};

#endif
