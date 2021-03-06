
#include "Mastermind.h"

void Mastermind::erasePreviousCombinations() {
	// delete p, if p is nullptr then delete does nothing
	delete player;
	delete ultimate;	
	player = ultimate = nullptr;
}

void Mastermind::setStateForNewGame() {
	erasePreviousCombinations();
	player = new Combination();
	ultimate = Combination::createRandomCombination();
}

bool Mastermind::makeGuess(int guessCnt) {
	cout << endl << guessCnt + 1 << ". pokusaj:" << endl;
	cin >> *player;
	// cout << "Krajnja kombinacija: " << *ultimate << endl;

	player->printSimilarity(*ultimate);

	return (*player == *ultimate ? true : false);
}

void Mastermind::changeLengthOfCombination() const {
	cout << "\nUnesite novu duzinu kombinacije: ";

	int len;
	cin >> len;
	Settings::getInstance().setLengthOfCombination(len);
}

void Mastermind::changeNumberOfTries() const {
	cout << "\nUnesite novi broj pokusaja: ";

	int num;
	cin >> num;
	Settings::getInstance().setNumberOfTries(num);
}

void Mastermind::start() {
	while (!end) {
		settings = ((choice = TextUserInterface::getInstance().printMainMenu()) == 2 ? true : false);

		switch (choice) {
		case 1: // START NEW GAME
			setStateForNewGame();
			TextUserInterface::getInstance().printGameInfo(firstGame);

			for (int i = 0; i < Settings::getInstance().getNumberOfTries(); i++)
				if (makeGuess(i) == true) {
					TextUserInterface::getInstance().solvedCorrectly();
					break;
				} else if(i == Settings::getInstance().getNumberOfTries() - 1) // we missed and it is our last try
					TextUserInterface::getInstance().gameOver(ultimate);
			break; // case 1

		case 2: // MODIFY SETTINGS
			while (settings) {
				choice = TextUserInterface::getInstance().printSettings();

				switch (choice) {
				case 1:
					changeLengthOfCombination();
					break;

				case 2:
					changeNumberOfTries();
					break;

				case 3:	// EXIT AND SAVE SETTINGS
					settings = false;
					break;

				default:
					cout << "Nepoznata komanda\n";
					break;
				}
			}
			break;

		case 3: // EXIT GAME
			end = true;
			break;

		default:
			cout << "\nNepoznata komanda!\n";
			break;

		}
	}

	erasePreviousCombinations();
}
