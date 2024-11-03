// AVL Tree

/*
First search the element
Then Delete
Then Check balancing
*/

/*
Deletion cases:

    Leaf Node Deletion: Delete it directly

    Single Child Deletion:
        Left Child:
            delete that node
            return its left child
        Right Child:
            delete that node
            return its right child

    Both Child Exists:
        We need a replacement for the element we are deleting
        We can either replace it with the largest element from left branch or with the smallest element of right branch

        - Right side min element(left-most):
            right side-> minimum element
            replace it with root                    (here we are just replacing the data(not deleting the actual node), in BST code we were replacing the nodes)
            delete kerdo jisse replace kiya usko

        - Left side max element(right-most):
            left side -> maximum element
            replace it with root                    (here we are just replacing the data(not deleting the actual node), in BST code we were replacing the nodes)
            delete kerdo jisse replace kiya usko
*/

// Last step of each case would be to check the balancing of ancestor nodes. If unbalanced the peform rotation to balance them
// jaha se delete kiya hai uske doosre side se unbalancing hogi

#include <iostream>
using namespace std;

class Node
{
public:
    int data, height;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node *root)
{
    if (!root)
    {
        return 0;
    }

    return root->height;
}

int getBalance(Node *root)
{
    return getHeight(root->left) - getHeight(root->right);
}

Node *rightRotation(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;

    child->right = root;
    root->left = childRight;

    // update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

Node *leftRotation(Node *root)
{
    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    // update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

Node *deleteNode(Node *root, int key)
{
    if (!root)
    {
        return NULL;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {

        // Leaf Node
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }

        // Only one child  exist
        else if (root->left && !root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (!root->left && root->right)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // bold child exist
        else
        {
            // Right side's smallest element
            Node *curr = root->right;
            while (curr->left)
            {
                curr = curr->left;
            }
            root->data = curr->data;                           // changing values only not the actual nodes
            root->right = deleteNode(root->right, root->data); // deleting the element jisse replace kiya hai
        }
    }

    // update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // checking balance
    int balance = getBalance(root);

    // Left Side
    if (balance > 1)
    {

        // left left
        if (getBalance(root->left) >= 0)
        {
            return rightRotation(root);
        }
        // left right
        else
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }

    // Right Side
    else if (balance < -1)
    {

        // right right
        if (getBalance(root->right) <= 0)
        {
            return leftRotation(root);
        }
        // right left
        else
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }

    else
        return root;
}