#include <array>
#include "calculate.hpp"
using namespace std;

string bullpgia::calculateBullAndPgia(string s, string guess) {
	int countBull = 0, countPgia = 0, size = s.length();
	for (int i = 0; i < size; i++) {
		if (s[i] == guess[i]) {
			countBull++;
			s[i] = 'T';
			guess[i] = 'Z';
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (s[i] == guess[j]) {
				countPgia++;
				guess[j] = 'Z';
			}
		}
	}
	return to_string(countBull) + "," + to_string(countPgia);
}
