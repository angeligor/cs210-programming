/*
CS210 Project Three - Corner Grocer
File: ItemTracker.cpp
Purpose: Implement file loading, counting, queries, and data file writing.
*/

#include "ItemTracker.h"
#include <fstream>
#include <sstream>
#include <iostream>

ItemTracker::ItemTracker(const std::string& inputPath)
	: inputPath_(inputPath) {}

/*Load:
   Reads one item per line from inputPath_
   Ignores empty/whitespace-only lines
   Populates freq_ with exact (case-sensitive) keys
*/

bool ItemTracker::Load(std::string* errorMsg) {
	std::ifstream in(inputPath_);
	if (!in.is_open()) {
		if (errorMsg) *errorMsg = "Could not open input file: " + inputPath_;
		return false;
	}

	std::string line;
	while (std::getline(in, line)) {
		// Trim simple whitespace at both ends.
		while (!line.empty() && (line.back() == '\r' || line.back() == '\n' || line.back() == ' ' || line.back() == '\t'))
			line.pop_back();
		std::size_t start = 0;
		while (start < line.size() && (line[start] == ' ' || line[start] == '\t'))
			++start;

			if (start < line.size()) {
				std::string item = line.substr(start);
				++freq_[item]; // Count exact spelling (case sensitive).
		}
	}
	return true;
}

// GetCount: returns 0 if item not present.
int ItemTracker::GetCount(const std::string& item) const {
	auto it = freq_.find(item);
	return (it == freq_.end()) ? 0 : it->second;
}

// GetAll: Returns a copy so callers can sort/print without touching internals.
std::vector<std::pair<std::string, int>> ItemTracker::GetAll() const {
	std::vector<std::pair<std::string, int>> vec;
	vec.reserve(freq_.size());
	for (const auto& kv : freq_) vec.push_back(kv);
	return vec;
}

// WriteToFile: Writes "Item Count" per line.
bool ItemTracker::WriteToFile(const std::string& outputPath, std::string* errorMsg) const {
	std::ofstream out(outputPath);
	if (!out.is_open()) {
		if (errorMsg) *errorMsg = "Could not open output file: " + outputPath;
		return false;
	}
	for (const auto& kv : freq_) {
		out << kv.first << ' ' << kv.second << '\n';
	}
	return true;
}