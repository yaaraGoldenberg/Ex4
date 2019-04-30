#include "calculate.hpp"
using namespace std::string;
using namespace bullpgia;

string calculateBullAndPgia(string s, string guess) {
	int cuntBull = 0, countPgia = 0, size = s.length();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (s.at(i) == guess.at(j)) {
				if (i == j) {
					cuntBull++;
					break;
				}
				else {
					countPgia++;
				}
			}
		}
		string ans = "bull: " + to_string(countBull) + " , pgia: " + to_string(countPgia);
		return ans;
	}
}