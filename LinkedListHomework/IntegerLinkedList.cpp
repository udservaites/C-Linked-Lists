#include "IntegerLinkedList.h"
#include<iostream>

using namespace std;


IntegerLinkedList::IntegerLinkedList()
{
	head_ptr = nullptr;
}


IntegerLinkedList::~IntegerLinkedList()
{
	//deletes list;
	Node *current_ptr;
	Node *nextNode_ptr;

	current_ptr = head_ptr;
	while (current_ptr != NULL) { //WHen NULL, you are at the end of the list
		nextNode_ptr = current_ptr->next_ptr; //Save the way to the next node
		delete current_ptr; //Delete the node
		current_ptr = nextNode_ptr; //Set current_ptr to the next node to start process again
	}
	head_ptr = nullptr;
}
//Adds a node to the end of the list
void IntegerLinkedList::appendNode(int num) {

	Node *newNode_ptr = new Node; //Create new node
	newNode_ptr->integer = num; //Set value of node
	newNode_ptr->next_ptr = nullptr; //Set the next to nullptr becuase it is now last in the list

	//Check to see if this node is the first node in the list
	if (head_ptr == NULL) {
		head_ptr = newNode_ptr; /*Sets the head pointer to the address in newNode.
						head now points to where newNode points*/
	}
	else {
		Node *current_ptr = head_ptr; //Create a node to hold a temp pointer value

		while (current_ptr->next_ptr != NULL) { //FInd the last node in the list
			current_ptr = current_ptr->next_ptr; //Directs to the next node until you hit the end of the list
		}
		current_ptr->next_ptr = newNode_ptr; //Sets the pointer of the last in list to the new last node in list
	}
	//displayList();
}

//Assuming the list is ordered, this will insert an interger in its proper order
void IntegerLinkedList::insertNode(int num) {

	Node *newNode_ptr = new Node; //Create new node
	newNode_ptr->integer = num;
	newNode_ptr->next_ptr = nullptr;

	if (head_ptr == NULL) {
		head_ptr = newNode_ptr;
	}
	else {
		Node *current_ptr = head_ptr; //Current is used to travers the list. It is equal to head becuase head is the beginning of the list
		Node *previous_ptr = nullptr; //As the list is traversed, this will be equal to the previous pointer before current

		while ((current_ptr != NULL) && (current_ptr->integer < newNode_ptr->integer)) { /*While the current is not null and
																			 the current interger is less than the
																			 newNode we are inserting integer*/
			previous_ptr = current_ptr;//Current is old news, so now it is allocated to previous
			current_ptr = current_ptr->next_ptr; //Sets the next itereation of current to the next node in the list
		}

		if (previous_ptr == NULL) { //Inserts newNode at head of list, if list is empty
			newNode_ptr->next_ptr = head_ptr;
			head_ptr = newNode_ptr;
		}
		else { //Inserts newNode after previous from the list traverse in above while loop			
			previous_ptr->next_ptr = newNode_ptr; //Sets the next pointer of newNode to current
			newNode_ptr->next_ptr = current_ptr; //Sets pointer of previous to newNode
		}
	}
	
}

//Deletes a node that has the value the integer passed into the function
void IntegerLinkedList::deleteNode(int num) {
	Node *current_ptr = head_ptr;
	Node *previous_ptr = head_ptr;

	/*if (head_ptr = NULL) { //If head is equal to null, then nothing needs to be done

	}
	else if (head_ptr->integer == num) { //If head is equal to the num, then delete head
	current_ptr = head_ptr->next_ptr;
	delete head_ptr;
	head_ptr = current_ptr;
	}
	else { //Traverse the list to find the node to delete*/
	current_ptr = head_ptr;
	while ((current_ptr != NULL) && (current_ptr->integer != num)) {
		previous_ptr = current_ptr;
		current_ptr = current_ptr->next_ptr;
	}
	if (current_ptr == NULL) {

	}
	else if (previous_ptr == NULL) {
		head_ptr = head_ptr->next_ptr;
	}
	else {
		Node *tempNode = current_ptr;
		previous_ptr->next_ptr = current_ptr->next_ptr;
		delete tempNode;
	}

	
}

