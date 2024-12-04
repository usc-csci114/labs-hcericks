#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <ctime>  
#include <cstdlib>
#include <algorithm>
#include <chrono>

using namespace std;


void fillrand(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = rand();
    } 
}

using namespace std;

int main(int argc, char* argv[])
{

    srand(time(0)); 

	for(int i = 1; i < 100;i++)
	{
		vector<int> v;
		//1. Resize the vector to size*i
		v.resize(i);

        fillrand(v);
        priority_queue<int> pq(v.begin(), v.end());

	
		const auto start = std::chrono::steady_clock::now();

        while (!pq.empty())
        {
            pq.pop();
        }

        const auto end = std::chrono::steady_clock::now();
		const std::chrono::duration<double> diff = end - start;

        std::cout << "Sorting vector for size " << v.size() << ": ";
		std::cout << diff.count() << endl;
    }

    return 0;

}