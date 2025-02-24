#include "../Word.h"
#include "../ArrayOfWords.h"
#include <gtest/gtest.h>
#include <sstream>
#include <stdexcept>
#include <cctype>

// extern void interactiveMenu(); // Defined in interactiveMenu source

// Word tests
TEST(WordTest, ConstructorAndOutput) {
    Word w("Hello");
    std::ostringstream os;
    os << w;
    EXPECT_EQ(os.str(), "Hello");
}

TEST(WordTest, CopyConstructor) {
    Word w1("Test");
    Word w2(w1);
    EXPECT_TRUE(w1 == w2);
}

TEST(WordTest, MoveConstructor) {
    Word w1("Move");
    Word w2(std::move(w1));
    std::ostringstream os;
    os << w2;
    EXPECT_EQ(os.str(), "Move");
}

TEST(WordTest, CopyAssignment) {
    Word w1("Assign");
    Word w2;
    w2 = w1;
    EXPECT_TRUE(w1 == w2);
}

TEST(WordTest, MoveAssignment) {
    Word w1("MoveAssign");
    Word w2;
    w2 = std::move(w1);
    std::ostringstream os;
    os << w2;
    EXPECT_EQ(os.str(), "MoveAssign");
}

TEST(WordTest, EqualityAndLessThan) {
    Word w1("apple"), w2("apple"), w3("banana");
    EXPECT_TRUE(w1 == w2);
    EXPECT_TRUE(w1 < w3);
}

TEST(WordTest, StartsWith) {
    Word w("prefix");
    EXPECT_TRUE(w.startsWith("pre"));
    EXPECT_FALSE(w.startsWith("fix"));
}

TEST(WordTest, ToLowerCase) {
    Word w("TeSt");
    w.toLowerCase();
    std::ostringstream os;
    os << w;
    EXPECT_EQ(os.str(), "test");
}

TEST(WordTest, OperatorIndexValid) {
    Word w("hello");
    EXPECT_EQ(w[0], 'h');
    w[0] = 'H';
    EXPECT_EQ(w[0], 'H');
}

TEST(WordTest, OperatorIndexInvalid) {
    Word w("hi");
    EXPECT_THROW({ char c = w[2]; (void)c; }, std::out_of_range);
}

TEST(WordTest, InputOperator) {
    std::istringstream iss("inputTest");
    Word w;
    iss >> w;
    std::ostringstream os;
    os << w;
    EXPECT_EQ(os.str(), "inputTest");
}

// ArrayOfWords tests
TEST(ArrayOfWordsTest, DefaultConstructor) {
    ArrayOfWords arr;
    std::ostringstream os;
    os << arr;
    EXPECT_EQ(os.str(), "");
}

TEST(ArrayOfWordsTest, SingleWordConstructor) {
    Word w("single");
    ArrayOfWords arr(w);
    std::ostringstream os;
    os << arr;
    EXPECT_EQ(os.str(), "single ");
}

TEST(ArrayOfWordsTest, ArrayConstructor) {
    Word words[3] = { Word("one"), Word("two"), Word("three") };
    ArrayOfWords arr(words, 3);
    std::ostringstream os;
    os << arr;
    EXPECT_EQ(os.str(), "one two three ");
}

TEST(ArrayOfWordsTest, CopyConstructor) {
    Word words[2] = { Word("copy"), Word("test") };
    ArrayOfWords arr1(words, 2);
    ArrayOfWords arr2(arr1);
    std::ostringstream os;
    os << arr2;
    EXPECT_EQ(os.str(), "copy test ");
}

TEST(ArrayOfWordsTest, MoveConstructor) {
    Word words[2] = { Word("move"), Word("ctor") };
    ArrayOfWords arr1(words, 2);
    ArrayOfWords arr2(std::move(arr1));
    std::ostringstream os1, os2;
    os1 << arr2;
    os2 << arr1;
    EXPECT_EQ(os1.str(), "move ctor ");
    EXPECT_EQ(os2.str(), "");
}

TEST(ArrayOfWordsTest, CopyAssignment) {
    Word words[2] = { Word("assign"), Word("copy") };
    ArrayOfWords arr1(words, 2);
    ArrayOfWords arr2;
    arr2 = arr1;
    std::ostringstream os;
    os << arr2;
    EXPECT_EQ(os.str(), "assign copy ");
}

TEST(ArrayOfWordsTest, MoveAssignment) {
    Word words[2] = { Word("move"), Word("assign") };
    ArrayOfWords arr1(words, 2);
    ArrayOfWords arr2;
    arr2 = std::move(arr1);
    std::ostringstream os1, os2;
    os1 << arr2;
    os2 << arr1;
    EXPECT_EQ(os1.str(), "move assign ");
    EXPECT_EQ(os2.str(), "");
}

TEST(ArrayOfWordsTest, OperatorPlusEqualWord) {
    ArrayOfWords arr;
    arr += Word("first");
    arr += Word("second");
    std::ostringstream os;
    os << arr;
    EXPECT_EQ(os.str(), "first second ");
}

TEST(ArrayOfWordsTest, OperatorPlusEqualArray) {
    ArrayOfWords arr;
    arr += Word("a");
    ArrayOfWords other;
    other += Word("b");
    other += Word("c");
    arr += other;
    std::ostringstream os;
    os << arr;
    EXPECT_EQ(os.str(), "a b c ");
}

TEST(ArrayOfWordsTest, OperatorIndex) {
    ArrayOfWords arr;
    arr += Word("index");
    EXPECT_TRUE(arr[0] == Word("index"));
}

TEST(ArrayOfWordsTest, Subset) {
    ArrayOfWords arr;
    arr += Word("apple");
    arr += Word("banana");
    arr += Word("apricot");
    ArrayOfWords subset = arr.subset('a');
    std::ostringstream os;
    os << subset;
    EXPECT_EQ(os.str(), "apple apricot ");
}

TEST(ArrayOfWordsTest, SortWords) {
    ArrayOfWords arr;
    arr += Word("delta");
    arr += Word("alpha");
    arr += Word("charlie");
    arr += Word("bravo");
    arr.sortWords();
    std::ostringstream os;
    os << arr;
    EXPECT_EQ(os.str(), "alpha bravo charlie delta ");
}

TEST(ArrayOfWordsTest, InputOperator) {
    std::istringstream iss("3 word1 word2 word3");
    ArrayOfWords arr;
    iss >> arr;
    std::ostringstream os;
    os << arr;
    EXPECT_EQ(os.str(), "word1 word2 word3 ");
}

TEST(ArrayOfWordsTest, Resize) {
    ArrayOfWords arr;
    const int numWords = 20;
    for (int i = 0; i < numWords; i++) {
        arr += Word("word");
    }
    std::ostringstream os;
    os << arr;
    std::string expected;
    for (int i = 0; i < numWords; i++) {
        expected += "word ";
    }
    EXPECT_EQ(os.str(), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
