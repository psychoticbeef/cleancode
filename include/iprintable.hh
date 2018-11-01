#ifndef IPRINTABLE_HH
#define IPRINTABLE_HH

#include <string>

class IPrintable {
   private:
   public:
    virtual std::string print() = 0;
};

#endif
