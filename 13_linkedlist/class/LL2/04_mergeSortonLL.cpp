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

Node *merge(Node *h1, Node *h2)
{
    List ans;
    Node *i = h1;
    Node *j = h2;

    while (i != NULL && j != NULL)
    {
        if (i->data <= j->data)
        {
            ans.push_back(i->data);
            i = i->next;
        }
        else
        {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while (i != NULL)
    {
        ans.push_back(i->data);
        i = i->next;
    }

    while (j != NULL)
    {
        ans.push_back(j->data);
        j = j->next;
    }
    return ans.head;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *rightHead = splitAtMid(head);
    Node *sortedLeft = mergeSort(head);
    Node *sortedRight = mergeSort(rightHead);

    return merge(sortedLeft, sortedRight);
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

int main()
{
    List ll;
    // QS : Merge Sort the Linked List
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.printList();

    ll.head = mergeSort(ll.head);
    ll.printList();
}