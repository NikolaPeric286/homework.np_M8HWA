// np_M8HWA.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author(s): Nikola Peric
// 
// Calculator: allows user to input values into a calculator and do basic 4 function  
// operations and stores the output value into the memory for use again.
//
// Classes:
//		Calculator
// 
// Inputs:
//		user inputed choice of action: char userInput
//		user inputed number into calculator: double userDouble
// 
// Outputs:
//		contents of array with operators and answer formated as equation
//
//

#include <iostream>
using namespace std;

class Calculator {


public:
	//constructors
	Calculator(); // default constructor: sets all vaues to 0
	//public member functions

	//    operations
	void add();       // The operator functions work by incrimenting through the array and modifying the first element of the array
	void subtract();  // with the elements of the array then clearing the used elements. In theory this should save computing time
	void multiply();  // as the operation is done, saved in the existing allocated memory for the array, and clears array all in 
	void divide();    // the same loop. Step by step is in function defenitions.

	//    user memory functions
	void insertNum(double& num);
	void clearArray();

private:

	double value_array[4];
	int value_count;
	//double answer; //********************
	//instruction file says to declare private member variable to store answer but, the 
	//first element of the array can be used to store the answer anyway as it carries
	//over between operations. During the operations the changes can be made straight
	//to the first element of the array and have the answer stored there instead of a local
	// variable. In theory this should be faster and more efficient.



};

int main(){
	char userChar; //: inputs the users choice of action from the list of options. Stores type char
	Calculator userCalc;
	double userDouble; // : stores users inputed value into the calculator if option e) enter is chosen type double

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
			//validates input
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

Calculator::Calculator() : value_count(0), value_array{ 0 } { // default constructor: sets all vaues to 0

}

void Calculator::insertNum(double& num) { // takes user input by reference and sets the next value in the array equal to it. value_count acts as the index of the next open space

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
	//double answer;
	if (value_count < 2) { 
		cout << "\nEnter at least two numbers for calculation!\n";
	}
	else {
		//answer = value_array[0]; // saves first value in temp variable

		cout << value_array[0]; // outputs first value before it is modified

		for (int i = 0; i < value_count - 1; i++) { // value_count - 1 ensures that the operator is not printed the last time

			
				cout << " + "; 

				cout << value_array[i + 1]; 

				value_array[0] = value_array[0] + value_array[i + 1]; // stores answer in first element of array instead of temp variable

				value_array[i + 1] = 0; // clears used ement from array. avoids clearArray() function call
				
		}

		cout << " = " << value_array[0] << "\n";
		value_count = 1; // inside of for loop clears the array out except the answer which is left in the first element. 
		                 //Sets value_count to 1 to represent. Avoids clearArray() and insertNum() function calls, since
						 //for loop is being used anyway
		                  

		//clearArray(); // clears array for next use
		//insertNum(answer); // stores temp answer variable into array above function scope to save for the next use
		//answer = 0; 
	}
}
void Calculator::subtract() {
	//double answer;
	if (value_count < 2) {
		cout << "\nEnter at least two numbers for calculation!\n";
	}
	else {
		cout << value_array[0]; // outputs first value before it is modified

		for (int i = 0; i < value_count - 1; i++) { // value_count - 1 ensures that the operator is not printed the last time


			cout << " - ";

			cout << value_array[i + 1];

			value_array[0] = value_array[0] - value_array[i + 1]; // stores answer in first element of array instead of temp variable

			value_array[i + 1] = 0; // clears used element from array. avoids clearArray() function call

		}

		cout << " = " << value_array[0] << "\n";
		value_count = 1;
		//clearArray();
		//insertNum(answer);
		//answer = 0;
	}
	
}
void Calculator::multiply() {
	//double answer;
	if (value_count < 2) {
		cout << "\nEnter at least two numbers for calculation!\n";
	}
	else {
		cout << value_array[0]; // outputs first value before it is modified

		for (int i = 0; i < value_count - 1; i++) { // value_count - 1 ensures that the operator is not printed the last time


			cout << " * ";

			cout << value_array[i + 1];

			value_array[0] = value_array[0] * value_array[i + 1]; // stores answer in first element of array instead of temp variable

			value_array[i + 1] = 0; // clears used element from array. avoids clearArray() function call

		}

		cout << " = " << value_array[0] << "\n";
		value_count = 1;

		//clearArray();
		//insertNum(answer);
		//answer = 0;
	}
	
}
void Calculator::divide() {
	//double answer;
	if (value_count < 2) {
		cout << "\nEnter at least two numbers for calculation!\n";
	}
	else {

		cout << value_array[0]; // outputs first value before it is modified

		for (int i = 0; i < value_count - 1; i++) { // value_count - 1 ensures that the operator is not printed the last time


			cout << " / ";

			cout << value_array[i + 1];

			value_array[0] = value_array[0] / value_array[i + 1]; // stores answer in first element of array instead of temp variable

			value_array[i + 1] = 0; // clears used element from array. avoids clearArray() function call

		}

		cout << " = " << value_array[0] << "\n";
		value_count = 1;
		//clearArray();
		//insertNum(answer);
		//answer = 0;
	}
	
}
