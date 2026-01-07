// queue reversal using stack
// tc = O(n), sc = O(n)
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void reverseQueue(queue<int> &q)
{
    stack<int> s;
    // step 1: push all elements of queue into stack
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    // step 2: pop all elements from stack back to queue
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << "Original Queue: ";
    queue<int> temp = q; // create a copy to display
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    reverseQueue(q);

    cout << "Reversed Queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
