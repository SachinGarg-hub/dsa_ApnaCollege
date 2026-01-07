#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
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
// diameter of a tree
/* no. of nodes in the longest path between 2 leaves */
/* approach 1 O(n^2)*/
int diam1(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int currDiam = height(root->left) + height(root->right) + 1; // O(n)
    int leftdiam = diam1(root->left);
    int rightdiam = diam1(root->right);
    return max(currDiam, max(leftdiam, rightdiam));
}
// approach 2 O(n)
pair<int, int> diam2(Node *root)
{
    // base case = (diameter, height)
    if (root == NULL)
        return {0, 0};

    // recursive calls
    pair<int, int> leftInfo = diam2(root->left);   // {ld, lh}
    pair<int, int> rightInfo = diam2(root->right); // {rd, rh}

    int leftDiam = leftInfo.first;
    int rightDiam = rightInfo.first;

    int leftHt = leftInfo.second;
    int rightHt = rightInfo.second;

    // height of current node
    int currHeight = max(leftHt, rightHt) + 1;

    // diameter passing through root
    int currDiam = leftHt + rightHt + 1;

    // final diameter at this node
    int finalDiam = max(currDiam, max(leftDiam, rightDiam));

    return {finalDiam, currHeight};
}
// whether 2 trees are identical rooted at root and subroot
bool isIdentical(Node *root, Node *subroot)
{
    if (root == NULL && subroot == NULL)
        return true;
    if (root == NULL || subroot == NULL)
        return false;

    if (root->data != subroot->data)
        return false;
    return isIdentical(root->left, subroot->left) && isIdentical(root->right, subroot->right);
}
// subtree of another tree
bool IsSubtree(Node *root, Node *subroot)
{
    if (subroot == NULL)
        return true;
    if (root == NULL)
        return false;

    if (root->data == subroot->data)
    {
        if (isIdentical(root, subroot))
            return true;
    }
    return IsSubtree(root->left, subroot) || IsSubtree(root->right, subroot);
}
// top view of binary tree
void topView(Node *root)
{
    queue<pair<Node *, int>> Q; // (node, HD)
    map<int, int> m;            // (HD, node->data)

    Q.push(make_pair(root, 0));

    while (!Q.empty())
    {
        pair<Node *, int> curr = Q.front();
        Q.pop();

        Node *currNode = curr.first;
        int currHD = curr.second;
        // If HD already present, do not store the data
        // This ensures that we only store the first node encountered at each HD
        if (m.count(currHD) == 0)
        {
            m[currHD] = currNode->data;
        }

        // Left child: HD - 1
        if (currNode->left != NULL)
        {
            Q.push(make_pair(currNode->left, currHD - 1));
        }

        // Right child: HD + 1
        if (currNode->right != NULL)
        {
            Q.push(make_pair(currNode->right, currHD + 1));
        }
    }
    // Print map -> top view result
    for (auto it : m)
    {
        cout << it.second << " ";
    }
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    vector<int> nodes2 = {1, 2, 4, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};

    Node *root = buildTree(nodes);
    Node *subroot = new Node(2);
    subroot->left = new Node(4);
    subroot->right = new Node(5);
    cout << IsSubtree(root, subroot) << endl;
    /* Node *root2 = buildTree(nodes2);
     cout << "Diameter = " << diam1(root) << endl;
     cout << "Diameter = " << diam2(root).first << endl;
     cout << "Height= " << diam2(root).second << endl;
 */
    topView(root);
    cout << endl;
    return 0;
}
