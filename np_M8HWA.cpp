// np_M8HWA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Calculator {


public:

	Calculator();

	void add();
	void subtract();
	void multiply();
	void divide();

	void insertNum(double num);
	void clearArray();

private:

	double value_array[4];
	int value_count;
	double answer;


};

int main(){
	char userChar;
	Calculator userCalc;
	double userDouble;

	cout << "CALCULATOR\n";
	cout << "What would you like to do?\n";

	do {
		
		cout << "\ne) Enter Number\n";
		cout <<   "a) Add\n";
		cout <<   "s) Subtract\n";
		cout <<   "m) Multiply\n";
		cout <<   "d) Divide\n";
		cout <<   "c) Clear Calculator\n";
		cout <<   "q) Quit\n";
		cout << "\nChoice: ";

		cin >> userChar;
		

		while (userChar != 'e' && userChar != 'a' && userChar != 's' && userChar != 'm' && userChar != 'd' && userChar != 'c' && userChar != 'q') {

			cout << "\nInvalid input. Try again!\n";
			cout << "Choice: ";
			cin >> userChar;
			
		}

		

		switch (userChar) {
			
		case 'e':
			cout << "Enter a number into your calculator: ";
			cin >> userDouble;
			userCalc.insertNum(userDouble);
			break;
		case 'a':
			userCalc.add();
			break;
		case 's':
			userCalc.subtract();
			break;
		case 'm':
			userCalc.multiply();
			break;
		case 'd':
			userCalc.divide();
			break;
		case 'c':
			userCalc.clearArray();
			cout << "\nAll values are cleared!\n";
			break;
		case 'q':
			break;
		}

	} while (userChar != 'q' && userChar != 'Q');

	cout << "\nQuitting... Goodbye!\n\n\n";

	return 0;
}

Calculator::Calculator() : value_count(0), answer(0), value_array{ 0 } {

}

void Calculator::insertNum(double num) {

	if (value_count < 4) {

		value_array[value_count] = num;


		value_count++;
	}
	else {

		cout << "\nFailed to enter the current number!\nNo room left for a new number!\n";


	}


}
void Calculator::clearArray() {

	

	for (int i = 0; i < 4; i++) {
		value_array[i] = 0;
	}
	value_count = 0;

}

void Calculator::add() {

	if (value_count < 2) {
		cout << "\nEnter at least two numbers for calculation!\n";
	}
	else {
		answer = value_array[0];
		for (int i = 0; i < value_count; i++) {

			

			cout << value_array[i];

			if (i < value_count - 1 ){
				answer = answer + value_array[i + 1];
				cout << " + ";
			}

			

		}
		cout << " = " << answer << "\n";

		clearArray();
		insertNum(answer);
		answer = 0;
	}

	

	

}
void Calculator::subtract() {
	if (value_count < 2) {
		cout << "\nEnter at least two numbers for calculation!\n";
	}
	else {
		answer = value_array[0];
		for (int i = 0; i < value_count; i++) {

			

			cout << value_array[i];

			if (i < value_count -1) {
				answer = answer - value_array[i + 1];
				cout << " - ";
			}
		}
		cout << " = " << answer << "\n";

		clearArray();
		insertNum(answer);
		answer = 0;
	}
	
}
void Calculator::multiply() {
	if (value_count < 2) {
		cout << "\nEnter at least two numbers for calculation!\n";
	}
	else {
		answer = value_array[0];
		for (int i = 0; i < value_count; i++) {

			

			cout << value_array[i];

			if (i < value_count - 1) {
				answer = answer * value_array[i + 1];
				cout << " * ";
			}

		}
		cout << " = " << answer << "\n";

		clearArray();
		insertNum(answer);
		answer = 0;
	}
	
}
void Calculator::divide() {
	if (value_count < 2) {
		cout << "\nEnter at least two numbers for calculation!\n";
	}
	else {
		answer = value_array[0];
		for (int i = 0; i < value_count; i++) {

			

			cout << value_array[i];

			if (i < value_count - 1) {
				answer = answer / value_array[i + 1];
				cout << " / ";
			}
		}
		cout << " = " << answer << "\n";

		clearArray();
		insertNum(answer);
		answer = 0;
	}
	
}
