// Q1 Check BST

// if you perform inorder traversal on a tree and if the ans is in ascending order this means it is a BST
#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

void inorder(Node *root, vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

bool isBST()
{
    vector<int> ans;
    Node *root;
    inorder(root, ans);
    for (int i = 1; i < ans.size(); i++)
    {
        if (ans[i] < ans[i - 1])
            return 0;
    }
    return 1;
}


// another method
bool BST(Node* root, int&prev){
    if(!root)
        return 1;

    if(!BST(root->left, prev))
        return 0;

    if(root->data<=prev)
        return 0;

    return BST(root->right, prev);
}

bool isBST(Node* root){
    int prev = INT8_MIN;
    return BST(root, prev);
}



// Question 2: Minimum Distance between BST Nodes
