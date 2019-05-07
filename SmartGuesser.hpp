#pragma once
#include <string>
#include "Guesser.hpp"
#include "calculate.hpp"

namespace bullpgia {
	class SmartGuesser : public bullpgia::Guesser {
	public:
		string guess() override;
		void learn(string results) override;
		void startNewGame(uint length) override;
	};
}