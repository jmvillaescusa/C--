/*
	Questions

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	// Exercises 
	// 1. List of Games
	vector<string> videoGames;
	vector<string>::const_iterator iter;
	string game;
	int index;
	bool addingGame = false;
	bool program = false;

	cout << "\t\tWelcome to the Video Game Lister!\n";
	cout << "\nHere you can type in your favourite games and display them in a list.\n";
	cout << "Type 'show' to display all your games.\n";
	cout << "Type 'add' to add a game to the list, then press Enter for a new game\n"; 
	cout << "If you want to stop adding, simply type 'stop'.\n";
	cout << "Type 'remove', then the index number indicated to remove a game.\n";
	cout << "Type 'end' to finish the program.\n";

	do {
		cout << "\nWhat do you like to do?\n";
		cin >> game;

		if (game == "add") {
			addingGame = false;
			cout << "\nWhat game(s) do you like to add?\n";
			while (!addingGame) {
				getline(cin, game);
				if (game == "stop") {
					addingGame = true;
				}
				else {
					if (!game.empty()) {
						videoGames.push_back(game);
					}
					else {
						NULL;
					}
				}
			}
		}
		else if (game == "show") {
			cout << "\nIndex - Game\n";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			for (int i = 0; i < videoGames.size();i++) {
				cout << i << "     - " << videoGames[i] << endl;
			}
		}
		else if (game == "remove") {
			cout << "\nWhat do you like to remove? (Enter the index number): ";
			cin >> index;
			cout << "Removed " << videoGames.at(index) << ".\n";
			videoGames.erase(videoGames.begin() + index);
		}
		else if (game == "end") {
			cout << "\nThank you for using this program.\n";
			program = true;
		}

		/*
			2. They forgot to code the increment to each score
			   What is currently doing is just going through the vector with iter,
			   but not changing any score
		*/

		/*
			3. Create a list of words to shuffle with hints attached to them
			   Tell the program to pick a random word
			   Shuffle the letters of that word
			   Start the game loop
		           Introduce the player the game, and reveal the shuffuled word
				   Ask the player to either unshuffle the word or give them the hint when promped
				   If they get it right
				       Congratulate the player, and end the loop
				   Otherwise
				       Tell to keep trying, until they get it right
			   End the program
		*/

	} while (!program);

	return 0;
}