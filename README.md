## Module eight journal reflection
**Project Summary**

- Reads 'Project_Three_Input_File.txt' (one item per line), counts occurrences, and provides a menu to:
(1) Query a single item,
(2) Lists all frequencies,
(3) Show a histogram,
(4) Writes frequency.dat on exit.

**What I did well**
 
- Separated concerns (data vs. UI). 
- Wrote clear, commented code.
- Used std::unordered_map for O(1) lookups.
- Added input/file error handling with concise user messages.

**Where I could enhance the code**

- Case-insensitive search and normalization.
- Sorting by frequency (desc) in options 2/3.
- Unit tests for 'ItemTracker'.
- More robust stream-state checks during read/write.

**Most challenging parts and how I overcame them**
 
- File-path/working-directory issues and getting the menu's input validation right.
- I solved them by checking stream state, and testing with representative inputs.

**Transferable skills**

- C++ STL containers/iterators, file I/O, error handling, modular design, version control, and writing documentation/screenshots for stakeholders.

**Maintainable, readable, adaptable**

- 'ItemTracker' owns all data logic; 'Menu' owns I/O; 'main()' is minimal.
- const-correct interfaces, header guards, and small helpers keep the code easy to extend without changing the UI.
