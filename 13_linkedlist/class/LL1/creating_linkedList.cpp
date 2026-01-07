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
    // delete node from memory
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};
class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
    // delete list from memory
    ~List()
    {
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }
    // add a element at start of a list
    void push_front(int val)
    {
        Node *newnode = new Node(val); // dynamic allocation
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
    // add element at last of a list
    void push_back(int val)
    {
        Node *newnode = new Node(val); // dynamic allocation
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ->  ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    // insert at a position
    void insert(int val, int pos)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = tail = newnode;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                return;
            }
            temp = temp->next;
        }
        // temp is now at pos-1 i.e. prev / left
        newnode->next = temp->next;
        temp->next = newnode;
    }
    // delete first element from list
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "ll is empty \n";
            return;
        }

        Node *temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }
    // delete last element from list
    void pop_back()
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL; // temp = tails prev
        delete temp;
    }
    // iterative Search in LL
    int searchltr(int key)
    {
        Node *temp = head;
        int idx = 0;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }
    // Recursive search in LL
    int helper(Node *temp, int key)
    {
        if (temp == NULL)
        {
            return -1;
        }
        if (temp->data == key)
        {
            return 0;
        }
        int idx = helper(temp->next, key);
        if (idx == -1)
        {
            return -1;
        }
        return idx + 1;
    }
    int searchRec(int key)
    {
        return helper(head, key);
    }
    // Reverse a LL

    void reverse()
    {
        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;
            // updations for next itr
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    // find and remove nth node from last
    int getsize()
    {
        int sz = 0;
        Node *temp = head;
        while (temp != 0)
        {
            temp = temp->next;
            sz++;
        }
        return sz;
    }
    void removeNth(int n)
    {
        int size = getsize();
        Node *prev = head;
        for (int i = 1; i < (size - n); i++)
        {
            prev = prev->next;
        }
        prev->next = prev->next->next;
    }
};
int main()
{
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();
    ll.reverse();
    ll.printList();
}