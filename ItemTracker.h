/*
CS210 Project Three - Corner Grocer
File: ItemTracker.h
Purpose: Declare the ItemTracker class which loads items from a text file,
         counts frequencies, answers queries, and writes results to a data file.
I/O Format Requirements:
- Input dile: one item name per line (case-sensitive).
- Data file (frequency.dat): lines like "ItemName Count".
Design:
- Separation of concerns: ItemTracker does data work only (no UI/printing).
- Encapsulation: Internal map is private; callers use const queries.
- Error handling: bool returns + error messages.
*/

#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <string>
#include <unordered_map>
#include <vector>


class ItemTracker {
public:
	// Construct with a default path.
	explicit ItemTracker(const std::string& inputPath = "Project_Three_Input_File.txt");
	// Load and count items from the input file. Return false and sets errorMsg on failure.
	bool Load(std::string* errorMsg = nullptr);
	// Get frequency for a single item (0 if not present).
	int GetCount(const std::string& item) const;
	// Get a copy of all item (item, count) pairs for printing/histogram/file output.
	std::vector<std::pair<std::string, int>> GetAll() const;
	// Write "ItemName Count" per line to outputPath. Returns false on failure.
	bool WriteToFile(const std::string& outputPath, std::string* errorMsg = nullptr) const;

private:
	std::string inputPath_;                     // Path to input text file
	std::unordered_map<std::string, int> freq_; // Frequency table
};

#endif


