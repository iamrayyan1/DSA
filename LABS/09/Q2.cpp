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

class AVLTree
{
public:
    int rotationCount = 0;

    int getHeight(Node *root)
    {
        return root ? root->height : 0;
    }

    int getBalance(Node *root)
    {
        return getHeight(root->left) - getHeight(root->right);
    }

    Node *rightRotation(Node *root)
    {
        rotationCount++;
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
        rotationCount++;
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

        // Right Right Case
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
};

int main()
{
    AVLTree avl;
    Node *root = NULL;

    int values[] = {10, 20, 30, 25, 5, 15};

    for (int i = 0; i < 6; i++)
    {
        root = avl.insert(root, values[i]);
    }

    cout << "Total rotations performed: " << avl.rotationCount << endl;

    return 0;
}
