#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StringSimilarityChecker {
public:
	const int MAX_LENGTH_SCORE = 60;
	const int MAX_ALPHA_SCORE = 40;
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
	int getAlphaScore(string a, string b)
	{
		for (int alen = 0; alen < a.length(); alen++) {
			addCharTotalList(a[alen]);
			for (int blen = 0; blen < b.length(); blen++) {
				addCharTotalList(b[blen]);
				if (a[alen] == b[blen])
				{
					addCharToSameList(a[alen]);
				}
			}
		}

		if (sameList.size() == 0)
			return 0;

		if (a.length() == sameList.size())
			return MAX_ALPHA_SCORE;

		return MAX_ALPHA_SCORE * sameList.size() / totalList.size();
	}

	void addCharToSameList(char sameChar)
	{
		bool found = false;
		for (char ch : sameList)
		{
			if (ch == sameChar) {
				found = true;
				break;
			}
		}
		if (found == false)
			sameList.push_back(sameChar);
	}

	void addCharTotalList(char input)
	{
		bool found = false;
		for (char ch : totalList)
		{
			if (ch == input) {
				found = true;
				break;
			}
		}
		if (found == false)
			totalList.push_back(input);
	}

	vector<char> totalList;
	vector<char> sameList;
};