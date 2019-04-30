#pragma once
#include <string>
#include "Guesser.hpp"
using std::string;
using namespace std;

namespace bullpgia {
	class SmartGuesser : public bullpgia::Guesser {
	private:

		string s;
		int place;


	public:
		SmartGuesser() {//default
			s = "0000";
			place = 0;
		}
		string guess() override;
	};
}