#include <iostream>
#include <string>
#include "MainMenu.h"

//#define TEST_SUITE
#ifdef TEST_SUITE
namespace TestSuite {

	// This method displays a condensed version of the list on a single line.
	// It is intended to be used for testing.
	// The field displayed in the list elements is the name field:
	// eg: [3]->[5]-#    // "3" and "5" are the actual names.  
	void viewList(const Employee* pHead) {
		const Employee* pCurrent = pHead;

		// while the node we're looking at is not null...
		while (pCurrent) {
			std::cout << "->[" << pCurrent->name << "]";	// output the name
			pCurrent = pCurrent->pNext;
		}
		std::cout << "-#";	// indicates a null pointer.
		std::cout << "\n\n";
	}

	// prints out a message to preceed the actual list
	void printExpectedMsg(const std::string& msg) {
		std::cout << "----------------------------------\n";
		std::cout<< "expected: \t" << msg << "\n";
		std::cout << "actual: \t";
	}

	// runs a bunch of tests to see if list implementation works as expected.
	void testBasicFunctionality(Employee*& pHead) {

		std::cout << "test empty list:\n";
		printExpectedMsg("-#");		
		viewList(pHead);

		std::cout << "test (invalid) removal from empty list:\n";
		removeEmployee(pHead, 0);
		printExpectedMsg("-#");
		viewList(pHead);

		std::cout << "test add 5 employees:\n";
		addNewEmployee(pHead, "0");
		addNewEmployee(pHead, "1");
		addNewEmployee(pHead, "2");
		addNewEmployee(pHead, "3");
		addNewEmployee(pHead, "4");
		//viewEmployees(pHead);
		printExpectedMsg("->[4]->[3]->[2]->[1]->[0]-#");
		viewList(pHead);

		std::cout << "test invalid removal from full list:\n";
		removeEmployee(pHead, 99);
		printExpectedMsg("->[4]->[3]->[2]->[1]->[0]-#");
		viewList(pHead);

		std::cout << "test removal from head:\n";
		removeEmployee(pHead, 4);
		printExpectedMsg("->[3]->[2]->[1]->[0]-#");
		viewList(pHead);
	
		std::cout << "test removal from tail:\n";
		removeEmployee(pHead, 0);
		printExpectedMsg("->[3]->[2]->[1]-#");
		viewList(pHead);
	

		std::cout << "test removal from middle:\n";
		removeEmployee(pHead, 2);
		printExpectedMsg("->[3]->[1]-#");
		viewList(pHead);

		std::cout << "test (invalid) removal of pre-existing element:\n";
		removeEmployee(pHead, 2);
		printExpectedMsg("->[3]->[1]-#");
		viewList(pHead);

		std::cout << "test remove last 2 individually:\n";
		removeEmployee(pHead, 1);
		removeEmployee(pHead, 3);
		viewEmployees(pHead);
		printExpectedMsg("-#");
		viewList(pHead);
	
		std::cout << "test invalid removal on an empty list:\n";
		removeEmployee(pHead, 999);
		printExpectedMsg("-#");
		viewList(pHead);

		std::cout << "test invalid removal on a list of one element:\n";
		addNewEmployee(pHead, "5");
		removeEmployee(pHead, 999);
		printExpectedMsg("->[5]-#");
		viewList(pHead);

		std::cout << "test invalid removal on a list of two elements:\n";
		addNewEmployee(pHead, "6");
		removeEmployee(pHead, 999);
		printExpectedMsg("->[6]->[5]-#");
		viewList(pHead);

		std::cout << "test remove head, add new element:\n";
		removeEmployee(pHead, 6);
		addNewEmployee(pHead, "7");
		printExpectedMsg("->[7]->[5]-#");
		viewList(pHead);

		std::cout << "test remove tail, add new element:\n";
		removeEmployee(pHead, 5);
		addNewEmployee(pHead, "8");
		printExpectedMsg("->[8]->[7]-#");
		viewList(pHead);

		std::cout << "test add 10 employees & remove them all via removeAllEmployees():\n";
		for (int i = 0; i < 10; i++)
		{
			addNewEmployee(pHead, std::to_string(i) );
		}
		removeAllEmployees(pHead);
		printExpectedMsg("-#");
		viewList(pHead);
	}

	void runTestSuite() {
		Employee* pEmployees = nullptr;
		testBasicFunctionality(pEmployees);
	}
}

#endif