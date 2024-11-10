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

Node *createBSTFromSortedArray(int *arr, int left, int right)
{
    if (left > right)
    {
        return NULL;
    }

    int mid = left + (right - left) / 2;
    Node *root = new Node(arr[mid]);

    root->left = createBSTFromSortedArray(arr, left, mid - 1);
    root->right = createBSTFromSortedArray(arr, mid + 1, right);

    return root;
}

Node *createBSTFromSortedArray(int *arr, int size)
{
    return createBSTFromSortedArray(arr, 0, size - 1);
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
    int arr[] = {0, 6, 12, 18, 24};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node *root = createBSTFromSortedArray(arr, size);

    cout << "BST: ";
    preOrder(root);
    cout << endl;

    return 0;
}
