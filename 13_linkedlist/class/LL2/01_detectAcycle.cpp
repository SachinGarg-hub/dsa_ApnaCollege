#include <iostream>
using namespace std;

// Definition for singly-linked list
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

// Detect cycle using Floyd’s algorithm
Node *detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return slow; // meeting point found
    }
    return NULL; // no cycle
}

// Function to remove cycle from linked list
void removeCycle(Node *head)
{
    Node *meet = detectCycle(head);
    if (meet == NULL)
    {
        cout << "No cycle found.\n";
        return;
    }

    // Move one pointer to head
    Node *start = head;

    // If the cycle starts at the head
    if (meet == head)
    {
        while (meet->next != head)
            meet = meet->next;
        meet->next = NULL;
        cout << "Cycle removed (cycle started at head).\n";
        return;
    }

    // Otherwise, move both one step until next pointers match
    while (start->next != meet->next)
    {
        start = start->next;
        meet = meet->next;
    }

    // Break the cycle
    meet->next = NULL;
    cout << "Cycle removed successfully.\n";
}

// Function to print linked list
void display(Node *head)
{
    Node *temp = head;
    cout << "List: ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Driver code
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create a cycle manually
    head->next->next->next->next->next = head->next->next; // cycle at node 3

    removeCycle(head); // remove the cycle
    display(head);     // verify the list is now linear

    return 0;
}
