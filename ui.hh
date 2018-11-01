#ifndef UI_HH
#define UI_HH

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "iprintable.hh"

class UI {
   public:
    std::string read_input();
    std::string read_file(std::string filename);
    void output(IPrintable&, bool should_print_index = false);
};

#endif
