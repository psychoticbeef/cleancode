#include "main.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-generated-matchers.h>


TEST(WordCountTest, Test) {
    ASSERT_EQ(0, get_word_count({ }));
    ASSERT_EQ(2, get_word_count({ "a", "b" }));
}

TEST(FilterTest, Test) {
    std::vector<std::string> filter = { "a", "on", "off", "the" };
    ASSERT_THAT(filter_tokens( { "" }, filter), testing::ElementsAre( "" ));
    ASSERT_THAT(filter_tokens( { "a", "b", "c" }, filter), testing::ElementsAre("b", "c"));
    ASSERT_THAT(filter_tokens( { "b", "c" }, filter), testing::ElementsAre("b", "c"));
    ASSERT_THAT(filter_tokens( { "mary", "had", "a", "little", "lamb" }, filter), testing::ElementsAre("mary", "had", "little", "lamb"));
}

TEST(GetTokenTest, Test) {
    ASSERT_THAT(get_tokens("mary had a little lamb"), testing::ElementsAre("mary", "had", "a", "little", "lamb"));
    ASSERT_THAT(get_tokens(" a "), testing::ElementsAre( "a"));
    ASSERT_THAT(get_tokens("  "), testing::ElementsAre( ));
}

TEST(GetStopWordsTest, ValidTestFile) {
    ASSERT_THAT(get_stop_words("stopwords.txt"), testing::ElementsAre( "a", "on", "off", "the" ));
}
TEST(GetStopWordsTest, InvalidFile) {
    ASSERT_THAT(get_stop_words("foobar.txt"), testing::ElementsAre( ));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
