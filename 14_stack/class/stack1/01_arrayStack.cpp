// stack using array and menu driven program..
// implement stack and its various operations using array
#include <iostream>
using namespace std;
const int MAX = 100;
int stk[MAX];
int top = -1; // null value

void isempty()
{
    if (top == -1)
    {
        cout << "Stack underflowed" << endl;
    }
}
void isfull()
{
    if (top == MAX - 1)
    {
        cout << "Stack overflow" << endl;
        return;
    }
}
void push()
{
    int x;
    cout << "Enter element to be pushed in stack" << endl;
    cin >> x;
    isfull();
    top++;
    stk[top] = x;
}
void pop()
{
    isempty();
    cout << "Element poped :" << stk[top] << endl;
    top--;
}
void Top()
{
    isempty();
    cout << "First element of stack is :" << stk[top] << endl;
}
void size()
{
    cout << "Stack has :" << top + 1 << "elements" << endl;
}

int main()
{
    int choice;
    do
    {
        cout << "choose number from following:" << endl;
        cout << "1. to push element" << endl;
        cout << "2. to pop element " << endl;
        cout << "3. to display top element " << endl;
        cout << "4, to check size of stack" << endl;
        cout << "5. to check underflow" << endl;
        cout << "6. to check overflow" << endl;
        cout << "7. to exit the program" << endl;
        cout << "enter your choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            Top();
            break;
        case 4:
            size();
            break;
        case 5:
            isempty();
            break;
        case 6:
            isfull();
        case 7:
            cout << "program exited.." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);
    return 0;
}