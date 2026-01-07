// stack using deque
// tc = O(1) for all operations, sc = O(n)
#include <iostream>
#include <deque>
using namespace std;
class StackUsingDeque
{
    deque<int> dq;

public:
    void push(int value)
    {
        dq.push_back(value);
    }

    void pop()
    {
        if (!dq.empty())
            dq.pop_back();
        else
            cout << "Stack is empty. Cannot pop." << endl;
    }
    int top()
    {
        if (!dq.empty())
            return dq.back();
        else
        {
            cout << "Stack is empty." << endl;
            return -1; // Indicating empty stack
        }
    }

    bool isEmpty()
    {
        return dq.empty();
    }
    int size()
    {
        return dq.size();
    }
};
int main()
{
    StackUsingDeque s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl; // 30
    cout << "Stack size: " << s.size() << endl; // 3

    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // 20

    s.pop();
    s.pop();
    s.pop(); // Attempt to pop from empty stack

    return 0;
}
