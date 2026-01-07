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
/*
kth level of binary tree
*/
void kthHelper(Node *root, int k, int currlevel)
{
    if (root == NULL)
    {
        return;
    }
    if (currlevel == k)
    {
        cout << root->data << " ";
        return;
    }
    kthHelper(root->left, k, currlevel + 1);  // left subtree
    kthHelper(root->right, k, currlevel + 1); // right subtree
}
void kthLevel(Node *root, int k)
{
    kthHelper(root, k, 1);
    cout << endl;
}
// lowest common ancestor in binary tree
bool rootToNodePath(Node *root, int n, vector<int> &path) // O(n)
{
    if (root == NULL)
    {
        return false;
    }
    path.push_back(root->data); // add the node in path
    if (root->data == n)
    {
        return true;
    }
    bool foundLeft = rootToNodePath(root->left, n, path);
    bool foundRight = rootToNodePath(root->right, n, path);
    if (foundLeft || foundRight)
    {
        return true;
    }
    path.pop_back(); // backtracking
    return false;
}
int LCA(Node *root, int n1, int n2) // O(n)
{
    vector<int> path1;
    vector<int> path2;
    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    for (int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++)
    {
        if (path1[i] != path2[j])
        {
            return path1[i - 1];
        }
    }
}
int LCA2(Node *root, int n1, int n2) // O(n) space optimized
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root->data;
    }
    int leftLCA = LCA2(root->left, n1, n2);
    int rightLCA = LCA2(root->right, n1, n2);

    if (leftLCA != -1 && rightLCA != -1)
    {
        return root->data;
    }
    if (leftLCA != -1)
    {
        return leftLCA;
    }
    return rightLCA;
}
// minimum distance between two nodes in binary tree
// Distance from root to given node
int dist(Node *root, int n)
{
    if (!root)
        return -1;

    if (root->data == n)
        return 0;

    int leftDist = dist(root->left, n);
    int rightDist = dist(root->right, n);

    if (leftDist == -1 && rightDist == -1)
        return -1;

    if (leftDist != -1)
        return leftDist + 1;
    return rightDist + 1;
}

// Minimum distance between 2 nodes
int minDistance(Node *root, int n1, int n2)
{
    int lca = LCA2(root, n1, n2);

    int d1 = dist(root, n1);
    int d2 = dist(root, n2);
    return (d1 + d2);
}
// kth ansestor of a node in binary tree
int kthAnsestor(Node *root, int &k, int n)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == n)
    {
        return 0;
    }
    int leftdist = kthAnsestor(root->left, k, n);
    int rightdist = kthAnsestor(root->right, k, n);

    if (leftdist == -1 && rightdist == -1)
    {
        return -1;
    }
    int valdist = leftdist == -1 ? rightdist : leftdist;
    if (valdist + 1 == k)
    {
        cout << "kth anscetor = " << root->data << endl;
    }
    return valdist + 1;
}
// transform to sum tree
int tramsformToSumTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = tramsformToSumTree(root->left);
    int rightSum = tramsformToSumTree(root->right);

    int currdata = root->data;
    root->data = leftSum + rightSum;
    return currdata + root->data;
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildTree(nodes);
    kthLevel(root, 3);
    cout << LCA(root, 4, 5) << endl;
    cout << LCA2(root, 4, 6) << endl;
    cout << minDistance(root, 4, 6) << endl;
    int k = 2;
    kthAnsestor(root, k, 5);
    tramsformToSumTree(root);
    preorder(root);
    return 0;
}
