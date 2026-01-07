#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void insert(int val, int pos)
    {
        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node *temp = head;
        int i = 0;
        while (temp != NULL && i < pos - 1)
        {
            temp = temp->next;
            i++;
        }

        if (temp == NULL)
        {
            cout << "Invalid position\n";
            return;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
};
Node *splitAtMid(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev != NULL)
    {
        prev->next = NULL;
    }

    return slow;
}
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev; // prev is head
}

void printList(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *zigzag(Node *head)
{
    Node *rightHead = splitAtMid(head);
    Node *rightRev = reverse(rightHead);

    // alternate merging
    Node *left = head;
    Node *right = rightRev;
    Node *nextLeft = NULL;
    Node *nextRight = NULL;
    Node *tail = head;

    while (left != NULL && right != NULL)
    {
        nextLeft = left->next;
        left->next = right;

        nextRight = right->next;
        right->next = nextLeft;

        tail = right;
        left = nextLeft;
        right = nextRight;
    }

    if (right != NULL)
    {
        tail->next = right;
    }
    return head;
}

int main()
{
    List ll;
    // QS : Zig Zag Linked List
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();

    ll.head = zigzag(ll.head);
    ll.printList();
}