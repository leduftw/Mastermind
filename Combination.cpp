
#include "Combination.h"

void Combination::copy(const Combination &c) {
	combination = new char[length = c.length];
	for (int i = 0; i < c.length; i++)
		combination[i] = c.combination[i];
}

void Combination::createRandomCombination(Combination &c) {
	int length = c.length;
	double rnd;

	srand(time(nullptr));
	for (int i = 0; i < 50; i++)
		rnd = rand();

	for (int i = 0; i < length; i++) {
		rnd = rand() / (double)RAND_MAX;

		if (rnd < 1. / 6)
			c.combination[i] = 'P';
		else if (rnd < 2. / 6)
			c.combination[i] = 'T';
		else if (rnd < 3. / 6)
			c.combination[i] = 'K';
		else if (rnd < 4. / 6)
			c.combination[i] = 'H';
		else if (rnd < 5. / 6)
			c.combination[i] = 'S';
		else
			c.combination[i] = 'Z';
	}
}

istream& operator>>(istream &is, Combination &c) {
	int length = c.getLength();
	char *comb = new char[length];
	bool valid = true;
	do {
		valid = true;
		for (int i = 0; i < length; i++) {
			is >> comb[i];
			if (comb[i] != 'P' && comb[i] != 'K' && comb[i] != 'T' && comb[i] != 'H' && comb[i] != 'Z' && comb[i] != 'S')
				valid = false;
		}
	} while (!valid);

	for (int i = 0; i < length; i++)
		c.combination[i] = comb[i];
	delete[] comb;
	return is;
}

ostream& operator<<(ostream &os, const Combination &c) {
	for (int i = 0; i < c.getLength(); i++)
		os << c.combination[i] << " ";
	return os;
}

bool operator==(const Combination &c1, const Combination &c2) {
	if (c1.getLength() != c2.getLength())
		return false;

	for (int i = 0; i < c1.getLength(); i++)
		if (c1.combination[i] != c2.combination[i])
			return false;
	return true;
}

void Combination::similarity(const Combination &c) const {
	if (length != c.length)
		return;

	Combination cpyCurr = *this, cpy = c;
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
