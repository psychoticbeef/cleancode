#include "stopwords.hh"

// --- UI class ---

std::string Stopwords::read_input() {
	std::cout << "Enter sentence: ";
	std::string result;
	std::getline(std::cin, result);
	return result;
}

void Stopwords::output(int count, int count_distinct) {
	std::cout << "count: " <<  count << std::endl;
	std::cout << "count distinct: " <<  count_distinct << std::endl;
}

// --- Storage class ---

bool Stopwords::file_exists(const std::string& name) {
	std::ifstream f(name.c_str());
	return f.good();
}

const std::vector<std::string> Stopwords::get_stop_words(const std::string& filename) {
	std::vector<std::string> result;
	if (!file_exists(filename)) return result;
	// TODO: check file readability
	std::fstream filter;
	filter.open(filename, std::ios::in);
	std::string line;
	while (getline(filter, line)) {
		result.push_back(line);
	}
	return result;
}

// --- word count class ---

const std::vector<std::string> Stopwords::split_string(const std::string& stringToSplit, const std::string& regexPattern) {
	std::vector<std::string> result;
	const std::regex rgx(regexPattern);
	std::sregex_token_iterator iter(stringToSplit.begin(), stringToSplit.end(), rgx, -1);
	for (std::sregex_token_iterator end; iter != end; ++iter) {
		result.push_back(iter->str());
	}
	if (result.size() >= 1 && result.at(0) == "") result.erase(result.begin());
	return result;
}

const std::vector<std::string> Stopwords::get_tokens(const std::string& input) {
	const std::string pattern("([^a-zA-Z]+)");
	return split_string(input, pattern);
}

const std::vector<std::string> Stopwords::filter_tokens(const std::vector<std::string>& input, const std::vector<std::string>& filter) {
	std::vector<std::string> result;
	std::copy_if (input.begin(), input.end(), std::back_inserter(result),
			[filter](std::string in) {
			return std::find(filter.begin(), filter.end(), in) == filter.end();
			}
		     );
	return result;
}

const int Stopwords::get_word_count(const std::vector<std::string>& input) {
	return input.size();
}

const int Stopwords::get_word_count_distinct(const std::vector<std::string>& input) {
	std::set<std::string> result;
	for (const auto &i : input) result.insert(i);
	return result.size();
}

// --- integration ---

const std::pair<int, int> Stopwords::run(const std::string& input) {
	auto tokens = get_tokens(input);
	std::vector<std::string> stop_words = get_stop_words("stopwords.txt");
	auto filtered = filter_tokens(tokens, stop_words);
	auto count =  get_word_count(filtered);
	auto count_distinct =  get_word_count_distinct(filtered);
	return std::make_pair(count, count_distinct);
}

