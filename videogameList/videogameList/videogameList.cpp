/*
Pseudo Code
	Create a vector container for games
	Create a command prompt
	Create a int index
	Introduce the user to the program and establish rules
	Ask the user what to do (add, show, remove end)
	To add
	   Start a loop until the user types 'stop'
		   Ask the user what games do they like to add
		   If they say 'stop'
			   break the loop
		   Otherwise
			   add that entry to the vector
	To Show
	   Start a for loop
		   output each entry with an index number
	To Remove
	   Ask the user to input the index number accoring to the game
	   Remove that game from the vector
	To End
	   Thank the user for using the program
	   End the program
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> videoGames;

vector<string> toAdd();
void toShow();
void toRemove(int ind);

int main()
{
	int index;
	string command;
	bool program = false;

	cout << "\t\tWelcome to the Video Game Lister!\n";
	cout << "\nHere you can type in your favourite games and display them in a list.\n";
	cout << "Type 'show' to display all your games.\n";
	cout << "Type 'add' to add a game to the list, then press Enter for a new game\n";
	cout << "If you want to stop adding, simply type 'stop'.\n";
	cout << "Type 'remove', then the index number indicated to remove a game.\n";
	cout << "Type 'end' to finish the program.\n";
	cout << "\n\t\t***** PLEASE REPLACE EVERY ' ' WITH '-'. *****" << endl;

	do {
		cout << "\nWhat do you like to do?\n";
		cin >> command;

		if (command == "add") {
			videoGames = toAdd();
		}
		else if (command == "show") {
			toShow();
		}
		else if (command == "remove") {
			cout << "\nWhat do you like to remove? (Enter the index number): ";
			cin >> index;
			toRemove(index);
		}
		else if (command == "end") {
			cout << "\nThank you for using this program.\n";
			program = true;
		}

	} while (!program);

	return 0;
}

vector<string> toAdd() {
	string game;
	vector<string> list = videoGames;
	bool addingGame = false;
	cout << "\nWhat game(s) do you like to add?\n";
	while (!addingGame) {
		cin >> game;
		if (game == "stop") {
			addingGame = true;
		}
		else {
			list.push_back(game);
		}
	}
	return list;
}

void toShow() {
	cout << "\nIndex - Game\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	for (int i = 0; i < videoGames.size(); i++) {
		cout << i << "     - " << videoGames[i] << endl;
	}
}

void toRemove(int ind) {
	if (ind < videoGames.size()) {
		cout << "Removed " << videoGames.at(ind) << ".\n";
		videoGames.erase(videoGames.begin() + ind);
	}
	else {
		cout << "Index number is beyond the boundary." << endl;
	}
}