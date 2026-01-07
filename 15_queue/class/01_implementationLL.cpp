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
        next = nullptr;
    }
};
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(int val)
    {
        Node *newNode = new Node(val);
        if (front == nullptr)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
    }
    int peek()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    bool isEmpty()
    {
        return front == nullptr;
    }
    void display()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element: " << q.peek() << endl; // 10
    q.display();                                   // 10 20 30
    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl; // 20
    q.display();                                                 // 20 30
    q.dequeue();
    q.dequeue();
    q.dequeue(); // Queue is empty
    return 0;
}