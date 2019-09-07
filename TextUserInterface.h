
#ifndef TEXTUSERINTERFACE_H
#define TEXTUSERINTERFACE_H

#include <iostream>
#include "Combination.h"
using namespace std;

// Singleton pattern
class TextUserInterface {

	TextUserInterface() { }

public:

	// Note: Scott Meyers mentions in his Effective Modern C++ book, that 
	// deleted functions should generally be public as it results in better 
	// error messages due to the compilers behavior to check accessibility
	// before deleted status

	TextUserInterface(const TextUserInterface &) = delete;
	void operator=   (const TextUserInterface &) = delete;

	static TextUserInterface& getInstance() {
		static TextUserInterface textUI;
		return textUI;
	}

	void printSigns()                    const; // Prints valid characters that player can enter
	void printRules()                    const; // Prints rules of the game
	int printMainMenu()                  const; // Prints main menu and returns choice that player selects
	int printSettings()                  const; // Prints settings menu and returns choice that player select
	void printGameInfo(bool &firstGame)  const; // Prints rules and signs
	void solvedCorrectly()				 const;	// If player guessed correctly
	void gameOver(Combination *ultimate) const; // If player ran out of tries

};

#endif
