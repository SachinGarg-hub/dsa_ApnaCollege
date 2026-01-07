// stack using two queues
// push costly approach
#include <iostream>
#include <queue>
using namespace std;
class StackUsingTwoQueues
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int val)
    {
        // Push the new element onto q2
        q2.push(val);
        // Move all elements from q1 to q2
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        // Swap the names of q1 and q2
        swap(q1, q2);
    }
    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        q1.pop();
    }
    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q1.front();
    }
    bool isEmpty()
    {
        return q1.empty();
    }
    int getSize()
    {
        return q1.size();
    }
};
int main()
{
    StackUsingTwoQueues s;
    s.push(10);
    s.push(20);
    cout << "Top element: " << s.top() << endl; // 20
    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // 10
    return 0;
}
