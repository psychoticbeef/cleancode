#ifndef IPRINTABLE_HH
#define IPRINTABLE_HH

#include <iostream>
#include <string>

class IPrintable {
    private:
    public:
     virtual std::string print() = 0;
     virtual std::string print_index() = 0;
};

#endif
