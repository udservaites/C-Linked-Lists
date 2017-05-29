/*Kathryn Rebecca Servaites
CIS 2207.N01
Linked List Homework
Chapter 17 Programming Challenges 1-5*/

/*1.  Your Own Linked List
Design your own linked list class to hold a series of integers. The class should have
member functions for appending, inserting, and deleting nodes. Don’t forget to add a
destructor that destroys the list. Demonstrate the class with a driver program.
2.  List Print
Modify the linked list class you created in Programming Challenge 1 to add a print
member function. The function should display all the values in the linked list. Test
the class by starting with an empty list, adding some elements, and then printing the
resulting list out.
3.  List Copy Constructor
Modify your linked list class of Programming Challenges 1 and 2 to add a copy
constructor. Test your class by making a list, making a copy of the list, and then displaying
the values in the copy.
4.  List Reverse
Modify the linked list class you created in the previous programming challenges by
adding a member function named reverse that rearranges the nodes in the list so that
their order is reversed. Demonstrate the function in a simple driver program.
5.  List Search
Modify the linked list class you created in the previous programming challenges to
include a member function named search that returns the position of a specific value
in the linked list. The first node in the list is at position 0, the second node is at position
1, and so on. If x is not found on the list, the search should return -1. Test the new
member function using an appropriate driver program. */

#include "IntegerLinkedList.h"
#include <iostream>


using namespace std;

int main() {

	//Create initial node
	IntegerLinkedList *list = new IntegerLinkedList;
	IntegerLinkedList *copy = new IntegerLinkedList;
	
	int position, menuChoice = 0, nodeValue;

	while (menuChoice != 9) {
		cout << "\n\nMenu: " << endl;
		cout << "1. Append List "
			"\n2. Insert Node "
			"\n3. Delete Node "
			"\n4. Search List "
			"\n5. Reverse List "
			"\n6. Copy List "
			"\n7. Delete List "
			"\n8. Display List"
			"\n9. Quit " << endl;
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "Please enter an integer to store in the node: ";
			cin >> nodeValue;
			list->appendNode(nodeValue);
			list->displayList();
			break;
		case 2:
			cout << "Please enter an integer to store in the node: ";
			cin >> nodeValue;
			list->insertNode(nodeValue);
			list->displayList();
			break;
		case 3:
			cout << "Please enter the integer value of the node you want to delete: ";
			cin >> nodeValue;
			list->deleteNode(nodeValue);
			list->displayList();
			break;
		case 4:
			cout << "Please enter the integer value of the node you want ot search: ";
			cin >> nodeValue;
			position = list->searchList(nodeValue);
			if (position != -1) {
				cout << "The node is located in position " << position << endl;
			}
			else {
				cout << "That node is not located in the list. " << endl;
			}
			break;
		case 5:
			list->reverseList();
			list->displayList();
			break;
		case 6:
			copy->copyList(list);
			copy->displayList();
			break;
		case 7:
			list->~IntegerLinkedList();
			list->displayList();
			break;
		case 8:
			list->displayList();
			break;
		case 9:
			break;
		default:
			cout << "That is not a valid entry. Please try again. ";
			break;
		}
	}

	system("pause");
	return(0);
}