/*
	Questions
	1. Encapsulation helps saparate codes by keeping the details hidden, and only exchanges the return value when needed

	2. Globel variables make programs confusing bevause it can be difficult to keep track of their changing values
	   Limiting their usage is often recommended when programming

	3. Global constant allows the programmer to access them for a variety of uses
	   Unlike their variable counter part, constants do not change in value, therefore makes coding much more clearer
	   Only use them when they are needed in more than one area

	4. Optimizing code improves performance of the program
	   If the programmer attemps to optimize their code during the development process,
	   it could cause conflicts and errors in the program
	   It is recommended to optimize code by the end of the development process

	5. Software reuse is when a new software is created from predefined software compontents
	   Using these as building blocks for newer software systems
	   This benefits the game industry because it improves productivity and drecreases development time
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
using namespace std;

char toGuess(string &used);
void check(const string &THE_WORD, string &soFar, char &letter, int &wrong);

int getInput(int num);
string getInput(string text);

int main()
{
	// Exercises
	/*  1. The paramaters must be switched (low must be last in the list), due to how C++
		   reads right to left when looking at the parameters of a function */

	// 2. Hangman with functions
	/*const int MAX_WRONG = 8;

	vector<string> words;
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	words.push_back("JAYA");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];
	int wrong = 0;
	string soFar = string(THE_WORD.size(), '-');
	string used = "";

	cout << "Welcome to Hangman. Good luck!";

	while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
		cout << "\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";;
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
	*/

	// 3.
	int number;
	cout << "Enter a number: ";
	cin >> number;
	cout << "You've entered: " << getInput(number) << endl;
	string text;
	cout << "Enter a text: ";
	cin >> text;
	cout << "You've entered: " << getInput(text) << endl;

	return 0;
}

// Function Definitions
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

int getInput(int num) {
	return num;
}
string getInput(string text) {
	return text;
}