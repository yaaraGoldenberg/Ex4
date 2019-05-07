
#include "calculate.hpp"
using namespace std;


string bullpgia::calculateBullAndPgia(string s, string guess) {
	int countBull = 0, countPgia = 0, size = s.length();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (s.at(i) == guess.at(j)) {
				if (i == j) {
					countBull++;
					break;
				}
				else {
					countPgia++;
				}
			}
		}
	}
		string ans = to_string(countBull) + "," + to_string(countPgia);
		return ans;
}

