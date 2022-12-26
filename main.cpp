#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>

using namespace std;

bool isUpper(char c) {
	return c >= 'А' && c <= 'Я';
}

bool isLower(char c) {
	return c >= 'а' && c <= 'я';
}

char toUpper(char c) {
	if (isLower(c)) {
		return c - 32;
	}
	return c;
}

char toLower(char c) {
	if (isUpper(c)) {
		return c + 32;
	}
	return c;
}

bool isLetter(char c) {
	return isUpper(c) || isLower(c);
}

void write(vector<char>& word, vector<char>& foundLetters, ofstream& outputFile) {
	if (word.size() > 0) {
		for (size_t i = 0; i < word.size() - 1; i++) {
			char left = toLower(word[i]);
			char right = toLower(word[i + 1]);

			if (left == right) {
				word[i] = toUpper(left);
				word[i + 1] = toUpper(right);

				if (find(foundLetters.begin(), foundLetters.end(), left) == foundLetters.end()) {
					foundLetters.push_back(left);
				}
			}
		}

		for (size_t i = 0; i < word.size(); i++) {
			std::cout << word[i];
			outputFile << word[i];
		}
		word.clear();
		if (foundLetters.size() > 0) {
			std::cout << '(';
			outputFile << '(';
			for (size_t i = 0; i < foundLetters.size(); i++) {
				cout << foundLetters[i];
				outputFile << foundLetters[i];
			}

			std::cout << ')';
			outputFile << ')';

			foundLetters.clear();
		}
	}
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	ifstream inputFile(".\\input.txt");
	if (!inputFile.good()) {
		std::cout << "input.txt не удалось открыть";
		std::cin.get();
		return -1;
	}
	ofstream outputFile(".\\output.txt");

	char c;
	std::vector<char> word;
	std::vector<char> foundLetters;

	while (!inputFile.eof()) {
		inputFile.get(c);
		if (isLetter(c)) {
			word.push_back(c);
		}
		else {
			write(word, foundLetters, outputFile);
			cout << c;
			outputFile << c;
		}
		//inputFile.peek();
	}
	write(word, foundLetters, outputFile);

	return 0;
}
