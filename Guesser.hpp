#pragma once
#include <string>
using std::string;

namespace bullpgia {
	class Guesser {

	public:
		unsigned int length
		int Bull, Pgia;
		virtual string guess() = 0;
		void startNewGame(uint length) {
			length = length;
		};
		void learn(string reply) {};
	};
}