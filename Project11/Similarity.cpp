#include <iostream>
#include <string>
using namespace std;

class StringSimilarityChecker {
public:
	const int MAX_SCORE = 60;
	int run(string a, string b) {
		if (isSameLength(a, b)) { return MAX_SCORE; }
		if (isDoubleLength(a, b)) { return 0; }
		return GetScore(a, b);
	}
	int GetScore(std::string& a, std::string& b)
	{
		int longlen = max(a.length(), b.length());
		int shortlen = min(a.length(), b.length());
		return MAX_SCORE * (shortlen - (longlen - shortlen)) / shortlen;
	}
	bool isSameLength(std::string& a, std::string& b)
	{
		return (a.length() == b.length());
	}
	bool isDoubleLength(std::string& a, std::string& b)
	{
		return (a.length() * 2 <= b.length()
			|| a.length() >= b.length() * 2);
	}
};