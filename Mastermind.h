
#ifndef MASTERMIND_H
#define MASTERMIND_H

#include "TextUserInterface.h"

class Mastermind {

	bool firstGame = true, end = false, correct = false, settings = false;
	int choice = 0;

	Combination *player = nullptr, *ultimate = nullptr;

	void erasePreviousCombinations();
	void setStateForNewGame();
	bool makeGuess(int guessCnt);
	void changeLengthOfCombination() const;
	void changeNumberOfTries() const;

public:

	Mastermind() = default;
	void start();

};

#endif
