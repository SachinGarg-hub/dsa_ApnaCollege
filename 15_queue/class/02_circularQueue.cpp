// implementation of circular queue using array
#include <iostream>
using namespace std;
class CircularQueue
{
private:
    int *arr;
    int front;
    int rear;
    int capacity; // maximum number of elements in the queue
    int size;     // current number of elements in the queue

public:
    CircularQueue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }
    ~CircularQueue()
    {
        delete[] arr;
    }
    void enqueue(int val)
    {
        if (size == capacity)
        {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
    }
    void dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }
    int peek()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == capacity;
    }
};
int main()
{
    CircularQueue cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cout << "Front element: " << cq.peek() << endl; // 10
    cq.dequeue();
    cout << "Front element after dequeue: " << cq.peek() << endl; // 20
    cout << "Queue size: " << cq.getSize() << endl;               // 2
    return 0;
}