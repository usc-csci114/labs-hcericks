#include <iostream>

using namespace std;

//Calculator: Create a simple calculator that performs basic arithmetic operations like addition, subtraction, multiplication, and division.


int main(int argc, char* argv[])
{
    double num1, num2;
    string func;
    double result;
    
    cout << "Give me 2 numbers" << endl;
    cin >> num1  >> num2;

    cout << "Give me an operation: addition, subtraction, multiplication, or division" << endl;
    cin >> func;

    if (func == "quit")
    {
        cout << "you have quit program. goodbye" << endl;
        return 0;
    }

    else if (func == "addition")
    {
        result = num1 + num2;
        cout << "Result: " << result << endl;
    }
    
    else if (func == "subtraction")
    {
        result = num1 - num2;
        cout << "Result: " << result << endl;
    }
    
    else if (func == "multiplication")
    {
        result = num1 * num2;
        cout << "Result: " << result << endl;
    }
    
    else if (func == "division")
    {
        if (num2 == 0)
        {
            cout << "Error! Cant divide by 0" << endl;
            return 0;
        }
        result = num1/num2;
        cout << "Result: " << result << endl;
    }

    else {
        cout << "Invalid operation!" << endl;
    }

    

    return 0;

}

