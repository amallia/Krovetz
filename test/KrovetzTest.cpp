#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Krovetz/Krovetz.hpp"

using namespace ::testing;

TEST(KrovetzTest, TestVerbInIng) {
    stem::Krovetz stemmer;
    std::string stemmed;
    stemmed = stemmer.stem("adherance");
    ASSERT_EQ(stemmed, "adhere");

    stemmed = stemmer.stem("observerance");
    ASSERT_EQ(stemmed, "observer");

    stemmed = stemmer.stem("abance");
    ASSERT_EQ(stemmed, "abance");

    stemmed = stemmer.stem("coefficiency");
    ASSERT_EQ(stemmed, "coefficient");

    stemmed = stemmer.stem("abcdancy");
    ASSERT_EQ(stemmed, "abcdance");

    stemmed = stemmer.stem("canonic");
    ASSERT_EQ(stemmed, "canonical");

    stemmed = stemmer.stem("colonic");
    ASSERT_EQ(stemmed, "colony");

    stemmed = stemmer.stem("colonic");
    ASSERT_EQ(stemmed, "colony");

    stemmed = stemmer.stem("communic");
    ASSERT_EQ(stemmed, "commune");

    stemmed = stemmer.stem("abcdeic");
    ASSERT_EQ(stemmed, "abcdeic");

    stemmed = stemmer.stem("ammism");
    ASSERT_EQ(stemmed, "amm");

    stemmed = stemmer.stem("aboutness");
    ASSERT_EQ(stemmed, "about");

    stemmed = stemmer.stem("aaaaainess");
    ASSERT_EQ(stemmed, "aaaaay");

    stemmed = stemmer.stem("doable");
    ASSERT_EQ(stemmed, "do");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}