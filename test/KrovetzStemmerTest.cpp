#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "KrovetzStemmer/KrovetzStemmer.hpp"

using namespace ::testing;

TEST(KrovetzStemmerTest, TestVerbInIng) {
    stem::KrovetzStemmer * stemmer = new stem::KrovetzStemmer();
    std::string thestem = stemmer->kstem_stemmer((char*)"eating");
    ASSERT_EQ(thestem, "eat");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}