#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	int size = 2000000;
	for(int i = 1; i < 20;i++)
	{
		vector<int> v;
		//1. Resize the vector to size*i
		v.resize(size*i);

		//2. Reserve 2*size*i (so we don't resize)
		v.reserve(2*size*i);

		//3. log the start time
		const auto start = std::chrono::steady_clock::now();

		sort(v.begin(),v.end());
		
		
		//4. log the stop time and calculate the diff
		const auto end = std::chrono::steady_clock::now();
		const std::chrono::duration<double> diff = end - start;

		std::cout << "Sorting vector for size " << v.size() << ": ";
		std::cout << diff.count() << endl;
	}	
}
