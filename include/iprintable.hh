#ifndef IPRINTABLE_HH
#define IPRINTABLE_HH

#include <iostream>
#include <string>

class IPrintable {
    private:
    public:
     virtual std::string print() = 0;
};

#endif
