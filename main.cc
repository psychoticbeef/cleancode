#include "stopwords.hh"

int main() {
	auto sw = new Stopwords();
	auto input = sw->read_input();
	auto count = sw->run(input);
	sw->output(count.first, count.second);
	delete sw;
}
