#include "businesslogic.hh"
#include "dict.hh"
#include "parameter.hh"
#include "ui.hh"

int main(int argc, char* argv[]) {
    UI ui;
    BusinessLogic bl;
    Parameter p(argc, argv);
    ui.output(p);
    Dict dict(p.use_dict(), p.get_dict_filename(), p.should_print_index());

    bool next = false;
    do {
        auto input =
            p.has_file() ? ui.read_file(p.get_filename()) : ui.read_input();
        auto statistics = bl.run(input);
        dict.set_tokens(statistics.get_unique());
        ui.output(statistics, p.should_print_index());
        ui.output(dict);
        next = statistics.get_token_count() > 0;
    } while (!p.has_file() && next);
}
