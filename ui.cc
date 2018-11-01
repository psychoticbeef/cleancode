#include "ui.hh"

std::string UI::read_input() {
    std::cout << "Enter sentence: ";
    std::string result;
    std::getline(std::cin, result);
    return result;
}

void UI::output(int count, int count_distinct) {
    std::cout << "count: " << count << std::endl;
    std::cout << "count distinct: " << count_distinct << std::endl;
}
