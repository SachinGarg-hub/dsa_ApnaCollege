// binary tree from preorder
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

static int idx = -1;

Node *buildTree(vector<int> &nodes)
{
    idx++;
    if (nodes[idx] == -1)
    {
        return nullptr;
    }

    Node *currnode = new Node(nodes[idx]);
    currnode->left = buildTree(nodes);
    currnode->right = buildTree(nodes);
    return currnode;
}

// preorder traversal
/*
root -> left subtree -> right subtree
 */
void preorder(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
// inorderTraversal
/*
left subtree -> root -> right subtree
*/
void inorder(Node *root)
{
    if (root == nullptr)
        return;

    // left
    inorder(root->left);
    // root
    cout << root->data << " ";
    // right
    inorder(root->right);
}
// postorder traversal
/*
left subtree
right subtree
root
*/
void postorder(Node *root)
{
    if (root == nullptr)
        return;

    // left
    postorder(root->left);
    // right
    postorder(root->right);
    // root
    cout << root->data << " ";
}
// level order traversal
/*
BFS -> breadth first search
DFS-> depth first search
level order traversal is done using queue
*/
void levelOrder(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << endl;
            if (q.empty())
            {
                break;
            }
            q.push(NULL);
        }
        else
        {
            cout << curr->data << " ";

            if (curr->left != nullptr)
                q.push(curr->left);

            if (curr->right != nullptr)
                q.push(curr->right);
        }
    }
}
/*
height of binary tree
max distance from root to leaf
*/
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftht = height(root->left);
    int rightht = height(root->right);
    int currht = max(leftht, rightht) + 1;
    return currht;
}
// count of nodes
int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftct = countNodes(root->left);
    int rightct = countNodes(root->right);
    return (leftct + rightct + 1);
}
// sum of nodes in bt
int sumNode(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftsum = sumNode(root->left);
    int rightsum = sumNode(root->right);
    return leftsum + rightsum + root->data;
}
int main()
{
    //  vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    vector<int> nodes2 = {1, 2, 4, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};
    // Node *root = buildTree(nodes);
    Node *root2 = buildTree(nodes2);
    /*
        cout << "Root = " << root->data << endl;

        preorder(root);
        cout << endl;
        inorder(root);
        cout << endl;
        postorder(root);
        cout << endl;
        levelOrder(root);
        cout << endl;
        */
    //  cout << "height: " << height(root) << endl;
    cout << "height: " << height(root2) << endl;
    cout << "Count of nodes : " << countNodes(root2) << endl;
    cout << "sum of nodes : " << sumNode(root2) << endl;
    return 0;
}
