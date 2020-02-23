
#ifndef SETTINGS_H
#define SETTINGS_H

// Singleton pattern
class Settings {

	int lengthOfCombination = 4, numberOfTries = 6;

	Settings() { }

public:

	static Settings& getInstance() {
		static Settings s;
		return s;
	}

	Settings(const Settings &) = delete;
	void operator=(const Settings &) = delete;

	int getLengthOfCombination() const {
		return lengthOfCombination;
	}

	int getNumberOfTries() const {
		return numberOfTries;
	}

	void setLengthOfCombination(int len) {
		lengthOfCombination = len;
	}

	void setNumberOfTries(int num) {
		numberOfTries = num;
	}

};

#endif
