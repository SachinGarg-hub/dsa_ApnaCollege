// doubly linked list
#include <iostream>
using namespace std;

struct node
{
    int data;   // Data part
    node *next; // Pointer to next node
    node *prev; // Pointer to previous node
};

node *head = NULL;
node *tail = NULL;

// Function to create a list with n nodes
void createList(int n)
{
    if (n <= 0)
    {
        cout << "Enter a number greater than zero\n";
        return;
    }

    int value;
    cout << "Enter data for node 1: ";
    cin >> value;

    head = new node();
    head->data = value;
    head->prev = NULL;
    head->next = NULL;
    tail = head;

    for (int i = 2; i <= n; ++i)
    {
        cout << "Enter data for node " << i << ": ";
        cin >> value;

        node *newNode = new node();
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = tail;

        tail->next = newNode;
        tail = newNode;
    }
}

// Function to display list from head to tail
void displayForward()
{
    if (head == NULL)
    {
        cout << "\nList is empty.\n";
        return;
    }

    node *temp = head;
    cout << "\nList (forward): ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to display list from tail to head
void displayBackward()
{
    if (tail == NULL)
    {
        cout << "\nList is empty.\n";
        return;
    }

    node *temp = tail;
    cout << "List (backward): ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Function to add a node at the beginning
void addAtBeginning()
{
    int value;
    cout << "Enter value to add at beginning: ";
    cin >> value;

    node *newNode = new node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;
    else
        tail = newNode;

    head = newNode;
    cout << "Node added at the beginning.\n";
}

// Function to add a node at the end
void addAtEnd()
{
    int value;
    cout << "Enter value to add at end: ";
    cin >> value;

    node *newNode = new node();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL)
        tail->next = newNode;
    else
        head = newNode;

    tail = newNode;
    cout << "Node added at the end.\n";
}

// Function to add a node at a specific position
void addAtPosition()
{
    int pos, value;
    cout << "Enter position to insert: ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> value;

    if (pos <= 0)
    {
        cout << "Invalid position.\n";
        return;
    }

    if (pos == 1)
    {
        addAtBeginning();
        return;
    }

    node *temp = head;
    int count = 1;

    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        cout << "Position out of range. Adding at end.\n";
        addAtEnd();
        return;
    }

    node *newNode = new node();
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode; // Added at the end

    temp->next = newNode;

    cout << "Node added at position " << pos << ".\n";
}

// Function to delete a node at the beginning
void deleteAtBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL; // List became empty

    delete temp;
    cout << "Node deleted from the beginning.\n";
}

// Function to delete a node at the end
void deleteAtEnd()
{
    if (tail == NULL)
    {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    node *temp = tail;
    tail = tail->prev;

    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL; // List became empty

    delete temp;
    cout << "Node deleted from the end.\n";
}

// Function to delete a node at specific position
void deleteAtPosition()
{
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    if (head == NULL)
    {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    if (pos <= 0)
    {
        cout << "Invalid position.\n";
        return;
    }

    if (pos == 1)
    {
        deleteAtBeginning();
        return;
    }

    node *temp = head;
    int count = 1;
    while (temp != NULL && count < pos)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        cout << "Position out of range.\n";
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev; // Deleted last node

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;
    cout << "Node deleted from position " << pos << ".\n";
}

int main()
{
    int choice, n;

    do
    {
        cout << "\n===== DOUBLY LINKED LIST MENU =====\n";
        cout << "1. Create List\n";
        cout << "2. Display Forward List\n";
        cout << "3. Display Backward List\n";
        cout << "4. Add Node at Beginning\n";
        cout << "5. Add Node at End\n";
        cout << "6. Add Node at specific position\n";
        cout << "7. Delete Node at Beginning\n";
        cout << "8. Delete Node at End\n";
        cout << "9. Delete Node at specific position\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number of nodes to create: ";
            cin >> n;
            createList(n);
            break;
        case 2:
            displayForward();
            break;
        case 3:
            displayBackward();
            break;
        case 4:
            addAtBeginning();
            break;
        case 5:
            addAtEnd();
            break;
        case 6:
            addAtPosition();
            break;
        case 7:
            deleteAtBeginning();
            break;
        case 8:
            deleteAtEnd();
            break;
        case 9:
            deleteAtPosition();
            break;

        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}