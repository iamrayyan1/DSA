#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    vector<int> keys;
    vector<Node *> children;
    Node *parent;
    bool isLeaf;

    Node() : parent(nullptr), isLeaf(true) {}
};

Node *createNode()
{
    return new Node();
}

void insertInOrder(vector<int> &keys, int key)
{
    bool inserted = false;
    for (int i = 0; i < keys.size(); i++)
    {
        if (key < keys[i])
        {
            keys.insert(keys.begin() + i, key);
            inserted = true;
            break;
        }
    }
    if (!inserted)
    {
        keys.push_back(key);
    }
}

void split(Node *&root, Node *node)
{
    cout << "Splitting node with keys: ";
    for (int i = 0; i < node->keys.size(); i++)
    {
        cout << node->keys[i] << " ";
    }
    cout << endl;

    int middleKey = node->keys[1];
    Node *leftChild = createNode();
    Node *rightChild = createNode();

    leftChild->keys.push_back(node->keys[0]);
    rightChild->keys.push_back(node->keys[2]);
    leftChild->isLeaf = rightChild->isLeaf = node->isLeaf;

    if (!node->isLeaf)
    {
        leftChild->children.push_back(node->children[0]);
        leftChild->children.push_back(node->children[1]);
        rightChild->children.push_back(node->children[2]);
        rightChild->children.push_back(node->children[3]);
        for (int i = 0; i < leftChild->children.size(); i++)
            leftChild->children[i]->parent = leftChild;
        for (int i = 0; i < rightChild->children.size(); i++)
            rightChild->children[i]->parent = rightChild;
    }

    if (!node->parent)
    {
        Node *newRoot = createNode();
        newRoot->keys.push_back(middleKey);
        newRoot->children.push_back(leftChild);
        newRoot->children.push_back(rightChild);
        leftChild->parent = rightChild->parent = newRoot;
        newRoot->isLeaf = false;
        root = newRoot;
    }
    else
    {
        Node *parent = node->parent;
        insertInOrder(parent->keys, middleKey);

        int index = -1;
        for (int i = 0; i < parent->children.size(); i++)
        {
            if (parent->children[i] == node)
            {
                index = i;
                break;
            }
        }

        parent->children[index] = leftChild;
        parent->children.insert(parent->children.begin() + index + 1, rightChild);

        leftChild->parent = rightChild->parent = parent;

        if (parent->keys.size() == 3)
            split(root, parent);
    }
}

Node *mergeTrees(Node *root1, Node *root2)
{
    cout << "Merging: " << endl;

    Node *mergedRoot = createNode();

    for (int i = 0; i < root1->keys.size(); i++)
    {
        mergedRoot->keys.push_back(root1->keys[i]);
    }
    mergedRoot->children.push_back(root1);
    root1->parent = mergedRoot;

    for (int i = 0; i < root2->keys.size(); i++)
    {
        mergedRoot->keys.push_back(root2->keys[i]);
    }
    mergedRoot->children.push_back(root2);
    root2->parent = mergedRoot;

    for (int i = 1; i < mergedRoot->keys.size(); i++)
    {
        int key = mergedRoot->keys[i];
        int j = i - 1;
        while (j >= 0 && mergedRoot->keys[j] > key)
        {
            mergedRoot->keys[j + 1] = mergedRoot->keys[j];
            j--;
        }
        mergedRoot->keys[j + 1] = key;
    }

    if (mergedRoot->keys.size() == 3)
        split(mergedRoot, mergedRoot);

    return mergedRoot;
}

void printTree(Node *root, int level = 0)
{
    if (!root)
        return;

    cout << "Level " << level << ": ";
    for (int i = 0; i < root->keys.size(); i++)
    {
        cout << root->keys[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i], level + 1);
    }
}

int main()
{
    Node *root1 = createNode();
    Node *root2 = createNode();

    root1->keys = {10, 20};
    Node *leaf1 = createNode();
    leaf1->keys = {5};
    Node *leaf2 = createNode();
    leaf2->keys = {15};
    root1->children.push_back(leaf1);
    root1->children.push_back(leaf2);
    leaf1->parent = root1;
    leaf2->parent = root1;

    root2->keys = {30, 40};
    Node *leaf3 = createNode();
    leaf3->keys = {25};
    Node *leaf4 = createNode();
    leaf4->keys = {50};
    root2->children.push_back(leaf3);
    root2->children.push_back(leaf4);
    leaf3->parent = root2;
    leaf4->parent = root2;

    cout << "Tree 1:" << endl;
    printTree(root1);

    cout << "Tree 2:" << endl;
    printTree(root2);

    Node *mergedTree = mergeTrees(root1, root2);

    cout << "Merged Tree:" << endl;
    printTree(mergedTree);

    return 0;
}
