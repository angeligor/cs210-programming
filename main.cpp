/*
CS210 Project Three - Corner Grocer
Author: Angel I. Rivera Perez
Professor: Sabahudin Tricic
File: main.cpp
Purpose: Minimal entry point that delegates all user interaction to the menu.
*/

#include <iostream>
#include "Menu.h"
using namespace std;

int main() {
	std::cout << "Corner Grocer (Project 3)\n";
	// All program behavior is driven by the menu loop for clarity and separation of concerns.
	RunMenu();
	return 0;
}