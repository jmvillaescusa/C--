#include <iostream>
using namespace std;

int main()
{
	int command;
	
	cout << "You've suddenly entered a cave that you heard about a rumored treasure at the ends of this cave.\n";
	cout << "1. Explore the cave\n";
	cout << "2. Exit\n\n";
	cout << "What do you do? ";
	cin >> command;

	if (command == 1) {
		cout << "Mustering up all your courage, you went further to the depths of the cave.\n";
		cout << "You encounter two branching paths, and you must decide which path you should take.\n";
		cout << "1. Take the left path\n";
		cout << "2. Take the right path\n\n";
		cout << "What do you do? ";
		cin >> command;
		if (command == 1) {
			cout << "By the end of this path, you encounter an old man, dressed in a red robe.\n";
			cout << "There are two torches on each side of him, illuminating the room you just entered.\n";
			cout << "In the middle, right in front of him, there is a bronzed sword with a green hilt.\n";
			cout << "The ond man says, 'It's dangerous to go alone! Take this.'\n\n";
			cout << "Creeped out, you hesitantly took the sword and decided to exit the cave.\n";
		}
	}

	return 0;
}