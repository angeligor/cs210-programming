/*CS210 Project Three - Corner Grocer
File: Menu.cpp
Purpose: Implement the interactive menu options
Mapping:
1) Individual Frequency: print "Item Count" for a user-provided item.
2) Overall Frequency: print every item as "ItemName Count" (one per line).
3) Histogram: print "ItemName ****" where the numbers of '*' equals the count.
4) Exit: write frequency.dat (same "ItemName Count" format) and terminate.
*/

#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

#include "Menu.h"
#include "ItemTracker.h"

// helpers (UI-only).
/*
@brief read an integer menu choice in the [range [1,4].
@return The validated user choice.
*/
static int ReadMenuChoice() {
	int choice;
	while (true) {
		std::cout << "\n==== Corner Grocer ====\n"
			"1) Search for an item\n"
			"2) Print all item frequencies\n"
			"3) Print histogram\n"
			"4) Exit (and write frequency.dat)\n"
			"Enter choice (1-4): ";
		if (std::cin >> choice && choice >= 1 && choice <= 4) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return choice;
		}
		std::cout << "Invalid input. Please enter a number 1-4.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

// @brief Print each item as "ItemName Count" (alphabetically for readability).
static void PrintAll(const std::vector<std::pair<std::string, int>>& items) {
	std::vector<std::pair<std::string,int>> sorted = items;
	std::sort(sorted.begin(), sorted.end(),
		[](const auto& a, const auto& b) { return a.first < b.first; });

	for (const auto& kv : sorted) {
		std::cout << kv.first << " " << kv.second << '\n';
	}
}

// @brief Print a simple histogram: "ItemName ****".
// @param mark Character used for the bar (default '*').

static void PrintHistogram(const std::vector<std::pair<std::string,int>>& items, char mark = '*') {
	std::vector<std::pair<std::string,int>> sorted = items;
	std::sort(sorted.begin(), sorted.end(),
		[](const auto& a, const auto& b) {return a.first < b.first; });

	for (const auto& kv : sorted) {
		std::cout << kv.first << " ";
		for (int i = 0; i < kv.second; ++i) {
			std::cout << mark;
		}
		std::cout << '\n';
	}
}

// Menu Driver
void RunMenu() {
	ItemTracker tracker;
	std::string err;
	if (!tracker.Load(&err)) {
		std::cout << "ERROR: " << err << '\n';
		return;
	}

	while (true) {
		int choice = ReadMenuChoice();

		if (choice == 1) {
			// Option 1 - Individual Frequency
			std::cout << "Enter item name to search: ";
			std::string item;
			std::getline(std::cin, item);
			if (item.empty()) {
				std::cout << "Item name connot be empty.\n";
				continue;
			}
			std::cout << item << " " << tracker.GetCount(item) << '\n';
		}
		else if (choice == 2) {
			// Option 2 - Overall Frequency
			auto all = tracker.GetAll();
			if (all.empty()) {
				std::cout << "(No items loaded.)\n";
			}
			else {
				PrintAll(all);
			}
		}
		else if (choice == 3) {
			// Option 3 - Histogram
			auto all = tracker.GetAll();
			if (all.empty()) {
				std::cout << "(No items loaded.)\n";
			}
			else {
				PrintHistogram(all, '*');
			}
		}
		else if (choice == 4) {
			// Option 4 - Exit and Data File Creation
			std::string outErr;
			if (!tracker.WriteToFile("frequency.dat", &outErr)) {
				std::cout << "Failed to write frequency.dat: " << outErr << '\n';
			}
			else {
				std::cout << "Wrote frequency.dat\n";
			}
			std::cout << "Goodbye!\n";
			break; // exit the program
		}
	}
}