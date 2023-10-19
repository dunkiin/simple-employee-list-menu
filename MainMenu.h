#ifndef MAINMENU_H
#define MAINMENU_H

// The MainMenu (.h & .cpp) file contains the function declarations used to 
// Present a main menu which allows a user to view, add, and remove employees.
// The list of employees is implemented with a linked list, and most of the
// processing functions get passed a pointer to the first element of the 
// list (Employee* pHead).

#include <string>

// A command set of operations that can be used with our Menu.
enum class Command{ viewEmployees, addEmployee, removeEmployee, removeAllEmployee, exit, invalid };

// a struct to represent an Employee (each instance forms a node of a linked list
// used to store employees.
struct Employee {
	int id;
	std::string name;
	Employee* pNext;
};

// A struct used to return multiple return values from the getNodeInfo() function.
// getNodeInfo() traverses the list looking for a target node (and its parent node).
// NodeInfo contains info needed to facilitate node insertion & deletion in the list.
struct NodeInfo {
	Employee* pNode;	// a pointer to the "target" node.
	Employee* pParent;	// a pointer to the node prior to pNode (nullptr if node is at the front)
};

/// <summary>
/// Clear any characters from the (keyboard) input buffer
/// </summary>
void ignoreLine();

/// <summary>
/// Get the int input from the user.
/// </summary>
/// <returns>an int from the console</returns>
int getIntFromUser();

/// <summary>
/// display the main menu
/// </summary>
void displayMainMenu();

/// <summary>
/// fetch the user input for menu number
/// </summary>
/// <returns>a menu command from user input</returns>
Command getMenuCommand();

// Given a Command, this will determine the appropriate function to call.
// - param 1: (given) a pointer to the front of the list of employees (passed by reference)
// - param 2: a Command (enum) representing the action to be taken.
void handleMenuInput(Employee*& pHead, Command command);

/// <summary>
/// Output All employees to the console.
/// </summary>
/// <param name="pHead"></param>
void viewEmployees(Employee* pHead);

/// <summary>
/// Create a new employee struct on the heap.
/// </summary>
/// <param name="name"></param>
/// <returns>A pointer to the dynamically allocated Employee struct</returns>
Employee* createEmployee(const std::string& name);

/// <summary>
/// Create a new employee node, then add it to the list
/// </summary>
/// <param name="pHead"></param>
/// <param name="name"></param>
void addNewEmployee(Employee*& pHead, const std::string& name);

/// <summary>
/// Search through the list for a node with the given id.
/// </summary>
/// <param name="pHead"></param>
/// <param name="employeeID"></param>
/// <returns>A NodeInfo struct. </returns>
NodeInfo getNodeInfo(Employee* pHead, int employeeID);

/// <summary>
/// Removes an employee node with the given id from the list.
/// </summary>
/// <param name="pHead"></param>
/// <param name="employeeID"></param>
void removeEmployee(Employee*& pHead, int employeeID);

/// <summary>
/// Removes all employee in the list.
/// </summary>
/// <param name="pHead"></param>
void removeAllEmployee(Employee*& pHead);

#endif
