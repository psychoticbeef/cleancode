#include "businesslogic.hh"
#include "parameter.hh"
#include "ui.hh"

int main(int argc, char* argv[]) {
    UI ui;
    BusinessLogic bl;
    Parameter p(argc, argv);

    auto input = p.has_file() ? ui.read_file(p.get_filename()) : ui.read_input();
    auto statistics = bl.run(input);
    ui.output(statistics, p.should_print_index());
}
