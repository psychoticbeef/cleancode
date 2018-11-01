#ifndef BUSINESSLOGIC_HH
#define BUSINESSLOGIC_HH

#include <string>
#include <utility>
#include "statistics.hh"
#include "storage.hh"
#include "wordcount.hh"

class BusinessLogic {
   public:
    Statistics run(const std::string& input);
};

#endif
