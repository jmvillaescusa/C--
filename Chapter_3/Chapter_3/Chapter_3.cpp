/*
	Questions
	1. Galaga:
	   Ship - lives
	        - movement
			- fire
			- score
	   Commander - launch
	             - grappleBeam
				 - pointValue
				 - movement
	   Minion - launch
			  - fire
			  - pointValue
			  - movement

	2. Much more efficient and easier to code compared to individual variables
	   Simply call a certain element by the index number associated with it
	   
	3. Cannot increase/decrease size of array after initialized

	4. Operator overloading redefines a familiar operator for many different uses
	   There are no downsides to using this

	5. A text-based adventure game (Zork)
	   Business simulaion game (Lemonade Stand)
	   Survival strategy games (The Oregon Trail)
*/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	//Exercises
	// 1. Jumbled Words
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] = {
		{"wall", "Do you feel you're banging your head against something?"}, 
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it."},
		{"persistent", "Keep at it."},
		{"jumble", "It's what the game is all about."}
	};	

	int score = 0;
	srand(static_cast<unsigned int>(time(0)));
	int choice(rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD]; //word to guess
	string theHint = WORDS[choice][HINT]; //hint for word
	string jumble = theWord;
	int length = jumble.size();
	for (int i = 0; i < length; ++i) {
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
	int points = length;

	cout << "\t\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	cout << "The jumble is: " << jumble;

	string guess;
	while ((guess != theWord) && (guess != "quit")) {
		cout << "\n\nYour guess: ";
		cin >> guess;

		if (guess == "hint") {
			cout << theHint;
			points *= 0.75;
		}
		else if (guess == theWord) {
			cout << "Thats it! You guessed it!\n";
			score += points;
		}
		else {
			cout << "Sorry, that's not it";
			points--;
		}
	}

	cout << "\nThanks for playing.\n";
	cout << "Your score: " << score << "\n\n";

	/*
	   2. The code must initialize the the 'phrase' string variable in order to make it work

	   phrase = "Example";
	*/

	/*
	   3. On the char board line, the index variables must be switched, otherwise the code will not count properly

		char board[ROWS][COLUMNS] = ...
	*/

	return 0;
}