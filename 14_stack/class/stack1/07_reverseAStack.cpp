#include <iostream>
#include <stack>
using namespace std;
void pushAtBottom(stack<int> &stk, int x)
{
    // Base case: If stack is empty, push the element
    if (stk.empty())
    {
        stk.push(x);
        return;
    }

    // Step 1: Pop the top element
    int topElement = stk.top();
    stk.pop();

    // Step 2: Recursive call to push x at the bottom
    pushAtBottom(stk, x);

    // Step 3: Push the top element back
    stk.push(topElement);
}
void reverseStack(stack<int> &stk)
{
    // Base case: If stack is empty, return
    if (stk.empty())
    {
        return;
    }

    // Step 1: Pop the top element
    int topElement = stk.top();
    stk.pop();

    // Step 2: Recursive call to reverse the remaining stack
    reverseStack(stk);

    // Step 3: Push the popped element at the bottom of the reversed stack
    pushAtBottom(stk, topElement);
}
int main()
{
    stack<int> stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);

    cout << "Original Stack (top to bottom): ";
    stack<int> temp = stk;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverseStack(stk);

    cout << "Reversed Stack (top to bottom): ";
    temp = stk;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}
