// Stack using vector
#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    vector<int> vec;

public:
    void push(int val)
    {
        vec.push_back(val);
    }

    void pop()
    {
        if (!vec.empty())
        {
            vec.pop_back();
        }
        else
        {
            cout << "Stack Underflow\n";
        }
    }

    int top()
    {
        if (!vec.empty())
        {
            return vec[vec.size() - 1];
        }
        cout << "Stack is Empty\n";
        return -1; // return any dummy value
    }

    bool empty()
    {
        return vec.empty();
    }

    int size()
    {
        return vec.size();
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;

    s.pop();
    cout << "After pop, top: " << s.top() << endl;

    return 0;
}
