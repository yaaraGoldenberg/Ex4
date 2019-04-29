#pragma once
#include <string>
using std::string;

namespace bullpgia {
	class Guesser {

	public:
		int length;
		virtual string guess();
		void startNewGame(int length);
		void learn(string reply);
	};
}