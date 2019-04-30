#pragma once
#include <string>
#include "Guesser.hpp"
using std::string;
using namespace std;

namespace bullpgia {

	class SmartGuesser : public bullpgia::Guesser {

	public:
		string guess() override;
		void learn(string reply) override;
		void startNewGame(uint length) override;
	};
}