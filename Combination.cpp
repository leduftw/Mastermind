
#include "Combination.h"

void Combination::copy(const Combination &c) {
	combination = new char[length = c.length];
	for (int i = 0; i < length; i++)
		combination[i] = c.combination[i];
}

Combination* Combination::createRandomCombination() {
	Combination *c = new Combination();
	double rnd;

	srand(time(nullptr));
	for (int i = 0; i < 50; i++)
		rnd = rand();

	for (int i = 0; i < c->length; i++) {
		rnd = rand() / (double)RAND_MAX;

		if (rnd < 1. / 6)
			c->combination[i] = 'P';
		else if (rnd < 2. / 6)
			c->combination[i] = 'K';
		else if (rnd < 3. / 6)
			c->combination[i] = 'T';
		else if (rnd < 4. / 6)
			c->combination[i] = 'H';
		else if (rnd < 5. / 6)
			c->combination[i] = 'Z';
		else
			c->combination[i] = 'S';
	}

	return c;
}

istream& operator>>(istream &is, Combination &c) {
	bool valid = true; // Indicates whether or not player's input is valid
	do {
		valid = true;
		for (int i = 0; i < c.length; i++) {
			is >> c.combination[i];
			if (c.combination[i] != 'P' && c.combination[i] != 'K' 
				&& c.combination[i] != 'T' && c.combination[i] != 'H' 
				&& c.combination[i] != 'Z' && c.combination[i] != 'S')
				valid = false;
		} // If at least one char is not valid, the whole combination is not valid and the player should input new one
	} while (!valid);
	return is;
}

ostream& operator<<(ostream &os, const Combination &c) {
	for (int i = 0; i < c.length; i++)
		os << c.combination[i] << " ";
	return os;
}

bool operator==(const Combination &c1, const Combination &c2) {
	if (c1.length != c2.length)
		return false;

	for (int i = 0; i < c1.length; i++)
		if (c1.combination[i] != c2.combination[i])
			return false;
	return true;
}

// End-to-end solution :)
void Combination::printSimilarity(const Combination &ultimate) const {
	if (length != ultimate.length) {
		cout << "Error! Combinations don't have equal length." << endl;
		return;
	}

	Combination cpyCurr = *this, cpy = ultimate;
	int inPlace = 0, outOfPlace = 0;

	for (int i = 0; i < length; i++)
		if (cpyCurr.combination[i] == cpy.combination[i]) {
			inPlace++;
			cpyCurr.combination[i] = 1;
			cpy.combination[i] = 0;
		}

	for (int i = 0; i < length; i++)
		for (int j = 0; j < length; j++)
			if (cpyCurr.combination[i] == cpy.combination[j]) {
				outOfPlace++;
				cpyCurr.combination[i] = 1;
				cpy.combination[j] = 0;
				break;
			}

	int all = length;
	for (int i = 0; i < inPlace; i++) {
		cout << "O";
		if (inPlace == length)
			cout << (i == inPlace - 1 ? " " : " | ");
		else
			cout << " | ";
		all--;
	}
	for (int i = 0; i < outOfPlace; i++) {
		cout << "X";
		if (inPlace + outOfPlace == length)
			cout << (i == outOfPlace - 1 ? " " : " | ");
		else
			cout << " | ";
		all--;
	}
	for (int i = 0; i < all; i++)
		cout << (i == all - 1 ? " " : " | ");
	cout << endl;
	if (inPlace + outOfPlace)
		cout << endl;
}
