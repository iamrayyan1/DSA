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

    Node *addNode(Node *node, int value)
    {
        if (node == NULL)
        {
            return new Node(value);
        }
        if (value < node->value)
        {
            node->left = addNode(node->left, value);
        }
        else
        {
            node->right = addNode(node->right, value);
        }
        return node;
    }

    int treeHeight(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        int leftHeight = treeHeight(node->left);
        int rightHeight = treeHeight(node->right);

        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }

    void traverseLevel(Node *node, int level, bool leftToRight)
    {
        if (node == NULL)
        {
            return;
        }
        if (level == 1)
        {
            cout << node->value << ' ';
        }
        else if (level > 1)
        {
            if (leftToRight)
            {
                traverseLevel(node->left, level - 1, leftToRight);
                traverseLevel(node->right, level - 1, leftToRight);
            }
            else
            {
                traverseLevel(node->right, level - 1, leftToRight);
                traverseLevel(node->left, level - 1, leftToRight);
            }
        }
    }

    void zigzagTraversal(Node *node)
    {
        int height = treeHeight(node);
        bool leftToRight = true;

        for (int i = 1; i <= height; i++)
        {
            traverseLevel(node, i, leftToRight);
            leftToRight = !leftToRight;
        }
    }
};

int main()
{
    BST tree;
    tree.root = tree.addNode(tree.root, 11);
    tree.root = tree.addNode(tree.root, 3);
    tree.root = tree.addNode(tree.root, 13);
    tree.root = tree.addNode(tree.root, 7);
    tree.root = tree.addNode(tree.root, 19);
    tree.root = tree.addNode(tree.root, 15);
    tree.root = tree.addNode(tree.root, 7);
    tree.root = tree.addNode(tree.root, 9);
    tree.root = tree.addNode(tree.root, 17);
    tree.root = tree.addNode(tree.root, 1);

    tree.zigzagTraversal(tree.root);
    return 0;
}
