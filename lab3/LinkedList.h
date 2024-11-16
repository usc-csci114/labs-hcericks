#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include <stdexcept>
#include "List.h"

template <typename T>
struct Node {
	T value;
	Node* next;
};

template <typename T>
class LinkedList : public List<T> {
public:
	LinkedList();
	void append(T v);
	void insert(size_t idx, T v);
	T at(size_t idx);
	void set(size_t idx, T v);
	void remove(size_t idx);
	size_t find(T v);
	size_t size();
	bool empty();

private:

	size_t m_size;
	Node<T>* head;
	Node<T>* tail;
};

template <typename T>
LinkedList<T>::LinkedList()
{
	m_size = 0;
	head = nullptr;
	tail = nullptr;	
}

template <typename T>
void LinkedList<T>::append(T v)
{
	Node<T>* new_node = new Node<T>;
	new_node -> next = nullptr;
	new_node -> value = v;

	if (tail != nullptr)
	{
		tail -> next = new_node;	
	}

	tail = new_node;


	if (head == nullptr)
	{
		head = tail;
	}

	m_size++;

}

template <typename T>
void LinkedList<T>::insert(size_t idx, T v)
{
	if ( idx < 0 || idx >= m_size)
	{
		throw std::range_error("Value is out of range");
	}
	
	if(head == nullptr)
	{
		append(v);
	}
	else 
	{
		Node<T>* temp = head;

		for (int i = 0; i < idx; i++)
		{
			temp = temp -> next;
		}
	
		Node<T>* new_node = new Node<T>;
		new_node -> next = temp->next;
		new_node -> value = v;

		temp -> next = new_node;
		
		m_size++;
	}	
}

template <typename T>
T LinkedList<T>::at(size_t idx)
{
	if ( idx < 0 || idx >= m_size)
	{
		throw std::range_error("Value is out of range");
	}

	Node<T>* temp = head;
	
	for (int i = 0; i < idx; i++)
	{
		temp = temp -> next;
	}

	return (temp -> value);
}

template <typename T>
void LinkedList<T>::set(size_t idx, T v)
{
	if ( idx < 0 || idx >= m_size)
	{
		throw std::range_error("Value is out of range");
	}

	Node<T>* temp = head;
	
	for (int i = 0; i < idx; i++)
	{
		temp = temp -> next;
	}

	temp -> value = v;
	
}

template <typename T>
void LinkedList<T>::remove(size_t idx)
{
	if ( idx < 0 || idx >= m_size)
	{
		throw std::range_error("Value is out of range");
	}
	
	Node<T>* prev = head;

	for (int i = 0; i < idx - 1; i++)
	{
		prev = prev -> next;
	}

	Node<T>* temp = head;

	for (int i = 0; i < idx; i++)
	{
		temp = temp -> next;
	}

    prev->next = temp->next; 

	m_size--;
}	


template <typename T>
size_t LinkedList<T>::find(T v)
{
	Node<T>* temp = head;
	
	for (int i = 0; i < m_size; i++)
	{
		if ((temp -> value) == v)
		{
			return i;
		}
	}

	std::cout << "Value is not found within linked list" << std::endl;
	return -1;
}

template <typename T>
size_t LinkedList<T>::size()
{
	return m_size;	
}

template <typename T>
bool LinkedList<T>::empty()
{
	if (m_size == 0)
	{
		return true;
	}
	return false;
}

#endif
