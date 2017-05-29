#pragma once
class IntegerLinkedList
{
private:
	struct Node {

		int integer; //Value of the node
		Node *next_ptr; //Pointer to the next node in the list
	};

	Node *head_ptr; //Pointer to the first node in the list
public:
	IntegerLinkedList();
	~IntegerLinkedList();

	//Methods
	void appendNode(int num);
	void insertNode(int num);
	void deleteNode(int num);
	void copyList(IntegerLinkedList *list);
	void displayList();
	int searchList(int num);
	void reverseList();

};

