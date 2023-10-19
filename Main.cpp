// This file is contains our main() routine which determines where our 
// program execution begins and ends.
#include <iostream>
#include "MainMenu.h"

// Set up a pointer for tracking a linked list of Employees
// Display a menu allowing a user various choices, and process those choices
// Clean up any dynamically allocated memory before finishing
int main()
{	
	// a pointer to our linked list of employees.
	Employee* pEmployees = nullptr;

	bool exitMainMenu{ false };		// init to default value  // ask chris ******
	Command command{ Command::invalid };

	// display the main menu, allow the user to make choices, and handle the input
	do {
		displayMainMenu();
		command = getMenuCommand();
		handleMenuInput(pEmployees, command);
	} while (command != Command::exit);

	// cleanup! - deallocate any employees in our linked list before setting the list to nullptr;
	// TODO
    removeAllEmployee(pEmployees);

	return 0;
}
