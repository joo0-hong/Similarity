#include "pch.h"
#include "../Project11/Similarity.cpp"
#include <iostream>
#include <string>
using namespace std;

TEST(TestCaseName, SameLength) {
	StringSimilarityChecker checker;
	string a = "ASD";
	string b = "DSA";
	
	EXPECT_EQ(checker.getLengthScore(a, b), 60);
}
TEST(TestCaseName, DoubleLength) {
	StringSimilarityChecker checker;
	string a = "AA";
	string b = "B";
	
	EXPECT_EQ(checker.getLengthScore(a, b), 0);
}
TEST(TestCaseName, Length5and3) {
	StringSimilarityChecker checker;
	string a = "AAABB";
	string b = "BAA";
	
	EXPECT_EQ(checker.getLengthScore(a, b), 20);
}

TEST(TestCaseName, Including) {
	StringSimilarityChecker checker;
	string a = "AA";
	string b = "AAE";
	
	EXPECT_EQ(checker.getLengthScore(a, b), 30);
}

TEST(TestCaseName, SameAlphabets) {
	StringSimilarityChecker checker;
	string a = "ASD";
	string b = "DSA";

	EXPECT_EQ(checker.getAlphaScore(a, b), 40);
}

TEST(TestCaseName, NoneSameAlphabets) {
	StringSimilarityChecker checker;
	string a = "A";
	string b = "BB";

	EXPECT_EQ(checker.getAlphaScore(a, b), 0);
}

TEST(TestCaseName, AlphabetIncluding) {
	StringSimilarityChecker checker;
	string a = "AAABB";
	string b = "BA";

	EXPECT_EQ(checker.getAlphaScore(a, b), 40);
}

TEST(TestCaseName, AlphabetIncluding2) {
	StringSimilarityChecker checker;
	string a = "AA";
	string b = "AAE";

	EXPECT_EQ(checker.getAlphaScore(a, b), 20);
}

