/**
 * A demo program for bull-pgia.
 *
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#include "calculate.hpp"
#include "Guesser.hpp"
#include "Chooser.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{ "1234" }, c12345{ "12345" }, c9999{ "9999" };
		ConstantGuesser g1234{ "1234" }, g12345{ "12345" }, g9999{ "9999" };

		testcase.setname("Calculate bull and pgia")
			.CHECK_OUTPUT(calculateBullAndPgia("1234", "1234"), "4,0")      // 4 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("1234", "4321"), "0,4")      // 0 bull, 4 pgia
			;

		testcase.setname("Play with dummy choosers and guessers")
			.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
			.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
			.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
			.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
			;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i = 0; i < 100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 100, true);  // smarty should always win in at most 10 turns!
		}

			testcase.setname("My test- Calculate bull and pgia")
			.CHECK_OUTPUT(calculateBullAndPgia("1010", "0101"), "0,4") // 0 bull, 4 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("1010", "0000"), "2,0") // 2 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("1010", "1023"), "2,1") // 0 bull, 1 pgia

			.CHECK_OUTPUT(calculateBullAndPgia("5749", "4902"), "0,1") // 0 bull, 1 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("5749", "5749"), "4,0") // 4 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("5749", "3925"), "0,2") // 0 bull, 2 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("5749", "8321"), "0,0") // 0 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("5749", "7520"), "0,2") // 0 bull, 2 pgia

			.CHECK_OUTPUT(calculateBullAndPgia("14", "1"), "1,0") // 1 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("14", "41"), "0,2") // 0 bull, 2 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("14", "14"), "2,0") // 0 bull, 1 pgia

			.CHECK_OUTPUT(calculateBullAndPgia("9", "6"), "0,0") // 0 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("9", "9"), "1,0") // 1 bull, 0 pgia

			
			.CHECK_OUTPUT(calculateBullAndPgia("176543789", "12345678"), "8,0")	//8 bull,0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("6844", "411"), "0,1")  //1 bull,1 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("1782", "27811"), "2,2") //2 bull,2 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("620", "9060"), "0,2") //0 bull,2 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("105", "1010"), "2,0") //2 bull,0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("137", "31"), "0,1")	//1 bull,1 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("666", "1161"), "1,0") //0 bull,0 pgia
			;
			
			ConstantChooser c4574{ "4574" }, c2356{ "2356" }, c68{ "68" }, c836{ "836" };
			ConstantGuesser g4574{ "4574" }, g2356{ "2356" }, g68{ "68" }, g836{ "836" };

			testcase.setname("My Test- Play with dummy choosers and guessers")
			.CHECK_EQUAL(play(c4574, g4574, 4, 100), 1)      // guesser wins in one turn.
			.CHECK_EQUAL(play(c2356, g4574, 4, 100), 101)    // guesser loses by running out of turns 
			.CHECK_EQUAL(play(c68, g2356, 2, 100), 101)   // guesser loses technically by making an illegal guess (too long).
			.CHECK_EQUAL(play(c2356, g68, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
			.CHECK_EQUAL(play(c68, g68, 2, 100), 1)      // guesser wins in one turn.
			.CHECK_EQUAL(play(c836, g4574, 3, 100), 101)   // guesser loses technically by making an illegal guess (too long).
			.CHECK_EQUAL(play(c4574, g836, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
			;

			testcase.setname("My Test- Play With Random ");
			RandomChooser Rchooser;
			SmartGuesser Schooser;
			testcase.CHECK_EQUAL(play(Rchooser, Schooser, 7, 100) <= 1, false);
			testcase.CHECK_EQUAL(play(Rchooser, Schooser, 4, 100) <= 100, true);
			testcase.CHECK_EQUAL(play(Rchooser, Schooser, 5, 100) <= 8, true);

			testcase.setname("My Test- Play Test");

			for (uint i = 0; i < 10; ++i) {
				testcase.CHECK_EQUAL(play(Rchooser, Schooser, 3, 100) <= 10, true);  // schooser  win at most 10 rounds
			}
			for (uint i = 0; i < 10; ++i) {
				testcase.CHECK_EQUAL(play(Rchooser, Schooser, 2, 100) <= 10, true);  // schooser  win  at most 10 turns
			}
		

		grade = testcase.grade();
	}
	else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: " << grade << endl;
	return 0;
}
