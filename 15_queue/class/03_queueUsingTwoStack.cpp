// Queue using 2 stacks
// costly enqueue and cheap dequeue
#include <iostream>
#include <stack>
using namespace std;
class QueueUsingTwoStacks
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int val)
    {
        // Move all elements from s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        // Push the new element onto s1
        s1.push(val);
        // Move all elements back from s2 to s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void dequeue()
    {
        if (s1.empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        s1.pop();
    }
    int peek()
    {
        if (s1.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return s1.top();
    }
    bool isEmpty()
    {
        return s1.empty();
    }
    int getSize()
    {
        return s1.size();
    }
};
int main()
{
    QueueUsingTwoStacks q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element: " << q.peek() << endl; // 10
    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl;        // 20
    cout << "Queue size: " << q.getSize() << endl;                      // 2
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // No
    return 0;
}
