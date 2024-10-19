// Binary Search Tree

// sorted order

/*
                   x
                y     z
        y < x
        z > x
*/

/*
    insertion:
        if value < root (left side)
        else right side

*/

// 3 7 4 1 6 8
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

    // NLR
    void preOrder(Node *node)
    { // passing address of root node
        if (node == NULL)
            return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // LNR
    void inOrder(Node *node) // output will be in sorted form
    {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    // LRN
    void postOrder(Node *node)
    {
        if (node == NULL)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

    bool search(Node *node, int target)
    {
        if (!node)
        {
            return 0;
        }
        if (node->data == target)
        {
            return 1;
        }
        else if (target < node->data)
        {
            return search(node->left, target);
        }
        else
        {
            return search(node->right, target);
        }
    }

    /*
    1. if leaf node:
        delete node
        return NULL
    2. if only one child:
        if only left exist:
            delete node
            return left child
        if only right exist:
            delete Node
            return right child
    3. If both child:
        Find the greatest element in left (we can also find smallest element at right)

        if(parent!=root)
            Parent ke right ko bolo child ke left ko point kero
            child->left = root->left
            child->right = root->right
            delete root
            return child
        if(parent == root)
            child->right = root->right
            delete root
            return child
    */
    Node *deleteNode(Node *root, int target)
    {
        if (!root)
        {
            return NULL;
        }

        if (target < root->data)
        {
            root->left = deleteNode(root->left, target);
            return root;
        }
        else if (target > root->data)
        {
            root->right = deleteNode(root->right, target);
            return root;
        }
        else
        {
            // Leaf Node
            if (!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            // 1 child exist
            else if (!root->right) // left side exist
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else if (!root->left) // right side exist
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            // 2 child exist
            else
            {
                // find the greatest element from left
                Node *child = root->left;
                Node *parent = root;
                // right mot node tak pohcnhna hai
                while (child->right)
                {
                    parent = child;
                    child = child->right;
                }
                // root is not equal to parent
                if (root != parent)
                {
                    parent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                }
                // root is equal to parent
                else
                {
                    child->right = root->right;
                }
                delete root;
                return child;
            }
        }
    }

    void printTree(Node *node, int space = 0) const
    {
        if (node == nullptr)
            return;

        // Increase distance between levels
        space += 5;

        // Process right child first
        printTree(node->right, space);

        // Print current node after space count
        cout << endl;
        for (int i = 5; i < space; i++)
        {
            cout << " ";
        }
        cout << node->data << endl;

        // Process left child
        printTree(node->left, space);
    }
};

// Main function to test the Binary Search Tree functionalities
int main()
{
    // Initial values to insert into the BST
    int arr[] = {3, 7, 4, 1, 6, 8};
    BST tree;

    // Insert nodes into the tree
    for (int i = 0; i < 6; i++)
    {
        tree.setRoot(tree.insertion(tree.getRoot(), arr[i]));
    }

    // Test traversals
    cout << "In-order Traversal (sorted): ";
    tree.inOrder(tree.getRoot());
    cout << endl;

    cout << "Pre-order Traversal: ";
    tree.preOrder(tree.getRoot());
    cout << endl;

    cout << "Post-order Traversal: ";
    tree.postOrder(tree.getRoot());
    cout << endl;

    // Print tree structure
    cout << "\nTree Structure:" << endl;
    tree.printTree(tree.getRoot());

    // Test searching for a value
    int searchValue = 4;
    cout << "\nSearching for " << searchValue << ": ";
    cout << (tree.search(tree.getRoot(), searchValue) ? "Found" : "Not Found") << endl;

    // Test deletion of a value
    int deleteValue = 7;
    cout << "\nDeleting value " << deleteValue << " from tree." << endl;
    tree.setRoot(tree.deleteNode(tree.getRoot(), deleteValue));

    // Print tree structure after deletion
    cout << "\nTree Structure after Deletion:" << endl;
    tree.printTree(tree.getRoot());

    // Traversal after deletion
    cout << "\nIn-order Traversal after Deletion: ";
    tree.inOrder(tree.getRoot());
    cout << endl;

    return 0;
}