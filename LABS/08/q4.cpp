#include <iostream>
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
        this->left = this->right = NULL;
    }
};

bool areIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    return (root1->data == root2->data &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right));
}

bool isSubtree(Node *T1, Node *T2)
{
    if (T2 == NULL)
        return true;

    if (T1 == NULL)
        return false;

    if (areIdentical(T1, T2))
        return true;

    return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
}

void preOrder(Node *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

int main()
{
    Node *T1 = new Node(10);
    T1->left = new Node(5);
    T1->right = new Node(15);
    T1->left->left = new Node(3);
    T1->left->right = new Node(7);
    T1->right->right = new Node(18);

    cout << "T1: ";
    preOrder(T1);
    cout << endl;

    Node *T2 = new Node(15);
    T2->right = new Node(18);

    cout << "T2: ";
    preOrder(T2);
    cout << endl;

    if (isSubtree(T1, T2))
    {
        cout << "T2 is a subtree of T1" << endl;
    }
    else
    {
        cout << "T2 is not a subtree of T1" << endl;
    }

    return 0;
}
