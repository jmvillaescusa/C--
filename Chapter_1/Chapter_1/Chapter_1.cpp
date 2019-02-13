/*
	Questions
	1. Fast - since C++'s design goals is performance, it has access to assembly language, allowing it to comminicate directly to the computer's hardware
	   Flexible - supports different styles of programming, and does not force any of them on the programmer
	   Well supported - because of its long history in the gaming industry, there's a large of assets to the programmer, greatly speeding up the process of writing a new game

	2. Employing the using directive grants the programmer access to a number of std prefixes, but the programmer may not use all of them

	3. Defining a new mane for existing types allows quicker access to that combined type for initialising new variables

	4. ++variable/--variable - prefix increment operator - will increase/decrease the variable value by 1 first in a complex equation
	   variable++/variable-- - postfix increment operator - will increase/decrease the variable value by 1 after the complex equation finishes

	5. Constants are used for variables with a unchangable value, often seen with all caps.
	   They are for keeping the coding more consistent.
	   Examples include point values.
*/

#include "pch.h"
#include <iostream>
using namespace std;

// Exercises
/* 1. int score; - good - simple, discriptive and easy to code
	  string playerName; - good - discriptive and easy to code/read
	  int high_score; - good - similar to playerName
	  int s; - bad - too ambiguous to describe
	  int playerTwoBonusForRoundOne; - bad - too difficilt to code (consistently speaking) due to its length
	  string playerScore - bad - wrong type */

char pause;
int numberOne;
int numberTwo;
int numberThree;

int main()
{
	// 2. 
	cout << "Seven divided by three is " << 7 / 3 << endl;  // 2
	//since both vales are whole numbers, the result will be a whole number
	cout << "Seven divided by three is " << 7.0 / 3 << endl; // 2.33333
	//one of the values is a float, thus the result will be shown as a float
	cout << "Seven divided by three is " << 7.0 / 3.0 << endl << endl; //  2.33333
	//same reason as above

	// 3. 
	cout << "Enter the first number: \n";
	cin >> numberOne;
	cout << "Enter the second number: \n";
	cin >> numberTwo;
	cout << "Enter the last number: \n";
	cin >> numberThree;
	cout << "\nAverage: " << (numberOne + numberTwo + numberThree) / 3; 

	cin >> pause;
	return 0;
}