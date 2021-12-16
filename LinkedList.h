//YOU MAY NOT MODIFY THIS DOCUMENT
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedListInterface.h"
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T>
{
private:
	struct Node
	{
		Node(T _value)
		{
			value = _value;
			next = NULL;
		}

		T value;
		Node* next;
	};

	Node* head;

public:

	LinkedList() 
	{
		cout<<"IN CONSTRUCTOR"<<endl;
		head = NULL;
	}

	~LinkedList() 
	{
		cout<<"IN DESTRUCTOR"<<endl;

		clear();
		cout<<"\nthe list has: "<<toString()<<endl;
	}

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(T value)
	{
		cout<<"INSERT HEAD"<<endl;
		insertHelper("head", value, head);
	}

	Node* getTail(Node* noodle){
		if(noodle == NULL || noodle->next == NULL){
			return noodle;

		} else{
			return getTail(noodle->next);
		}
		
	}

	void insertHelper(string ht, T value, Node* &noodle){

		if(ht == "head" && found(head, value) == NULL){
			Node* n = new Node(value);
			n->next = head;
			head = n;

		} else if(ht == "tail" && found(head, value) == NULL){
			Node* rumpa = getTail(head);
			Node* n = new Node(value);
			if(rumpa == NULL){
				head = n;
			} else{
				rumpa->next = n;
			}

		} else if(ht == "after" && found(head, value) == NULL && noodle != NULL){
			Node* n = new Node(value);
			n->next = noodle->next;
			noodle->next = n;
			
		}
		
	}

	Node* found(Node* noodle, T value){
		if(noodle == NULL || noodle->value == value){
			return noodle;

		} else{
			return found(noodle->next, value);
		}
	}

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value)
	{
		insertHelper("tail", value, head);
	}

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode){
		Node* godafton = found(head, insertionNode);
		insertHelper("after", value, godafton);
	}

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value){

		if(head == NULL){
			return;
		}
		if(head->value == value){
			Node* tmp = head;
			head = head->next;
			delete tmp;
		}
		else {
			Node* iter = head;
			while(iter->next != NULL && iter->next->value != value){
				iter = iter->next;
			}
			if(iter->next != NULL){
				Node* tmp = iter->next;
				iter->next = tmp->next;
				delete tmp;
			}
		}
	}

	/*
	clear

	Remove all nodes from the list.
	*/
	void clear(){
		while(head != NULL){remove(head->value);}
	}

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index)
	{
		
		cout << "IN AT" << endl;
		int i = 0;
		int storlek = size();
		T value;
		Node* current = head;
		if(index < 0 || index >= storlek){
			throw std::out_of_range("LinkedList::at() : index is out of range");
		}
		while(current->next != NULL && i < storlek && i != index){
			i += 1;
			current = current->next;
		}
	
		value = current->value;
		return value;
	}

	/*
	size

	Returns the number of nodes in the list.
	*/
	int size()
	{
		if(head != NULL){
			cout<<"IN SIZE"<<endl;
			int i = 1;
			Node* current = head;
			while(current->next != NULL){
				i += 1;
				current = current->next;
			}
			cout << "DONE WITH SIZE\n";
			return i;
		} else{
			return 0;
		}
	}

	/*
	toString
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	string toString()
	{
		string answer = "";
		stringstream ss(answer);
		Node* interacion = head;
		while(interacion != NULL)
		{
			if(interacion != head)
			{
				ss<<" ";
			}
			ss<<interacion->value;
			interacion = interacion->next;
		}
		return ss.str();
	}

};

#endif
