#include "stopwords.hh"

int main() {
    Stopwords sw;
    auto input = sw.read_input();
    auto count = sw.run(input);
    sw.output(count.first, count.second);
}
