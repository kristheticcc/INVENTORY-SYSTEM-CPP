# INVENTORY SYSTEM (C++)

This project is a simple inventory management system written in C++. It allows users to add, delete, and display items in an inventory list. The system uses C++ features like classes, objects, file handling, and Standard Template Library (STL) containers and iterators.

## Features

- **Add items**: Add new items to the inventory with their name, price, and quantity.
- **Remove items**: Remove an item from the inventory by specifying the item number.
- **Display items**: View the list of items stored in the inventory from the file.
- **Persistence**: The system saves and loads items from a text file ("Item_Inventory.txt") to persist the data even after closing the program.

## Technologies Used

- **C++** programming language
- **Standard Template Library (STL)**:
  - Containers: vector
  - Iterators
- **File Handling**: Writing and reading (using operator overloading) from a text file ("Item_Inventory.txt")

## How to Run

### Prerequisites

- Ensure you have a C++ compiler (such as `g++`) installed.

### Steps

1. **Clone the repository**:

   ```bash
   git clone https://github.com/kristheticcc/INVENTORY-SYSTEM-CPP.git
2. Navigate to project folder:
   cd INVENTORY-SYSTEM-CPP
3. Compile the program:
   g++ proj1.cpp -o inventory-system
4. Run the program
   ./inventory-system

Program Workflow:

Upon running the program, you’ll be prompted to input the number of items to add to the inventory.
You will then be able to:

Add items: Input item details (name, price, amount).
Delete items: Remove an item based on its position in the inventory.
Display items: View the list of items stored in the file.
Exit: Exit the program.
The inventory data is saved in the Item_Inventory.txt file for future reference, allowing the program to access the updated list every time it runs.

Example Usage

Here’s how the program looks when running:
Enter the number of items: 2
Enter for 1th item:
Item Name: Pen
Item Price: 2.5
Item Amount: 30
Enter for 2th item:
Item Name: Eraser
Item Price: 3.5
Item Amount: 60

Items have been added to the list and can be viewed in file.

--------------------MENU--------------------
1. Add items into the list
2. Delete item from the list
3. Display item list from file in console
4. Exit program
____________________________________________
Enter your choice from menu: 3
Reading items from file and displaying them:
Pen | 2.5 | 30
Eraser | 3.5 | 60
--------------------MENU--------------------
1. Add items into the list
2. Delete item from the list
3. Display item list from file in console
4. Exit program
____________________________________________
Enter your choice from menu: 4
Program exit!!!
---

## Author

This project was created by Krish Makwana

GitHub: https://github.com/kristheticcc

