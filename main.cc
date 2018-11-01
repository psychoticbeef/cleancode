#include "ui.hh"
#include "businesslogic.hh"

int main() {
    UI ui;
    BusinessLogic bl;

    auto input = ui.read_input();
    auto count = bl.run(input);
    ui.output(count.first, count.second);
}
