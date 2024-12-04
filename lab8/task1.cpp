#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue> 


using namespace std;

int main(){


    std::map<char, set<char> > graph;
    std::map<char, int > distance;

    std::ifstream ifile("graph1.txt");
	std::string line;
    string key_names;
    int num_keys = 0;
	
    if (!ifile.is_open()) 
    {
    std::cout << "Failed to open file!" << std::endl;
    return 0;
    }

    while (getline(ifile, line))
    {
        std::stringstream ss(line);
        char key;
        char neighbor;
        ss >> key;
        set<char> vert_neighbor;
        while (ss >> neighbor) 
        {
            if(neighbor == '0') continue;
            vert_neighbor.insert(neighbor); 
        }
        graph[key] = vert_neighbor;

        num_keys++;
        key_names.push_back(key);
    
    cout << "Processed file graph1.txt. Found "<< num_keys  << " vertexs: ";

    for (int i = 0; i < key_names.size(); i++)
    {
        cout << key_names[i];
        if (i != (key_names.size() - 1))
        {
            cout << ", ";
        }
    }

    cout << endl;

    cout << "What vertex do you want to start your BFS on?" << endl;
    char start;
    cin >> start;

    std::queue<char> Q;
    set<char> V;

    Q.push(start);
    V.insert(start);

    distance[start] = 0;

    cout << "BFS starting at: " << start << ": ";

    while (!Q.empty())
    {
        char v = Q.front();
        Q.pop();
        
        cout << v << ":";
        int d = distance[v];
        cout << d << ", ";
        

        for (std::set<char>::iterator it = graph[v].begin(); it != graph[v].end(); ++it) 
        {
            char n = *it;
            
            if (V.find(n) == V.end()) 
            {
                Q.push(n);
                V.insert(n);
                distance[n] = d + 1;
            }
        }
    }

    cout << endl;
    return 0;
}

