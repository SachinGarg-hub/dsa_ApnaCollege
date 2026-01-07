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

// Function to detect and remove cycle
void detectAndRemoveCycle(Node *head)
{
    if (head == NULL)
        return;

    Node *slow = head;
    Node *fast = head;
    bool isCycle = false;

    // Step 1: Detect cycle using Floyd’s algorithm
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            isCycle = true;
            break;
        }
    }

    // Step 2: If no cycle found
    if (!isCycle)
    {
        cout << "No cycle detected.\n";
        return;
    }

    // Step 3: Find start of cycle and remove it
    slow = head;

    // Case 1: If cycle starts at head
    if (slow == fast)
    {
        while (fast->next != slow)
            fast = fast->next;
        fast->next = NULL;
        cout << "Cycle removed (started at head).\n";
        return;
    }

    // Case 2: If cycle starts somewhere else
    Node *prev = NULL;
    while (slow != fast)
    {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    // 'fast' and 'slow' meet at the start of cycle
    prev->next = NULL; // break the cycle
    cout << "Cycle removed successfully.\n";
}

// Helper function to display the list
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

int main()
{
    // Create nodes
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create cycle manually (5 -> 3)
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveCycle(head); // Detect and remove cycle
    display(head);              // Print list after removal

    return 0;
}
