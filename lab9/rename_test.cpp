
#include <utility>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <random>
#include "hashtable.h"

using namespace std;

int main(int argc, char* argv[])
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, 1000);
	  
	HashTable<int, int> t;

    int N = 100000;

	const auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < N; i++)
    {
        int val = distribution(generator);
        t.insert(i, val);
    }
	
	const auto end = std::chrono::steady_clock::now();
	const std::chrono::duration<double> diff = end - start;

	std::cout << "Runtime " << N << ": ";
	std::cout << diff.count() << endl;


}