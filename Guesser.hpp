#pragma once
#include <string>
#include <iostream>
#include "calculate.hpp"
using namespace std;
using std::string;

namespace bullpgia {
	class Guesser {

	public:
		uint length;
		string guessreString;

		virtual string guess() = 0;
		virtual void startNewGame(uint length) {};
		virtual void learn(string reply) {
		};
	};
}