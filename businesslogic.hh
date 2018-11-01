#ifndef BUSINESSLOGIC_HH
#define BUSINESSLOGIC_HH

#include <string>
#include <utility>

class BusinessLogic {
   public:
    std::pair<int, int> run(const std::string& input);
};

#endif
