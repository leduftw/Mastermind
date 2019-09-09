
#include "TextUserInterface.h"

void TextUserInterface::printSigns() const {
	cout << "OZNAKE SIMBOLA:\n"
		<< "P - pik\n"
		<< "K - karo\n"
		<< "T - tref\n"
		<< "H - herc\n"
		<< "Z - zvezda\n"
		<< "S - skocko\n\n"
		<< "OSTALE OZNAKE:\n"
		<< "O - jedan simbol pogodjen na pravom mestu\n"
		<< "X - jedan simbol pogodjen ali nije na pravom mestu\n";
}

void TextUserInterface::printRules() const {
	int lenOfComb = Settings::getInstance().getLengthOfCombination();
	int numOfTries = Settings::getInstance().getNumberOfTries();

	cout << "\nPRAVILA:\n";
	cout << "1. Imate " << numOfTries << (numOfTries == 1 ? " pokusaj" : " pokusaja") << " da pogodite tacnu kombinaciju "
		<< "koja se sastoji od " << lenOfComb << " simbola." << endl;
	cout << "2. Kombinaciju unosite tako sto ukucate niz od " << lenOfComb << " karaktera, gde svaki karakter u nizu" << endl
		<< "predstavlja oznaku simbola, pri cemu je svaki simbol odvojen jednim znakom razmaka od prethodnog simbola.\n";
	cout << "3. Simbole obavezno kucati velikim slovima!\n\n";
	printSigns();
}

int TextUserInterface::printMainMenu() const {
	cout << "\n1. Zapocni novu igru\n"
		"2. Podesavanja\n"
		"3. Kraj rada\n"
		"Vas izbor? ";

	int choice;
	cin >> choice;
	return choice;
}

int TextUserInterface::printSettings() const {
	cout << endl << "1. Postavite duzinu kombinacije\n"
		<< "2. Postavite broj pokusaja\n"
		<< "3. Sacuvaj podesavanja\n"
		<< "Vas izbor? ";

	int choice;
	do {
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3) {
			cout << "\nNedozvoljen izbor. Pokusajte ponovo.\n";
			cout << endl << "1. Postavite duzinu kombinacije\n"
				<< "2. Postavite broj pokusaja\n"
				<< "3. Sacuvaj podesavanja\n"
				<< "Vas izbor? ";
		}
	} while (choice != 1 && choice != 2 && choice != 3);

	return choice;
}

void TextUserInterface::printGameInfo(bool &firstGame) const {
	// Prints the rules if user plays for the first time
	if (firstGame)
		TextUserInterface::getInstance().printRules();

	// In every other game, player only gets info about length of combination and number of tries
	if (!firstGame)
		cout << endl << "Duzina kombinacije: " << Settings::getInstance().getLengthOfCombination() << endl
		<< "Broj pokusaja: " << Settings::getInstance().getNumberOfTries() << endl;
	firstGame = false;
}

void TextUserInterface::solvedCorrectly() const {
	cout << "Cestitamo, pogodili ste tacnu kombinaciju!" << endl << endl;
}

void TextUserInterface::gameOver(Combination *ultimate) const {
	cout << endl << "Game over :(" << endl;
	cout << "Zamisljena kombinacija: " << *ultimate << endl;
}