void IntegerLinkedList::copyList(IntegerLinkedList *list) {
	
	this->~IntegerLinkedList(); //Delete the list so you can copy new stuff to it
	Node *listToCopy_ptr = list->head_ptr; //For traversing the original list
	
	/*Go through the listToCopy nodes one by one and append then to the 
	list you are copying them to.*/
	while (listToCopy_ptr != NULL) { 
		appendNode(listToCopy_ptr->integer);
		listToCopy_ptr = listToCopy_ptr->next_ptr; //Sets condition for next loop itereation

		/*Node *copyNode_ptr = new Node; //To make copy nodes
		copyNode_ptr->integer = listToCopy_ptr->integer; //Copy the interger value to copy node
		copyNode_ptr->next_ptr = nullptr; //Set next to nullptr

		if (head_ptr = NULL) { //Is this the first node in the copy list?
			head_ptr = copyNode_ptr; //If so, then set head pointer to node address
		}
		else { //If not the first copy node in list, then follow same steps as append
			Node *currentCopy_ptr; //To traverse the copy list
			currentCopy_ptr = head_ptr; //Start at the beginning

			while (currentCopy_ptr->next_ptr != NULL) { //Go through each node in the copy list until you hit the end of the list
				currentCopy_ptr = currentCopy_ptr->next_ptr;
			}
			currentCopy_ptr->next_ptr = copyNode_ptr; //Set the copyNode address into the next slot of the current node

			listToCopy_ptr = listToCopy_ptr->next_ptr; /*Go to the next node in the original list
														 for the next loop to copy the node*/

		}

//	}
	
}


void IntegerLinkedList::displayList() {

	Node *current_ptr = head_ptr;
	while (current_ptr != NULL) { //Will go through each node in list and disply integer value
		cout << "Node: " << current_ptr->integer << endl;
		current_ptr = current_ptr->next_ptr;
	}
}



int IntegerLinkedList::searchList(int num) {
	Node *current_ptr = new Node;
	int counter = 0;
	bool foundIt = false;

	if (head_ptr != NULL) {
		current_ptr = head_ptr;
		while ((current_ptr != NULL) && (current_ptr->integer != num)) { //Compare each integer in nodes to see if there is a match
			current_ptr = current_ptr->next_ptr;
			counter++;			
		}
		if (current_ptr->integer == num) {//Set flag when value is found
				foundIt = true;
			}
	}
	if (foundIt) {
		return counter;
	}
	else {
		return -1;
	}
}

void IntegerLinkedList::reverseList() {
	Node *previousNode_ptr = new Node;
	Node *currentNode_ptr = new Node;
	Node *nextNode_ptr = new Node;

	if (head_ptr != NULL) {
		previousNode_ptr = head_ptr;
		currentNode_ptr = previousNode_ptr->next_ptr;
		nextNode_ptr = currentNode_ptr->next_ptr;
		previousNode_ptr->next_ptr = nullptr; /*This will be the new last in the list. Set the
											  next pointer to nullptr to avoid an infinite loop.*/

		while (nextNode_ptr != NULL) {
			currentNode_ptr->next_ptr = previousNode_ptr; //Sets current next pointer to the previous node


			previousNode_ptr = currentNode_ptr; //Current becomes previous
			currentNode_ptr = nextNode_ptr; //Next becomes current
			nextNode_ptr = nextNode_ptr->next_ptr; //Get a new next
		}

		currentNode_ptr->next_ptr = previousNode_ptr; //Set the last node in the list that we didn't get to in the loop


		//head_ptr->next_ptr = nullptr; //Head is now last. Set next to null
		head_ptr = currentNode_ptr; //Change the head to the last in the list


	}
	
}