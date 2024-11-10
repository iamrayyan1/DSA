#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
    friend class BST;
};

class BST
{
    Node *root;

public:
    BST()
    {
        root = NULL;
    }

    Node *getRoot() { return root; }

    void setRoot(Node *newRoot) { root = newRoot; }

    Node *insertion(Node *node, int value)
    {
        if (node == NULL)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insertion(node->left, value);
        }
        else
        {
            node->right = insertion(node->right, value);
        }

        return node;
    }

    void inOrder(Node *node) // output will be in sorted form
    {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void MakeString(Node *root, int *arr, int &index)
    {
        if (root == nullptr)
            return;
        MakeString(root->left, arr, index);
        arr[index++] = root->data;
        MakeString(root->right, arr, index);
    }
};

int main()
{
    BST b;
    Node *root = nullptr;
    root = b.insertion(root, 15);
    b.insertion(root, 10);
    b.insertion(root, 20);
    b.insertion(root, 8);
    b.insertion(root, 12);
    b.insertion(root, 16);
    b.insertion(root, 25);
    b.insertion(root, 32);
    b.insertion(root, 6);
    b.insertion(root, 35);

    cout << "inOrder:" << endl;
    b.inOrder(root);

    int size = 10;
    int *arr = new int[size];
    int index = 0;

    b.MakeString(root, arr, index);

    cout << "\n\nString Representation: \n";
    for (int i = 0; i < index; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    Node *root2 = nullptr;
    for (int i = 0; i < index; i++)
    {
        root2 = b.insertion(root2, arr[i]);
    }

    cout << "\ninOrder:" << endl;
    b.inOrder(root2);

    delete[] arr;

    return 0;
}