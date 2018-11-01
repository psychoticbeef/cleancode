#ifndef STOPWORDS_H
#define STOPWORDS_H

#include <fstream>
#include <string>
#include <utility>
#include <vector>

class Stopwords {
   private:
    bool file_exists(const std::string& name);

   public:
    const std::pair<int, int> run(const std::string& input);
    const std::vector<std::string> get_stop_words(const std::string& filename);
};

#endif
