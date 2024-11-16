#include <iostream> 
#include <vector> 

using namespace std;

int main(int argc, char* argv[])
{
    cout << "Please enter numbers and press ctrl-d when you are done" << endl;
    vector<int> user_input;
    int num;

    while (cin >> num) 
    {
        user_input.push_back(num);
    }

    cout << "Values in order" << endl;
    for (int i = 0; i < user_input.size(); i++)
    {   
        cout << user_input[i] << endl;
    }

    stack<int> mystack;
    
    for (int i = 0; i < user_input.size(); i++)
    {
        mystack.push(user_input[i]);
    }

    cout << "Values in reverse order" << endl;
    while (!mystack.empty()) 
    {
        cout << mystack.top() << endl;  
        mystack.pop(); 
    }

    return 0;

}