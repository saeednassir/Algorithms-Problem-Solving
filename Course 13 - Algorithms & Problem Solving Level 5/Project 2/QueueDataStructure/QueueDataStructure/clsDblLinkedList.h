#pragma once

#include <iostream>

using namespace std;

template <class T>
class clsDblLinkedList
{

protected:

	int _Size = 0;

public:

	class Node
	{

	public:
		T value;
		Node* prev;
		Node* next;
	};

	Node* head = NULL;

	void InsertAtBeginning(T value)
	{

		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = head;
		newNode->prev = NULL;

		if (head != NULL) {
			head->prev = newNode;
		}
		head = newNode;
		_Size++;
	}

	void PrintList()
	{
		Node* Current = head;

		while (Current != NULL) {
			cout << Current->value << " ";
			Current = Current->next;
		}

		cout << "\n";
		delete Current;
	}

	Node* Find(T Value)
	{
		Node* Current = head;

		while (Current != NULL)
		{
			if (Current->value == Value)
				return Current;

			Current = Current->next;
		}

		return NULL;

	}

	void InsertAfter(Node* Current, T value)
	{

		if (Current == NULL)
		{
			return;
		}

		Node* newNode = new Node();

		newNode->value = value;
		newNode->next = Current->next;
		newNode->prev = Current;

		if (Current->next != NULL) {
			Current->next->prev = newNode;
		}
		Current->next = newNode;
		_Size++;
	}

	void InsertAtEnd(T value)
	{

		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = NULL;

		if (head == NULL) {
			newNode->prev = NULL;
			head = newNode;

		}
		else {
			Node* current = head;
			while (current->next != NULL) {
				current = current->next;
			}

			current->next = newNode;
			newNode->prev = current;

		}

		_Size++;
	}

	void DeleteNode(Node*& NodeToDelete)
	{

		if (head == NULL || NodeToDelete == NULL) {
			return;
		}
		if (head == NodeToDelete) {
			head = NodeToDelete->next;
		}
		if (NodeToDelete->next != NULL) {
			NodeToDelete->next->prev = NodeToDelete->prev;
		}
		if (NodeToDelete->prev != NULL) {
			NodeToDelete->prev->next = NodeToDelete->next;
		}
		delete NodeToDelete;
		_Size--;
	}

	void DeleteFirstNode()
	{

		if (head == NULL) {
			return;
		}
		Node* temp = head;
		head = head->next;
		if (head != NULL) {
			head->prev = NULL;
		}
		delete temp;
		_Size--;
	}

	void DeleteLastNode()
	{

		if (head == NULL) {
			return;
		}
		if (head->next == NULL) {
			delete head;
			head = NULL;
			_Size--;
			return;
		}
		Node* current = head;
		while (current->next->next != NULL) {
			current = current->next;
		}
		Node* temp = current->next;
		current->next = NULL;

		delete temp;
		_Size--;
	}

	int Size()
	{
		return _Size;

	}

	bool IsEmpty()
	{
		return (head == NULL);
		/*
			OR
			return _Size;
		*/

	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		Node* Current = head;
		Node* temp = nullptr;

		while (Current != nullptr)
		{
			temp = Current->prev;
			Current->prev = Current->next;
			Current->next = temp;

			Current = Current->prev;
		}

		if (temp != nullptr)
		{
			head = temp->prev;
		}

	}

	Node* GetNode(int index)
	{
		int Counter = 0;

		if (index > _Size - 1 || index < 0)return NULL;

		Node* Current = head;

		while (Current != NULL && Current->next != NULL)
		{
			if (Counter == index)
				break;

			Current = Current->next;
			Counter++;
		}

		return Current;
	}

	T GetItem(int index)
	{
		Node* ItemNode = GetNode(index);

		return (ItemNode == NULL) ? NULL : ItemNode->value;

	}

	bool UpdateItem(int index, int newValue)
	{
		Node* ItemNode = GetNode(index);

		if (ItemNode != NULL)
		{
			ItemNode->value = newValue;
			return true;
		}
		else
			return false;

	}

	bool InsertAfter(int index, T value)
	{
		Node* ItemNode = GetNode(index);

		if (ItemNode != NULL)
		{
			InsertAfter(ItemNode, value);
			return true;
		}
		else
			return false;
	}

};

