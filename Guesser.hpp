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
		virtual string guess() = 0;
		void startNewGame(uint length) {};
		void learn(string reply) {};
	};
}