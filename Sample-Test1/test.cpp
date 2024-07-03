#include "pch.h"
#include "../Project11/Similarity.cpp"
#include <iostream>
#include <string>
using namespace std;

TEST(TestCaseName, SameLength) {
	StringSimilarityChecker checker;
	string a = "ASD";
	string b = "DSA";
	
	EXPECT_EQ(checker.run(a, b), 60);
}
TEST(TestCaseName, DoubleLength) {
	StringSimilarityChecker checker;
	string a = "AA";
	string b = "B";
	
	EXPECT_EQ(checker.run(a, b), 0);
}