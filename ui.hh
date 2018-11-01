#ifndef UI_HH
#define UI_HH

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class UI {
   public:
    std::string read_input();
    std::string read_file(std::string filename);
    void output(int count, int count_distinct);
};

#endif
