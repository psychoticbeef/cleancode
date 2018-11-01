#ifndef STORAGE_HH
#define STORAGE_HH

#include <fstream>
#include <set>
#include <string>
#include <utility>

class Storage {
   private:
    bool file_exists(const std::string& name);

   public:
    const std::set<std::string> get_list(const std::string& filename);
    static Storage& getInstance() {
        static Storage instance;
        return instance;
    }
};

#endif
