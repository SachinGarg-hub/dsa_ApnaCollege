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
int main()
{
    stack<int> stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);

    cout << "Original Stack (top to bottom): ";
    stack<int> temp = stk;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    int x = 5;
    pushAtBottom(stk, x);

    cout << "Stack after pushing " << x << " at bottom (top to bottom): ";
    temp = stk;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}