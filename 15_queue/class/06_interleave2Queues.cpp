// Interleave two queues
// tc = O(n), sc = O(1)
#include <iostream>
#include <queue>
using namespace std;
void interleave(queue<int>& q1, queue<int>& q2) {
    int n = q1.size();

    for (int i = 0; i < n; i++) {
        // Step 1: take front of q2
        int x = q2.front();
        q2.pop();

        // Step 2: rotate q1
        for (int j = 0; j < i; j++) {
            q1.push(q1.front());
            q1.pop();
        }

        // Step 3: insert element from q2
        q1.push(x);
    }
}

int main() {
    queue<int> q1;
    queue<int> q2;

    // Sample input
    q1.push(1);
    q1.push(3);
    q1.push(5);

    q2.push(2);
    q2.push(4);
    q2.push(6);

    interleave(q1, q2);

    // Print interleaved queue
    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;

    return 0;
}
