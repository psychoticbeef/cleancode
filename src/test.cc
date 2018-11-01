#include <gmock/gmock-generated-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "businesslogic.hh"
#include "dict.hh"
#include "parameter.hh"
#include "statistics.hh"
#include "type.hh"
#include "wordcount.hh"

TEST(StatisticsTest, CountTokensTest) {
    Type::Tokens t;
    ASSERT_EQ(0, Statistics(t).get_token_count());
    ASSERT_EQ(2, Statistics({"a", "b"}).get_token_count());
    ASSERT_EQ(2, Statistics({"a", "b", "a"}).get_token_count_unique());
}

TEST(StatisticsTest, WordLength) {
    Type::Tokens t;
    Statistics s(t);
    // would be nice, but nan != nan
    //ASSERT_EQ(std::numeric_limits<float>::quiet_NaN(), s.get_average_word_length(t));
    ASSERT_EQ(1, s.get_average_word_length({"a", "b"}));
    ASSERT_EQ(2, s.get_average_word_length({"a", "bibb", "b"}));
}

TEST(IntegrationsTest, HyphenTest) {
    BusinessLogic bl;
    std::string testcase =
        "Humpty-Dumpty sat on a wall. Humpty-Dumpty had a great fall.";
    ASSERT_EQ(7, bl.run(testcase).get_token_count());
    ASSERT_EQ(6, bl.run(testcase).get_token_count_unique());
}

TEST(FilterTest, Test) {
    WordCount wc;
    Type::TokensSet filter = {"a", "on", "off", "the"};
    ASSERT_THAT(wc.filter_tokens({Type::Tokens()}, filter),
                testing::ElementsAre());
    ASSERT_THAT(wc.filter_tokens({"a", "b", "c"}, filter),
                testing::ElementsAre("b", "c"));
    ASSERT_THAT(wc.filter_tokens({"b", "c"}, filter),
                testing::ElementsAre("b", "c"));
    ASSERT_THAT(
        wc.filter_tokens({"mary", "had", "a", "little", "lamb"}, filter),
        testing::ElementsAre("mary", "had", "little", "lamb"));
}

TEST(GetTokenTest, Test) {
    WordCount wc;
    ASSERT_THAT(wc.get_tokens("mary had a little lamb"),
                testing::ElementsAre("mary", "had", "a", "little", "lamb"));
    ASSERT_THAT(wc.get_tokens(" a "), testing::ElementsAre("a"));
    ASSERT_THAT(wc.get_tokens("  "), testing::ElementsAre());
}

TEST(GetStopWordsTest, ValidTestFile) {
    ASSERT_THAT(Storage::getInstance().get_list("stopwords.txt"),
                testing::ElementsAre("a", "off", "on", "the"));
}

TEST(GetStopWordsTest, InvalidFile) {
    ASSERT_THAT(Storage::getInstance().get_list("foobar.txt"),
                testing::ElementsAre());
}

TEST(ParameterTest, Test) {
    char *params[] = {"program_name", "-index", "-dict=dict.txt",
                      "input_test.txt"};

    Parameter p(4, params);
    ASSERT_THAT(true, p.has_file());
    ASSERT_THAT(true, p.should_print_index());
    ASSERT_THAT(true, p.use_dict());
    ASSERT_THAT(std::string("input_test.txt"), p.get_filename());
    ASSERT_THAT(std::string("dict.txt"), p.get_dict_filename());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
