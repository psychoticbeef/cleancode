#include "ui.hh"

std::string UI::read_input() {
    std::cout << "Enter sentence: ";
    std::string result;
    std::getline(std::cin, result);
    return result;
}

std::string UI::read_file(std::string filename) {
    std::ifstream in(filename, std::ios::in | std::ios::binary);
    std::ostringstream result;
    result << in.rdbuf();
    in.close();
    return result.str();
}

void UI::output(IPrintable& printable, bool should_print_index) {
    std::cout << printable.print() << std::endl;
}
