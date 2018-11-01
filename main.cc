#include "businesslogic.hh"
#include "ui.hh"

int main() {
    UI ui;
    BusinessLogic bl;

    auto input = ui.read_input();
    auto count = bl.run(input);
    ui.output(count.first, count.second);
}
