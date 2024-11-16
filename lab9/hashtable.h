#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <utility>
#include <vector>
#include <map>
#include <stdexcept>
#include <utility>
#include <iostream>

template <typename K, typename V>
class HashTable {
public:
	HashTable();
	~HashTable();
	void insert(K key, V value);
	V find(K key);
	void remove(K key);
	size_t size();
	bool empty();
	
private:
	std::vector< std::map<K,V> > table;
	void resize();
	size_t size_;
	size_t alpha;
	uint64_t hash(K key);
};

template <typename K, typename V>
HashTable<K,V>::HashTable() { table.resize(1); alpha = 1; size_ = 0;};

template <typename K, typename V>
HashTable<K,V>::~HashTable() {};

template <typename K, typename V>
uint64_t HashTable<K,V>::hash(K key)
{
	std::hash<K> hasher;
	return hasher(key);
}

template <typename K, typename V>
void HashTable<K,V>::insert(K key, V value)
{
	if (( (size_ + 1) / table.resize() ) > alpha)
	{
		resize();
	}
	size_t idx = hash(key) % table.size();
	table[idx][key] = value;
	size_t ++;
}

template <typename K, typename V>
V HashTable<K,V>::find(K key)
{
	size_t idx = hash(key) % table.size();
	std::map<K,V>& table_idx = table[idx];

	if (table_idx.count(key) == 0) 
	{
		throw std::range_error("Key not found.");
	}
	else
	{
		return table_idx[key];
	}
}

template <typename K, typename V>
void HashTable<K,V>::remove(K key)
{
	size_t idx = hash(key) % table.size();
	std::map<K,V>& table_idx = table[idx];

	if (table_idx.count(key) == 0) 
	{
		throw std::range_error("Key not found.");
	}
	else
	{
		table_idx.erase(key);
		size_t --;
	}
}

template <typename K, typename V>
size_t HashTable<K,V>::size()
{
	return size_t;
}

template <typename K, typename V>
bool HashTable<K,V>::empty()
{
	if (size_t == 0) 
	{
		return true;
	}
	else 
	{
		return false;
	}

}

template <typename K, typename V>
void HashTable<K,V>::resize()
{
	std::vector< std::map<K,V> > old_table = table;
	
	table.resize(0);
	table.resize(2*old_table.size());

	size_ = 0;

	for (int i = 0; i < old_table.size() ; i++)
	{
		std::map<K,V>& temp_map = old_table[i];

		for (auto it = temp_map.begin(); it != temp_map.end(); ++it)
		{
			table.insert(it->first, it->second);
		}

	}
	
	std::cout << "resizing " << table.size() << " -> " << table.size()*2 << std::endl;
}
#endif
