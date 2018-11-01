#include <gmock/gmock-generated-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "businesslogic.hh"
#include "stopwords.hh"
#include "wordcount.hh"

TEST(WordCountTest, Test) {
    WordCount wc;
    ASSERT_EQ(0, wc.get_word_count({}));
    ASSERT_EQ(2, wc.get_word_count({"a", "b"}));
}

TEST(FilterTest, Test) {
    WordCount wc;
    std::vector<std::string> filter = {"a", "on", "off", "the"};
    ASSERT_THAT(wc.filter_tokens({""}, filter), testing::ElementsAre(""));
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
    Stopwords sw;
    ASSERT_THAT(sw.get_stop_words("stopwords.txt"),
                testing::ElementsAre("a", "on", "off", "the"));
}
TEST(GetStopWordsTest, InvalidFile) {
    Stopwords sw;
    ASSERT_THAT(sw.get_stop_words("foobar.txt"), testing::ElementsAre());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
