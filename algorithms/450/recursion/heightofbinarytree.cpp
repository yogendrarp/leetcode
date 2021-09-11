#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    node *left;
    node *right;
    int data;
};

node *getNode(int data)
{
    node *pointernode = new node();
    pointernode->data = data;
    pointernode->left = NULL;
    pointernode->right = NULL;
    return pointernode;
}
int maxdepth(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftdepth = maxdepth(root->left);
    int rightdepth = maxdepth(root->right);
    return 1 + max(leftdepth, rightdepth);
}

int main()
{
    node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    cout << "Height of maxdepth of tree is " << maxdepth(root) << endl;
}