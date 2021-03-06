#ifndef DICT_HH
#define DICT_HH

#include <sstream>
#include <string>
#include "iprintable.hh"
#include "storage.hh"
#include "type.hh"

class Dict : public IPrintable {
   private:
    Dict();
    std::set<std::string> m_dictionary;
    bool m_has_dict;
    bool m_index;
    Type::TokensSet m_tokens;

   public:
    Dict(bool, std::string, bool);
    std::string print() override;
    void set_tokens(Type::TokensSet);
};

#endif
