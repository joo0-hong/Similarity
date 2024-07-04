#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StringSimilarityChecker {
public:
	const int MAX_LENGTH_SCORE = 60;
	const int MAX_ALPHA_SCORE = 40;

	// Length checker
	int getLengthScore(string a, string b) {
		int longlen = max(a.length(), b.length());
		int shortlen = min(a.length(), b.length());

		if (longlen == shortlen) {
			return MAX_LENGTH_SCORE;
		}
		if (longlen >= shortlen * 2) {
			return 0;
		}
		return calcLengthScore(longlen, shortlen);
	}
	int calcLengthScore(int longlen, int shortlen)
	{
		return MAX_LENGTH_SCORE * (shortlen - (longlen - shortlen)) / shortlen;
	}

	// Alphabet checker
	int getAlphaScore(string a, string b)
	{
		for (int alen = 0; alen < a.length(); alen++) {
			for (int blen = 0; blen < b.length(); blen++) {
				addCharToListWithCheck(totalList, a[alen]);
				addCharToListWithCheck(totalList, b[blen]);
				if (a[alen] == b[blen])
				{
					addCharToListWithCheck(sameList, a[alen]);
				}
			}
		}

		if (sameList.size() == 0)
			return 0;

		if (sameList.size() == a.length())
			return MAX_ALPHA_SCORE;

		return calcAlphaScore();
	}

	unsigned long long calcAlphaScore()
	{
		return MAX_ALPHA_SCORE * sameList.size() / totalList.size();
	}

	void addCharToListWithCheck(vector<char>& list, char input)
	{
		bool found = false;
		for (char ch : list)
		{
			if (ch == input) {
				found = true;
				break;
			}
		}
		if (found == false)
			list.push_back(input);
	}
private : 
	vector<char> totalList;
	vector<char> sameList;
};