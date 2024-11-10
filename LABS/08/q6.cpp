#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

class modifiedTree
{
public:
    void recoverTree(Node *root)
    {
        Node *first = NULL, *second = NULL, *previous = NULL;

        findSwappedNodes(root, first, second, previous);

        if (first && second)
        {
            cout << "Swapped nodes found: " << first->data << " and " << second->data << endl;
            swap(first->data, second->data);
        }
    }

private:
    void findSwappedNodes(Node *node, Node *&first, Node *&second, Node *&previous)
    {
        if (!node)
            return;

        findSwappedNodes(node->left, first, second, previous);

        if (previous && node->data < previous->data)
        {
            if (!first)
            {
                first = previous;
            }
            second = node;
        }

        previous = node;

        findSwappedNodes(node->right, first, second, previous);
    }
};

void inOrder(Node *node)
{
    if (!node)
        return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(2);

    cout << "BST before: ";
    inOrder(root);
    cout << endl;

    modifiedTree corrector;
    corrector.recoverTree(root);

    cout << "BST after: ";
    inOrder(root);
    cout << endl;
}
