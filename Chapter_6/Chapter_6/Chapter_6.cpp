/*
	Questions
	1. Passing Value: Adv. - the program can pass any datatype
	                       - arguments are never changed, preventing unwanted side effects
	                  Dis. - if the program is passing large data, it will cost more memory and space

	2. Passing Reference: Adv. - passing these allow the function to change the value
	                           - since there is no copy, it can pass large data with no cost
							   - it can return multiple values from a function
	                      Dis. - arguments to reference parameters must be normal variables
							   - it could create confusion when using both passing by value and reference

	3. Passing Const Ref.: Adv. - can be used to gurantee the function won't change the argument 
	                       Dis. - similar as passing reference

	4. Returning Ref.: Adv. - efficiency
	                        - used to modify the original value
	                   Dis. - similar as passing reference

	5. This only matters on how difficult the programmer wants to make it for the user
	   For example, on the lowest difficulty, AI should make noticable mistake so the user can pick up on them
	   As the difficulty increases, AI will minimize it's mistakes and start implementing strategies to win
*/
#include <iostream>
#include <string>

using namespace std;

string askText(string prompt);
int askNumber(string prompt);
void tellStory(string &name, string &noun, int &number, string &bodyPart, string &verb);

int main()
{
	//Exercises
	// 1. Madlibs Revamp
	cout << "Welcome to Mad Lib.\n\n";
	cout << "Answer the following questions to help create a new story.\n";

	string name = askText("Please enter a name: ");
	string noun = askText("Please enter a plural noun: ");
	int number = askNumber("Please enter a number: ");
	string bodyPart = askText("Please enter a body part: ");
	string verb = askText("Please enter a verb: ");

	tellStory(name, noun, number, bodyPart, verb);

	/* 2. The datatypes must be the same when using the address-of operator
		  The value must be in either int or float*/

	/* 3. Returning theeMore does not change number variable
		  Instead, just add 3 to number than declaring a local variable
		  Then return number*/

	return 0;
}

string askText(string prompt) {
	string text;
	cout << prompt;
	cin >> text;
	return text;
}
int askNumber(string prompt) {
	int num;
	cout << prompt;
	cin >> num;
	return num;
}
void tellStory(string &name, string &noun, int &number, string &bodyPart, string &verb) {
	cout << "\nHere is your story:\n\n";
	cout << "The famous explorer " << name << " had nearly given up a life-long quest to find\n";
	cout << "The Lost City of " << noun << " when one day, the " << noun << " found the explorer.\n";
	cout << "Surrounded by " << number << " " << noun << ", a tear came to " << name << "'s " << bodyPart << ".\n";
	cout << "After all this time, the quest was finally over." << " And then, the " << noun << " promptly devoured " << name << ".\n";
	cout << "The moral of the story? Be careful what you " << verb << " for.\n";
}