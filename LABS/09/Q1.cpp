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

// INSERTION

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

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

Node *insert(Node *root, int key)
{
    if (!root)
    {
        return new Node(key);
    }

    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && key < root->left->data)
    {
        return rightRotation(root);
    }

    // Left Right Case
    if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // Right Right
    if (balance < -1 && key > root->right->data)
    {
        return leftRotation(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

bool isAVLHelper(Node *node, int &height, int minVal = 0, int maxVal = 0)
{
    if (node == NULL)
    {
        height = 0;
        return true;
    }

    if (node->data <= minVal || node->data >= maxVal)
    {
        return false;
    }

    int leftHeight, rightHeight;

    bool leftIsAVL = isAVLHelper(node->left, leftHeight, minVal, node->data);
    bool rightIsAVL = isAVLHelper(node->right, rightHeight, node->data, maxVal);

    height = max(leftHeight, rightHeight) + 1;

    bool isBalanced = abs(leftHeight - rightHeight) <= 1;

    return leftIsAVL && rightIsAVL && isBalanced;
}

bool isAVLTree(Node *root)
{
    int height = 0;
    return isAVLHelper(root, height);
}

void inOrder(Node *root)
{
    if (!root)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 550);

    if (isAVLTree(root))
    {
        cout << "The tree is a valid AVL tree." << endl;
    }
    else
    {
        cout << "The tree is a valid AVL tree." << endl;
    }

    cout << "In-Order Traversal: ";
    inOrder(root);
    cout << endl;

    return 0;
}
