# Corner Grocer Item Tracker (C++)

A console program that reads a store's daily purchase file and reports how often each item was bought. Built for CS 210, Programming Languages, at Southern New Hampshire University.

**Summary of the Project and the Problem It Solves**

The Corner Grocer wants to rearrange its produce section and needs to know how often each item is purchased. The program reads a text file of items in the order they were bought and offers a four-option menu. Option 1 shows how many times one item was purchased. Option 2 lists every item with its count. Option 3 shows the same counts as a histogram of asterisks. Option 4 exits. When the program starts, it also writes a backup file named `frequency.dat` that lists every item and its count.

**What I Did Particularly Well**

I kept the data in a `GroceryItem` class with private fields for the item name and quantity, so the class has no input or output and can be reused in another application. I stored the items in a map from item name to `GroceryItem`, which makes counting and lookups quick. The input file is read again each time the user picks option 1, 2, or 3, so reports always match the current file. Invalid menu entries are rejected without crashing the program.

**Where I Could Enhance My Code**

- **Efficiency:** the search compares each stored name in lowercase. A map keyed by a lowercase version of the name would allow a direct lookup.
- **Security and safety:** smart pointers (`std::unique_ptr`) would replace the manual `new` and `delete` calls and remove the risk of a memory leak.
- **Flexibility:** the input file name is a constant in the code. Letting the user choose the file would make the program easier to reuse.

**Most Challenging Pieces and How I Handled Them**

Working with pointers and memory management was the hardest part, because each item in the map is stored as a pointer that has to be deleted before the map is reloaded. I worked through it by following the instructor's video and testing with the sample file until the counts matched a manual count. Resources I am adding to my support network: the instructor's recordings, the zyBooks chapters, and the course code guidelines.

**Transferable Skills**

Designing a class that keeps its data private, choosing a data structure that fits the problem (a map), reading and writing files, validating user input, and testing results against known values will all carry over to other projects and courses.

**How I Made the Program Maintainable, Readable, and Adaptable**

Every function has a comment block that describes what it does, its parameters, what it returns, and what it throws. Names follow one convention, constants are written in capital letters, and the menu choices are named constants and not typed numbers. The menu, file reading, and reporting are in separate functions, so a change in one place does not affect the others. Because the item data lives in its own class, a new field (such as an aisle number) can be added without reworking the rest of the program.

**Files**

- `CornerGrocer.cpp`: main program and menu
- `GroceryItem.h` and `GroceryItem.cpp`: the `GroceryItem` class
- `project_three_input_file.txt`: sample purchase data
