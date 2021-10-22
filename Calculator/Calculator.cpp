#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

bool OperatorSelected = false, dot = false;
int Operator = 0, OperationCompleted = 0, keyinput;
double a, b;
string Expression = "";



bool lengthCheck() {
	if (Expression.find(".") == -1) {
		if (Expression.length() < 16) {
			return true;
		}
	}
	else if (Expression.length() < 17) {
		return true;
	}
	else {
		return false;
	}
}

void printDigit(const char number) {
	if (OperatorSelected == true || (Expression == "0" && OperatorSelected == true)) {
		OperatorSelected = false;
		OperationCompleted = 0;
		Expression = number;
	}
	else if (OperatorSelected == false && OperationCompleted == 0 && lengthCheck() == true) {
		if (Expression != "0") {
			Expression += number;
		}
		else {
			Expression = number;
		}
	}
}

void printZero() {
	if (OperatorSelected == true) {
		OperatorSelected = false;
		OperationCompleted = 0;
		Expression = "0";
	}
	else if (Expression != "0" && OperatorSelected == false && OperationCompleted == 0 && lengthCheck() == true) {
		Expression += "0";
	}
}

void printDot() {
	if (OperatorSelected == true || Expression == "") {
		OperatorSelected = false;
		OperationCompleted = 0;
		Expression = "0.";
	}
	else {
		if (Expression.find(".") == -1 && lengthCheck() == true && OperationCompleted == 0) {
			Expression += ".";
		}
	}
}

void deleteDigit() {
	if (OperatorSelected == false && Expression != "" && OperationCompleted == 0) {
		Expression = Expression.substr(0, Expression.length() - 1);
	}
}


int main()
{
	while (!_kbhit());
	while (true) {
		keyinput = _getch();
		switch (keyinput) {
		case 8:
			deleteDigit();
			break;
		case 46:
			printDot();
			break;
		case 48:
			printZero();
			break;
		case 49:
			printDigit('1');
			break;
		case 50:
			printDigit('2');
			break;
		case 51:
			printDigit('3');
			break;
		case 52:
			printDigit('4');
			break;
		case 53:
			printDigit('5');
			break;
		case 54:
			printDigit('6');
			break;
		case 55:
			printDigit('7');
			break;
		case 56:
			printDigit('8');
			break;
		case 57:
			printDigit('9');
			break;
		}
		system("cls");
		cout << Expression;

	}
}
