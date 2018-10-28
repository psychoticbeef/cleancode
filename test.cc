#include <gmock/gmock-generated-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "stopwords.hh"

TEST(WordCountTest, Test) {
    Stopwords sw;
    ASSERT_EQ(0, sw.get_word_count({}));
    ASSERT_EQ(2, sw.get_word_count({"a", "b"}));
}

TEST(FilterTest, Test) {
    Stopwords sw;
    std::vector<std::string> filter = {"a", "on", "off", "the"};
    ASSERT_THAT(sw.filter_tokens({""}, filter), testing::ElementsAre(""));
    ASSERT_THAT(sw.filter_tokens({"a", "b", "c"}, filter),
                testing::ElementsAre("b", "c"));
    ASSERT_THAT(sw.filter_tokens({"b", "c"}, filter),
                testing::ElementsAre("b", "c"));
    ASSERT_THAT(
        sw.filter_tokens({"mary", "had", "a", "little", "lamb"}, filter),
        testing::ElementsAre("mary", "had", "little", "lamb"));
}

TEST(GetTokenTest, Test) {
    Stopwords sw;
    ASSERT_THAT(sw.get_tokens("mary had a little lamb"),
                testing::ElementsAre("mary", "had", "a", "little", "lamb"));
    ASSERT_THAT(sw.get_tokens(" a "), testing::ElementsAre("a"));
    ASSERT_THAT(sw.get_tokens("  "), testing::ElementsAre());
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
