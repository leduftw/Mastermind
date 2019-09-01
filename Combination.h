
#ifndef COMBINATION_H
#define COMBINATION_H

#include <iostream>
#include <cstdlib>
#include <ctime>
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

	void del() {
		delete[] combination;
	}

public:

	Combination(int length = 4) {
		combination = new char[this->length = length];
	}

	Combination(const Combination &c) {
		copy(c);
	}

	Combination(Combination &&c) {
		move(c);
	}

	~Combination() {
		del();
	}

	Combination& operator=(const Combination &c) {
		if (this != &c) {
			del();
			copy(c);
		}
		return *this;
	}

	Combination& operator=(Combination &&c) {
		if (this != &c) {
			del();
			move(c);
		}
		return *this;
	}

	int getLength() const {
		return length;
	}

	static void createRandomCombination(Combination &c);
	void similarity(const Combination &) const;

	friend istream& operator>>(istream &, Combination &);
	friend ostream& operator<<(ostream &, const Combination &);
	friend bool operator==(const Combination &, const Combination &);

};

#endif
