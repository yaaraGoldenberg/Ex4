#include "SmartGuesser.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <string>
#include <list>
using std::string;
using namespace std;
using namespace bullpgia;

list<std::string> option;
string tempGuess;

void SmartGuesser::startNewGame(uint length) {
	int size = pow(10, length);
	for (int i = 0; i < size; i++) {
		stringstream stream;
		stream << setw(length) << setfill('0') << i;
		string guess = stream.str();
		option.push_front(guess);
	}
}

string SmartGuesser::guess()  {
	std::list<std::string>::iterator itOption = option.begin();
	if (option.size() == 0) {
		startNewGame(length);
	}
	else if (option.size() > 1) {
		std::advance(itOption, rand() % (option.size() - 1));
		tempGuess = *itOption;
	}
	else {//there is only one option
		tempGuess = *itOption->begin();
	}
	return tempGuess;
}

void SmartGuesser::learn(string reply) {
	list<string>::iterator it = option.begin();
	while (it != option.end()) {
		string check = calculateBullAndPgia(*it, tempGuess);
		if (check.compare(reply) != 0) {
			it = option.erase(it);
		}
		std::advance(it, 1);
	}
	option.remove(tempGuess);
}
