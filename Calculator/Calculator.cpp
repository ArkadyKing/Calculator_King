#include <iostream>
#include <conio.h>
#include <string>
#include "Header.h"
using namespace std;
using namespace CalcF;

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

void ClearAll() {
	Expression = "";
	OperatorSelected = false;
	dot = false;
	OperationCompleted = 0;
	Operator = 0;
}

void subEQ() {
	Expression = to_string(a);
	OperationCompleted = Operator;
	Operator = 0;
}
void EQ() {
	if (OperatorSelected == false && Expression != "" && Expression != "-") {

		switch (OperationCompleted) {
		case 0:
		case 5:
		case 6:
		case 7:
		case 8:
			switch (Operator) {
			case 0:
				a = stod(Expression);
				break;
			case 1:
				b = stod(Expression);
				a = divF(a,b);
				subEQ();
				break;
			case 2:
				b = stod(Expression);
				a = multF(a, b);
				subEQ();
				break;
			case 3:
				b = stod(Expression);
				a = subF(a, b);
				subEQ();
				break;
			case 4:
				b = stod(Expression);
				a = plusF(a, b);
				subEQ();
				break;
			}
			break;
		case 1:
			a = divF(a, b);
			Expression = to_string(a);
			break;
		case 2:
			a = divF(a, b);
			Expression = to_string(a);
			break;
		case 3:
			a = subF(a, b);
			Expression = to_string(a);
			break;
		case 4:
			a = plusF(a, b);
			Expression = to_string(a);
			break;
		}

	}
}
void DIVIDE() {
	if (Expression != "" && Expression != "-") {
		OperationCompleted = 0;
		EQ();
		OperatorSelected = true;
		Operator = 1;
	}
}
void MULTIPLY() {
	if (Expression != "" && Expression != "-") {
		OperationCompleted = 0;
		EQ();
		OperatorSelected = true;
		Operator = 2;
	}
}
void SUBSTRACT() {
	if (Expression == "") {
		Expression = "-";
	}
	else if (Expression != "" && Expression != "-") {
		OperationCompleted = 0;
		EQ();
		OperatorSelected = true;
		Operator = 3;
	}
}
void PLUS() {
	if (Expression == "-") {
		Expression = "";
	}
	else if (Expression != "" && Expression != "-") {
		OperationCompleted = 0;
		EQ();
		OperatorSelected = true;
		Operator = 4;
	}
}
void XX() {
	if (Expression != "" && Expression != "-") {
		Expression = to_string(xF(stod(Expression)));
		OperationCompleted = 5;
		OperatorSelected = false;
	}
}
void SQR() {
	if (Expression != "" && Expression != "-") {
		Expression = to_string(sF(stod(Expression)));
		OperationCompleted = 6;
		OperatorSelected = false;
	}
}
void LN() {
	if (Expression != "" && Expression != "-") {
		Expression = to_string(xF(stod(Expression)));
		OperationCompleted = 7;
		OperatorSelected = false;
	}
}
void LG() {
	if (Expression != "" && Expression != "-") {
		Expression = to_string(log10(stod(Expression)));
		OperationCompleted = 8;
		OperatorSelected = false;
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
		case 224:
			ClearAll();
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
		case 47:
			DIVIDE();
			break;
		case 42:
			MULTIPLY();
			break;
		case 45:
			SUBSTRACT();
			break;
		case 43:
			PLUS();
			break;
		case 115:
		case 235:
			SQR();
			break;
		case 120:
		case 231:
			XX();
			break;
		case 108:
		case 164:
			LN();
			break;
		case 76:
		case 132:
			LG();
			break;
		case 13:
			EQ();
			break;
		}
		system("cls");
		cout << Expression << endl;

		switch (Operator) {
		case 1:
			cout << "/";
			break;
		case 2:
			cout << "*";
			break;
		case 3:
			cout << "-";
			break;
		case 4:
			cout << "+";
			break;
		}
	}
}
