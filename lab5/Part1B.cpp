#include <iostream> 
#include <vector> 

using namespace std;

int main(int argc, char* argv[])
{
    string user_input;
    cout << "Please enter your parenthesis string" << endl;
    cin >> user_input;

    stack<char> openstack;
    
    for (int i = 0; i < user_input.size(); i++)
    {
        char paren = user_input[i];

        if ( (paren == ('{')) || (paren == ('[')) 
        || (paren == ('(')) || (paren == ('<')) )
        {
            openstack.push(paren);
        }

        else if ((paren == ('}')) || (paren == (']')) 
        || (paren == (')')) ||(paren == ('>')) )
        {
            char open_bracket = openstack.top();
            if ((paren == '}' && open_bracket == '{') || 
                (paren == ']' && open_bracket == '[') ||
                (paren == ')' && open_bracket == '(') ||
                (paren == '>' && open_bracket == '<')) 
                {
                    openstack.pop();
                }
            else if (openstack.empty())
            {
                cout << "Error. Found "<<  paren << " at position " << 
                i + 1 << ", expecting any open " << endl;
                return 0;
            }
            else 
            {
                cout << "Error. Found "<<  paren << " at position " << 
                i + 1 << ", expecting " << openstack.top() << endl;
                return 0;
            }

        }

        else if (paren == (' ') || paren == ('\t'))
        {
            continue;
        }

        else 
        {
            cout << "Not a valid charecter. Goodbye" << endl;
            return -1;
        }
    }

    if (!openstack.empty())
    {
        cout << "Error. Unmatched open parens/brackets." << endl;
    }

    else 
    {
        cout << "Order is correct!" << endl;
    }


    return 0;
}