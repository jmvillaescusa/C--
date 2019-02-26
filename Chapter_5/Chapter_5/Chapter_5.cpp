/*
	Questions
	1. Encapsulation helps saparate codes by keeping the details hidden, and only exchanges the return value needed

	2.

	3.

	4.

	5.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include "Chapter_5.h"
using namespace std;

char toGuess(string &used);
void check(const string &THE_WORD, string &soFar, char &letter, int &wrong);

int main()
{
	// Exercises
	/*
		1. The paramaters must be switched (low must be last in the list), due to how C++
		   reads right to left when looking at the parameters of a function
	*/

	// 2. 
	const int MAX_WRONG = 8;

	vector<string> words;
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];
	int wrong = 0;
	//string soFar(THE_WORD.size(), "-");
	string soFar = string(THE_WORD.size(), '-');
	string used = "";

	cout << "Welcome to Hangman. Good luck!";

	while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
		cout << "\n\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";;
		cout << "\nYou've used the following letters:\n" << used << endl;
		cout << "\nSo far, the word is:\n" << soFar << endl;

		char letter = toGuess(used);
		check(THE_WORD, soFar, letter, wrong);
	}

	if (wrong == MAX_WRONG) {
		cout << "\nYou've been hanged!";
	}
	else {
		cout << "\nYou guessed it!";
	}

	cout << "\nThe word was " << THE_WORD << endl;

	return 0;
}

char toGuess(string &used) {
	char guess;
	cout << "Enter your guess: ";
	cin >> guess;
	guess = toupper(guess);
	while (used.find(guess) != string::npos) {
		cout << "You've already guessed " << guess << endl;
		cout << "Enter your guess: ";
		cin >> guess;
		guess = toupper(guess);
	}
	used += guess;
	return guess;
}
void check(const string &THE_WORD,string &soFar, char &letter, int &wrong) {
	if (THE_WORD.find(letter) != string::npos) {
		cout << "That's right! " << letter << " is in the word.\n";

		for (int i = 0; i < THE_WORD.length(); i++) {
			if (THE_WORD[i] == letter) {
				soFar[i] = letter;
			}
		}
	}
	else {
		cout << "Sorry, " << letter << " isn't in the word.\n";
		++wrong;
	}
}