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
	string game;
	bool addingGame = false;
	bool program = false;

	cout << "\t\tWelcome to the Video Game Listing Program!\n";
	cout << "\nHere you can type in your favourite games and display them in a list.\n";
	cout << "Type 'show' to display all your games.\n";
	cout << "Type 'add' to all a game to the list. If you want to stop adding, simply type 'stop'.\n";
	cout << "Type 'remove', then the index number indicated to remove a game.\n";
	cout << "Type 'end' to finish the program.\n";

	do {
		cout << "\nWhat do you like to do?\n";
		cin >> game;

		if (game == "add") {
			cout << "What game do you like to add? \n";
			while (!addingGame) {
				cin >> game;
				if (game == "stop") {
					addingGame = true;
				}
				else {
					videoGames.push_back(game);
				}
			}
		}
		else if (game == "show") {
			cout << "\nIndex - Game\n";
			cout << "~~~~~~~~~~~~\n";
			for (int i = 0; i < videoGames.size();i++) {
				cout << i << "     - " << videoGames[i] << endl;
			}
		}
		else if (game == "end") {
			program = true;
		}

	} while (!program);

	return 0;
}