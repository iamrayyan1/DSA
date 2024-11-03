// Limitation of bst:
/*
Insertion: O(n)
Search: O(n)
Deletion: O(n)
** in worst cases
Creation:
    - Array advance: nlogn
    - Runtime: n^2
*/

/*
We can do insertion, searching and deletion in O(n) using AVL trees
AVL: It is a self balance binary search tree (ek side pae tree ko grow hone nahi deta)

Example:
    10, 20, 30 given in input
BST:
    10
        20
            30
AVL:
    20
10      30

Example:
    30, 10, 20 given in input
BST:
    30
10
    20
AVL:
    20
10      30

Unbalanced cases:
    10 20 30     (R-R)
    30 20 10     (L-L)
    30 10 20     (L-R)
    10 30 20
Balanced cases:
    20 10 30
    20 30 10
*/

/*
Rotation:
    Left Rotation
    Right Rotation

Case 1: R-R  -> Rotate top element to Left
        10                  (R-R)
            20
                30

Case 2: L-L  -> Rotate top element to Right
          30                  (L-L)
      20
  10

Case 3: L-R  -> First rotate middle element to left than rotate top element to right
      30                  (L-R)
  10
          20

Case 4: R-L  -> First rotate middle element to right than rotate top element to left
          30                  (R-L)
      20
  10
*/

/*
Edge cases:
                A
                  \
              /     T1
            B
              \
          /    T2
        C
          \
            T3
    Right Rotation:
        B ka right child(T2) ko A ka left child bana dou


    A
  T1  \
        B
     T2   \
            C
          T3
    Left Rotation:
        B ka left child(T2) ko A ka right child bana dou
*/

/*
cover cases from yt video (44-57)
*/

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

Node *insert(Node *root, int key)
{
    // Doesn't exist
    if (!root)
    {
        return new Node(key);
    }

    // exist kerta hai
    if (key < root->data)
    { // left side
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    { // right side
        root->right = insert(root->right, key);
    }
    else
    {
        return root; // duplicate not allowed
    }

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Check Balancing
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && key < root->left->data)
    {
        return rightRotation(root); // rotate top element to right
    }

    // Left Right Case
    else if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotation(root->left); // rotate middle element to left
        return rightRotation(root);            // rotate top element to right
    }

    // Right Right Case
    else if (balance < -1 && key > root->left->data)
    {
        return leftRotation(root); // rotate top element to left
    }

    // Right Left Case
    else if (balance < -1 && key < root->left->data)
    {
        root->right = rightRotation(root->right); // rotate middle element to right
        return leftRotation(root);                // rotate top element to left
    }

    // Already Balanced
    else
    {
        return root;
    }
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

    // Duplicate elements not allowed
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 550);

    cout << " In-Order: " << endl;
    inOrder(root);
}