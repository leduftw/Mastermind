
#ifndef SETTINGS_H
#define SETTINGS_H

class Settings {

	static int lengthOfCombination, numberOfTries;

public:

	Settings() = delete;
	Settings(const Settings &) = delete;
	void operator=(const Settings &) = delete;

	static int getLengthOfCombination() {
		return lengthOfCombination;
	}

	static int getNumberOfTries() {
		return numberOfTries;
	}

	static void setLengthOfCombination(int len) {
		lengthOfCombination = len;
	}

	static void setNumberOfTries(int num) {
		numberOfTries = num;
	}

};

int Settings::lengthOfCombination = 4;
int Settings::numberOfTries = 6;

#endif
