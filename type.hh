#ifndef TYPE_HH
#define TYPE_HH

#include <set>
#include <string>
#include <vector>

class Type {
   public:
    typedef std::string Token;
    typedef Token& TokenRef;
    typedef std::vector<Token> Tokens;
    typedef Tokens& TokensRef;
    typedef std::set<Token> TokensSet;
};

#endif
