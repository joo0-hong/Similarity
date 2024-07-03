#include "pch.h"
#include "../Project11/Similarity.cpp"
#include <iostream>
#include <string>
using namespace std;

TEST(TestCaseName, TestName) {
	StringSimilarityChecker checker;
	string a = "ASD";
	string b = "DSA";
	
	EXPECT_EQ(checker.run(a, b), 60);
}