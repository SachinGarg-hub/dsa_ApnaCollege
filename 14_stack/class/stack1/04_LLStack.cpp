// stack using linked list
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    void push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }
    void pop()
    {
        if (isempty())
        {
            cout << "Stack underflow\n";
            return;
        }
        Node *temp = top;
        cout << "Popped element: " << top->data << endl;
        top = top->next;
        delete temp;
    }
    int peek()
    {
        if (isempty())
        {
            cout << "Stack is empty\n";
            return -1; // return any dummy value
        }
        return top->data;
    }
    bool isempty()
    {
        return top == NULL;
    }
    int size()
    {
        int count = 0;
        Node *current = top;
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
        return count;
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.peek() << endl;
    s.pop();
    cout << "After pop, top element: " << s.peek() << endl;
    cout << "Stack size: " << s.size() << endl;
    return 0;
}
