// double ended queue implementation
#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> dq;

    // Insertion at both ends
    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);
    dq.push_front(40);

    cout << "Deque after insertions: ";
    for (int elem : dq)
        cout << elem << " ";
    cout << endl;

    // Deletion from both ends
    dq.pop_front();
    dq.pop_back();

    cout << "Deque after deletions: ";
    for (int elem : dq)
        cout << elem << " ";
    cout << endl;

    // Accessing front and back elements
    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;

    return 0;
}