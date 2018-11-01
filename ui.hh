#ifndef UI_HH
#define UI_HH

#include <iostream>
#include <string>

class UI {
   public:
    std::string read_input();
    void output(int count, int count_distinct);
};

#endif
