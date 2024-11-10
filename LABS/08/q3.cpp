#include <iostream>
using namespace std;

class Node
{
private:
    int value;
    Node *left;
    Node *right;

public:
    Node(int value)
    {
        this->value = value;
        left = right = NULL;
    }

    friend class BST;
};

class BST
{
public:
    Node *root;

    BST() : root(NULL) {}

    Node *insert(Node *node, int value)
    {
        if (node == NULL)
        {
            return new Node(value);
        }
        if (value < node->value)
        {
            node->left = insert(node->left, value);
        }
        else
        {
            node->right = insert(node->right, value);
        }
        return node;
    }

    int maxProfitPath(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        int leftMax = maxProfitPath(node->left);
        int rightMax = maxProfitPath(node->right);

        return node->value + (leftMax > rightMax ? leftMax : rightMax);
    }

    void preOrder(Node *node)
    {
        if (node != NULL)
        {
            cout << node->value << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
};

int main()
{
    BST tree;
    tree.root = tree.insert(tree.root, 15);
    tree.root = tree.insert(tree.root, 3);
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 12);
    tree.root = tree.insert(tree.root, 8);
    tree.root = tree.insert(tree.root, 25);
    tree.root = tree.insert(tree.root, 9);

    cout << "Max Profit Path is: " << tree.maxProfitPath(tree.root) << endl;

    tree.preOrder(tree.root);
}
