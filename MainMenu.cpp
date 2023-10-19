// See comments in MainMenu.h for general details on what each functin does.
#include <iostream>
#include "MainMenu.h"
#include <string>


// clear any characters from the (keyboard) input buffer
void ignoreLine() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// read and return an int from the console.  Keep trying if invalid until an int is returned.
int getIntFromUser() {
	while (true) {
		int guess;
		std::cin >> guess;

		if (std::cin.fail()) {
			std::cin.clear();
			ignoreLine();
			std::cerr << "Invalid input. Input must be a valid int.  Please try again.\n";
		}
		else
		{
			ignoreLine();
			return guess;
		}
	}
}

// output the menu choices to the console.
void displayMainMenu()
{
	std::cout << "\n";
	std::cout << "--- MENU ---\n";
	std::cout << "1) View Employees\n";
	std::cout << "2) Add Employee\n";
	std::cout << "3) Remove Employee\n";
    std::cout << "4) Remove All Employees\n";
	std::cout << "0) Exit\n";
	std::cout << "-------------\n";
	std::cout << "Select:";
}

// Attempt to read an int from the keyboard.  
// If there was a failure, clear the buffer and return -1.
Command getMenuCommand() {
	// read user input
	int input{ -1 };  // default 
	std::cin >> input;
	if (std::cin.fail()) {
		std::cin.clear();	// clear the failure
		input = -1;			// indicate an error
	}
	ignoreLine();	// ignore any extra input

	Command command = Command::invalid;	// default
	// match input with specific commands
	switch (input) {
	case 1: command = Command::viewEmployees; break;
	case 2: command = Command::addEmployee; break;
	case 3: command = Command::removeEmployee; break;
    case 4: command = Command::removeAllEmployee; break;
	case 0: command = Command::exit; break;
	}
	return command;
}

// This function is called when a user picks a selection from the menu.
// It determines what action to take depending on the menuItemSelected, 
// and calls the appropriate function.
// Returns true the selection was a request to exit menu, false otherwise.
void handleMenuInput(Employee*& pHead, Command command)
{
	switch (command)
    {
	case Command::viewEmployees:
		std::cout << ">> View Employees:\n";
		viewEmployees(pHead);
		break;
	case Command::addEmployee: {
		std::cout << ">> Add Employee:\n";
		std::cout << "Enter name:";
		std::string name;
		std::getline(std::cin, name);
		addNewEmployee(pHead, name);
	}
							 break;
	case Command::removeEmployee:
		std::cout << ">> Remove Employee:\n";
		std::cout << "Enter id:";
		removeEmployee(pHead, getIntFromUser());
		break;
    case Command::removeAllEmployee:
        std::cout << ">> Remove All Employee:\n";
        removeAllEmployee(pHead);
        break;
	case Command::exit:
		std::cout << "Exiting\n";
		break;
	default:
		std::cout << "Invalid input.\n";
		break;
	}
}

void viewEmployees(Employee* pHead) {
    if (pHead == nullptr) {
        std::cout << "empty list. " << '\n';
    }
    else {
		Employee* pCurrent = pHead ;

		// if a pointer is contain a not null address, 
		//while( pCurrent != nullptr)
		while (pCurrent) {
			std::cout << "[id: " << pCurrent->id << ", name: " << pCurrent->name << "]\n";
			pCurrent = pCurrent->pNext; // move to next employee
		}
		
    }
}

Employee* createEmployee(const std::string& name) {
	static int employeeID{ 0 };
    
	Employee* pEmployee = new Employee{ employeeID++, name, nullptr };
    return pEmployee;

}

void addNewEmployee(Employee*& pHead, const std::string& name) {
    Employee* pEmployee = createEmployee(name);
    pEmployee->pNext = pHead;	// set the new employee next pointer to point to current first employee
    pHead = pEmployee;	// update the head point to the new employee
}


NodeInfo getNodeInfo(Employee* pHead, int employeeID) {
    NodeInfo empeInfo;
    
    // Set default to nullptr
    empeInfo.pNode = nullptr;
    empeInfo.pParent = nullptr;
    
    while (pHead != nullptr) {
        if (pHead->id == employeeID) {
            empeInfo.pNode = pHead;
            return empeInfo;
        }
        empeInfo.pParent = pHead;
        pHead = pHead->pNext;
    }
    
    return empeInfo;
    
}


void removeEmployee(Employee*& pHead, int employeeID) {
    NodeInfo info = getNodeInfo(pHead, employeeID);
    
    if (info.pNode == nullptr) {
        std::cout << "Error: employee ID:" << employeeID << " not found" << std::endl;
    }
    
    if (info.pParent == nullptr) {
        pHead = info.pNode->pNext;
        std::cout << "Remove ID:" << employeeID << std::endl;
        delete info.pNode;
    } else {
		info.pParent->pNext = info.pNode->pNext;
        std::cout << "Remove ID:" << employeeID << std::endl;
        delete info.pNode;
    }
}


void removeAllEmployee(Employee*& pHead) {
    Employee* empeInfo;
    while (pHead != nullptr) {
        empeInfo = pHead;
        pHead = pHead->pNext; // move to the next
        delete empeInfo;
    }
    std::cout << "All Employee killed!" << std::endl;
}


