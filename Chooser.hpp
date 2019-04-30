#pragma once
#include <string>
#include <iostream>
using std::string;

namespace bullpgia {

	class Chooser {
		public:
		virtual string choose(uint length) = 0;
	};
}