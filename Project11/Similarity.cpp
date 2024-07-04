#include <iostream>
#include <string>
using namespace std;

class StringSimilarityChecker {
public:
	const int MAX_SCORE = 60;
	int run(string a, string b) {
		int longlen = max(a.length(), b.length());
		int shortlen = min(a.length(), b.length());

		if (longlen == shortlen) { return MAX_SCORE; }
		if (longlen == shortlen * 2) { return 0; }
		return GetScore(longlen, shortlen);
	}
	int GetScore(int longlen, int shortlen)
	{
		return MAX_SCORE * (shortlen - (longlen - shortlen)) / shortlen;
	}
};