
#ifndef COMBINATION_H
#define COMBINATION_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Settings.h"
using namespace std;

class Combination {

	char *combination;
	int length;

	void copy(const Combination &);

	void move(Combination &c) {
		length = c.length;
		combination = c.combination;
		c.combination = nullptr;
	}

	void erase() {
		delete[] combination;
	}

public:

	Combination() {
		combination = new char[length = Settings::getInstance().getLengthOfCombination()];
	}

	Combination(const Combination &c) {
		copy(c);
	}

	Combination(Combination &&c) {
		move(c);
	}

	~Combination() {
		erase();
	}

	Combination& operator=(const Combination &c) {
		if (this != &c) {
			erase();
			copy(c);
		}
		return *this;
	}

	Combination& operator=(Combination &&c) {
		if (this != &c) {
			erase();
			move(c);
		}
		return *this;
	}

	static Combination* createRandomCombination();
	void printSimilarity(const Combination &ultimate) const; // For example, prints two signs are in place and one is out of place, like this O | O | X | 

	friend istream& operator>>(istream &, Combination &);
	friend ostream& operator<<(ostream &, const Combination &);
	friend bool operator==(const Combination &, const Combination &);

};

#endif
