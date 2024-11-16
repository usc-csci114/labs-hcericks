#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__
#include <stdexcept>
#include "List.h"

template <typename T>
class ArrayList : public List<T> {
public:
	ArrayList();
	void append(T v);
	void insert(size_t idx, T v);
	T at(size_t idx);
	void set(size_t idx, T v);
	void remove(size_t idx);
	size_t find(T v);
	size_t size();
	bool empty();

private:
	void resize(); //double the size of the array and copy the items
	size_t m_capacity;
	size_t m_size;
	T* data;
};

template <typename T>
ArrayList<T>::ArrayList()
{
	data = new T[4];
	m_capacity = 4;
	m_size = 0;
}

template <typename T>
void ArrayList<T>::append(T v)
{
	data[m_size] = v;
	m_size += 1;

}

template <typename T>
void ArrayList<T>::insert(size_t idx, T v)
{
	if ( idx < 0 || idx >= m_size)
	{
		throw std::range_error("Value is out of range");
	}

	if (m_size < m_capacity)
	{
		for (int i = m_size + 1; i < idx ; i--) 
		{
			data[i + 1] = data [i];
		}
	}
	else 
	{
		resize();
	}
	data[idx] = v;
}

template <typename T>
T ArrayList<T>::at(size_t idx)
{
	if ( idx < 0 || idx >= m_size)
	{
		throw std::range_error("Value is out of range");
	}
	else 
	{
		return data[idx];
	}
}

template <typename T>
void ArrayList<T>::set(size_t idx, T v)
{
	if ( idx < 0 || idx >= m_size)
	{
		throw std::range_error("Value is out of range");
	}
	else 
	{
		data[idx] = v;
	}

}

template <typename T>
void ArrayList<T>::remove(size_t idx)
{
	if ( idx < 0 || idx >= m_size)
	{
		throw std::range_error("Value is out of range");
	}
	for (int i = idx ; i < m_size ; i++) 
	{
		data[i] = data [i + 1];
	}	
}

template <typename T>
size_t ArrayList<T>::find(T v)
{
	for (int i = 0; i < m_size; i++)
	{
		if (data[i] == v)
		{
			return i;
		}
	}

	throw std::range_error("Value is not in list");

}

template <typename T>
size_t ArrayList<T>::size()
{
	return m_size;
}

template <typename T>
bool ArrayList<T>::empty()
{
	if (m_size == 0)
	{
		return true;
	}
	else 
	{
		return false;
	}
	
}
//double the size of the array and copy the items
template <typename T>
void ArrayList<T>::resize()
{
	m_capacity = m_capacity * 2;
	
	T* newData = new T[m_capacity];

	for (int i = 0; i < m_size; i ++)
	{
		newData[i] = data[i];
	}
	
	data = newData;
	
	
}
#endif

