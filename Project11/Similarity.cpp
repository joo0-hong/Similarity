#include <iostream>
#include <string>
using namespace std;

class StringSimilarityChecker {
public : 
	int run(string a, string b) {
		if (isSameLength(a, b))
		{
			return 60;
		}

		if (isDoubleLength(a, b))
		{
			return 0;
		}
	}
	bool isSameLength(std::string& a, std::string& b)
	{
		return a.length() == b.length();
	}
	bool isDoubleLength(std::string& a, std::string& b)
	{
		return a.length() * 2 <= b.length()
			|| a.length() >= b.length() * 2;
	}
};