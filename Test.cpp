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
/*
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
*/
		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		
		for (uint i = 0; i < 100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 100, true);  // smarty should always win in at most 10 turns!
		}
		
		/*
			testcase.setname("My test- Calculate bull and pgia")
			.CHECK_OUTPUT(calculateBullAndPgia("1010", "0101"), "0,8") // 0 bull, 8 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("1058", "5070"), "1,1") // 1 bull, 1 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("1019", "1023"), "2,1") // 2 bull, 1 pgia

			.CHECK_OUTPUT(calculateBullAndPgia("5749", "4902"), "0,2") // 0 bull, 2 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("5749", "5749"), "4,0") // 4 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("5749", "3925"), "0,2") // 0 bull, 2 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("5749", "8321"), "0,0") // 0 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("5749", "7520"), "0,2") // 0 bull, 2 pgia

			.CHECK_OUTPUT(calculateBullAndPgia("14", "13"), "1,0") // 1 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("14", "41"), "0,2") // 0 bull, 2 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("14", "14"), "2,0") // 0 bull, 1 pgia

			.CHECK_OUTPUT(calculateBullAndPgia("9", "6"), "0,0") // 0 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("9", "9"), "1,0") // 1 bull, 0 pgia

			
			.CHECK_OUTPUT(calculateBullAndPgia("17654378", "12345678"), "3,5")	//8 bull,0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("684", "411"), "0,1")  //1 bull,1 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("1782", "27811"), "2,2") //2 bull,2 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("620", "9060"), "0,2") //0 bull,2 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("105", "1010"), "2,0") //2 bull,0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("13", "31"), "0,2")	//1 bull,1 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("456", "1161"), "1,0") //0 bull,0 pgia
			;
			
			ConstantChooser c4574{ "4574" }, c2356{ "2356" }, c68{ "68" }, c836{ "836" }, c23544{ "23544" };
			ConstantGuesser g4574{ "4574" }, g2356{ "2356" }, g68{ "68" }, g836{ "836" };

			testcase.setname("My Test- Play with dummy choosers and guessers")
			.CHECK_EQUAL(play(c4574, g4574, 4, 100), 1)      // guesser wins in one turn.
			.CHECK_EQUAL(play(c2356, g4574, 4, 100), 101)    // guesser loses by running out of turns 
			.CHECK_EQUAL(play(c68, g2356, 2, 100), 101)   // guesser loses technically by making an illegal guess (too long).
			.CHECK_EQUAL(play(c23544, g836, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
			.CHECK_EQUAL(play(c68, g68, 2, 100), 1)      // guesser wins in one turn.
			.CHECK_EQUAL(play(c836, g4574, 3, 100), 101)   // guesser loses technically by making an illegal guess (too long).
			.CHECK_EQUAL(play(c4574, g836, 4, 100), 101)     // guesser loses technically by choosing an illegal number (too short).
			;
			
			testcase.setname("My Test- Play With smart ");
			RandomChooser randy1;
			SmartGuesser smarty1;
			for (uint i = 0; i < 100; ++i) {
				testcase.CHECK_EQUAL(play(randy1, smarty1, 4, 100) <= 100, true); // smarty win at most 10 rounds
			}
			RandomChooser randy2;
			SmartGuesser smarty2;
			for (uint i = 0; i < 100; ++i) {
				testcase.CHECK_EQUAL(play(randy2, smarty2, 5, 100) <= 70, true); // smarty win at most 10 rounds
			}
			RandomChooser randy3;
			SmartGuesser smarty3;
			for (uint i = 0; i < 100; ++i) {
				testcase.CHECK_EQUAL(play(randy3, smarty3, 3, 100) <= 50, true);  // smarty win at most 10 rounds
			}
			RandomChooser randy4;
			SmartGuesser smarty4;
			for (uint i = 0; i < 100; ++i) {
				testcase.CHECK_EQUAL(play(randy4, smarty4, 2, 100) <= 30, true);  // smarty win  at most 10 turns
			}
		
		*/
		grade = testcase.grade();
	}
	else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: " << grade << endl;
	return 0;
}
