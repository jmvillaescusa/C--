#include <iostream>
using namespace std;

int main()
{
	int command;

	cout << "\t\t Welcome to my short story\n\n";
	cout << "Please press ENTER to continue text, then press the number accoring to the action.\n";
	cout << "===========================================================\n";
	cout << "You've suddenly entered a cave that you heard about a rumored treasure at the ends of this cave.";
	cin.ignore();
	cout << "\t1. Explore the cave\n";
	cout << "\t2. Exit\n\n";
	cout << "What do you do? ";
	cin >> command;

	if (command == 1) {
		cout << "\nMustering up all your courage, you went further to the depths of the cave.\n";
		cout << "You encounter two branching paths, and you must decide which path you should take.";
		cin.get();
		cin.ignore();
		cout << "\t1. Take the left path\n";
		cout << "\t2. Take the right path\n\n";
		cout << "What do you do? ";
		cin >> command;
		if (command == 1) {
			cout << "\nBy the end of this path, you encounter an old man, dressed in a red robe.\n";
			cout << "There are two torches on each side of him, illuminating the room you just entered.\n";
			cout << "In the middle, right in front of him, there is a bronzed sword with a green hilt.\n";
			cout << "The onl man speaks, 'It's dangerous to go alone! Take this.'\n";
			cin.get();
			cin.ignore();
			cout << "Creeped out, you hesitantly took the sword and decided to exit the cave.\n";
			cout << "You arrive home, and displayed the sword above the fireplace and never told anyone about it's origin.\n";
			cin.ignore();
		}
		else if (command == 2) {
			cout << "\nBy the end of this path, you encounter a small child(?) in a dark room.\n";
			cout << "Inside this room, there is dark grey bricks that walled the surroundings of this room.\n";
			cout << "The small child(?) says to you , 'Thank you Mario! But our princess is in another castle!'\n";
			cin.get();
			cin.ignore();
			cout << "What? You thought to your self. Who's this Mario?\n";
			cout << "What princess? This is probably some regal stuff that's beyong your comprehension.\n";
			cout << "And castle? That explains the interior walls.\n";
			cout << "You tell the child, 'You must've mistaken me for someone else, sorry for the intrusion.'\n";
			cout << "Awkwardly, you leave the scene and exited the cave, with no treasure at hand.\n";
			cin.ignore();
		}
	}
	else if (command == 2) {
		cout << "\n'Why am I inside this cave', you thought yourself.\n";
		cout << "The rumour of a treasure inside this cave is probably a hoax.\n";
		cout << "Unrelated, you remembered you had a turkey inside the oven that should be finished cooking.\n";
		cout << "You chose to leave this cave and went home.\n";
		cout << "'Maybe someone else will go to inside this cave.'\n";
		cin.ignore();
	}

	cout << "THE END\n";
	return 0;
}