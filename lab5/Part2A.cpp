#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <ctime>  
#include <cstdlib>
#include <algorithm>

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
    vector<int> v(100);

    srand(time(0)); 
    fillrand(v);
    
    
    priority_queue<int> pq(v.begin(), v.end());

    list<int> v2;

    while (!pq.empty())
    {
        int max_val = pq.top();
        v2.push_front(max_val);
        pq.pop();
    }

    for (list<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
    

}