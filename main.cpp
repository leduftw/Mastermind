
#include "Combination.h"

int numberOfTries = 6;
int length = 4;

void printSigns() {
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

void printInfo() {
	cout << "\nPRAVILA:\n";
	cout << "1. Imate " << numberOfTries << (numberOfTries == 1 ? " pokusaj" : " pokusaja") << " da pogodite tacnu kombinaciju "
		<< "koja se sastoji od " << length << " simbola." << endl;
	cout << "2. Kombinaciju unosite tako sto ukucate niz od " << length << " karaktera, gde svaki karakter u nizu" << endl
		<< "predstavlja oznaku simbola, pri cemu je svaki simbol odvojen jednim znakom razmaka od prethodnog simbola.\n";
	cout << "3. Simbole obavezno kucati velikim slovima!\n\n";
	printSigns();
}

int main() {
	int choice;
	bool end = false, correct = false, firstGame = true, settings = false;
	Combination *curr = nullptr, *ultimate = nullptr;

	while (!end) {
		cout << "\n1. Zapocni novu igru\n"
			"2. Podesavanja\n"
			"3. Kraj rada\n"
			"Vas izbor? ";

		cin >> choice;

		switch (choice) {
		case 1:
			if (curr)
				delete curr;
			if (ultimate)
				delete ultimate;
			curr = new Combination(length);
			ultimate = new Combination(length);
			correct = false;
			Combination::createRandomCombination(*ultimate);
			if (firstGame) {
				printInfo();
				firstGame = false;
			}
			
			if (!firstGame) {
				cout << endl << "Duzina kombinacije: " << length << endl;
				cout << "Broj pokusaja: " << numberOfTries << endl;
			}

			for (int i = 0; i < numberOfTries; i++) {
				cout << endl << i + 1 << ". pokusaj:" << endl;
				cin >> *curr;
				// cout << "Krajnja kombinacija: " << *ultimate << endl;

				curr->similarity(*ultimate);
				
				if (*curr == *ultimate) {
					cout << "Cestitamo, pogodili ste tacnu kombinaciju!" << endl << endl;
					correct = true;
					break;
				}
			}

			if (!correct) {
				cout << "Game over :(" << endl;
				cout << "Zamisljena kombinacija: " << *ultimate << endl;
			}
			break;

		case 2:
			settings = true;
			while (settings) {
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

				switch (choice) {
				case 1:
					cout << "\nUnesite novu duzinu kombinacije: ";
					cin >> length;
					break;

				case 2:
					cout << "\nUnesite novi broj pokusaja: ";
					cin >> numberOfTries;
					break;

				case 3:
					settings = false;
					break;

				default:
					cout << "Nepoznata komanda\n";
					break;
				}
			}
			break;

		case 3:
			end = true;
			break;

		default:
			cout << "\nNepoznata komanda!\n";
			break;

		}
	}

	delete curr;
	delete ultimate;

}