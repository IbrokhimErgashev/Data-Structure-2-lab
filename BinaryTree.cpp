#pragma once  
#include <iostream>
#include <cstdlib>
using namespace std;

#define null NULL


struct List {
	int val;
	struct List* next;
};

class LinkedList {
private:
	List * head;
	//insertion for problem : modify ordered insertion using recursion
	List* insertNode(int info, List* head, List* prev);
public:
	LinkedList() {
		head = null;
	}
	//insertion as example
	void insert(int info);
	void print();
	//deletion as example
	void deleteNode(int info);

	void middle(struct Node *head);
	int count = 0;
};
void LinkedList::insert(int info) {

	if (head == null) {
		head = new List();
		head->val = info;
		head->next = null;
		return;
	}
	else if (head->val > info) {
		List* temp = new List();
		temp->val = info;
		temp->next = head;
		head = temp;
		return;
	}
	List * temp = head;
	while (temp->next != null && temp->next->val <= info)
		temp = temp->next;
	if (temp->next == null) {
		temp->next = new List();
		temp = temp->next;
		temp->val = info;
		temp->next = null;
	}
	else if (temp->next != null && temp->next->val > info) {
		List* node = new List();
		node->val = info;
		node->next = temp->next;
		temp->next = node;
		return;
	}

	count++;
}
void LinkedList::print() {
	List * temp = head;
	if (head != null)
		cout << "Printing elements of the list : ";
	else
		cout << "List is empty";

	while (temp != null) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;

}
//deletion as example
void LinkedList::deleteNode(int info) {
	if (head == null) {
		cout << "list is empty" << endl;
		return;
	}
	else if (head->val == info) {
		List *temp = head;
		head = head->next;
		delete temp;
		return;
	}

	List* iterator = head;
	List* prev = null;
	while (iterator != null && iterator->val != info) {
		prev = iterator;
		iterator = iterator->next;
	}
	if (iterator == null) {
		cout << "No such element" << endl;
		return;
	}
	else if (iterator->val == info) {
		prev->next = iterator->next;
		delete iterator;
		return;
	}
	count--;
}
void LinkedList::middle(struct Node *head) 
{
	struct List *slow_ptr = head;
	struct List *fast_ptr = head;
	if (head != NULL) 
	{
		while (fast_ptr != NULL && fast_ptr->next != NULL)
		{
			fast_ptr = fast_ptr->next->next;
			slow_ptr = slow_ptr->next;
		}

	}

}
int main()
{
	LinkedList list;

	int n;
	char option;
	while (true) {
		cin >> option;
		switch (option)
		{
		case 'i':

			cin >> n;
			list.insert(n);
			break;
		case 'p':
			list.print();
			break;
		case 'd':
			cin >> n;

			list.deleteNode(n);
			cout << "Left characters: ";
			list.print();
			break;

		case 'm':
			list.middle();
		
		default:
			break;
		}
	}
}


