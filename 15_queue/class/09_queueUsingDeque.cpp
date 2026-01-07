// Queue using Deque
// tc = O(1) for all operations, sc = O(n)
#include <iostream>
#include <deque>
using namespace std;
class QueueUsingDeque
{
    deque<int> dq;

public:
    void enqueue(int value)
    {
        dq.push_back(value);
    }
    void dequeue()
    {
        if (!dq.empty())
            dq.pop_front();
        else
            cout << "Queue is empty. Cannot dequeue." << endl;
    }
    int front()
    {
        if (!dq.empty())
            return dq.front();
        else
        {
            cout << "Queue is empty." << endl;
            return -1; // Indicating empty queue
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
    QueueUsingDeque q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl; // 10
    cout << "Queue size: " << q.size() << endl;     // 3

    q.dequeue();
    cout << "Front element after dequeue: " << q.front() << endl; // 20

    q.dequeue();
    q.dequeue();
    q.dequeue(); // Attempt to dequeue from empty queue

    return 0;
}
