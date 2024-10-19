// It is a type of Data Structure that represent a hierarchical relationship between data elements called nodes

// minimize search time

/*
TREE TERMINOLIGIES:
- Node: Each data element
- Edges: Link between two nodes
- Root: Top most element
- Parent: If the node contains any sub-node, then that node is said to be the parent of that sub-
node.
- Child node: If the node is a descendant of any node, then the node is known as a child node.
- Sibling: The nodes that have the same parent are known as siblings.
- Leaf Node: The node of the tree, which doesn't have any child node. A leaf
node is the bottom-most node of the tree.
- Ancestor node: An ancestor of a node is any predecessor node on a path from the root to that
node.
- Descendant: The immediate successor of the given node is known as a descendant of a node.
- Level: Levels of heirarchy
- Height: Level distance/diffrence between top and bottom node
- Degree: No of children of a Node
*/


/*
Binary Tree: 
    It is defined as the tree data structure where each node has atmost 2 children

If a Binary Tree has N nodes, it will have (n - 1) edges
*/



// How to create Binary Tree:

// left and right pointer (it will carry the addresses of left and right nodes)
// We will take inputs from the user to fill the tree
// If the input is "-1", it means that the child of current node donot exist and move to next node
// We move level wise
// Recursive data structure: The tree is also known as a recursive data structure.

// 1. Root Node create
// 2. Left Child
// 3. Right Child
// 4. Repeat the process 2 and 3 for each Node   (will use queue here to apply FIFO for creating child of each node)
#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data = value;
        left = right = NULL;
    }
};


// this code is for creating tree level wise
int main(){
    queue<Node*> q;       // to store address of nodes to create the children level-wise
    int x, first, second;
    
    cout << "Enter the root value: ";
    cin >> x;
    Node *root = new Node(x);      // creating root element
    q.push(root);

// build the Binary Tree
    while(!q.empty()){    
        Node* temp = q.front();
        q.pop();

        // left child
        cout << "Enter the Left value of " << temp->data << " (-1 for no left child): ";
        cin >> first;
        if(first != -1){  // Only create left child if input is not -1
            temp->left = new Node(first);
            q.push(temp->left);
        }

        // right child
        cout << "Enter the Right value of " << temp->data << " (-1 for no right child): ";
        cin >> second;        
        if(second != -1){  // Only create right child if input is not -1
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }
}



/*
function to insert a new value recursively

Node* insert(Node* node, int value){
    if(node == nullptr){
        return new Node(value); // Create a new node if current node is null
    }
    if(value < node->data){
        node->left = insert(node->left, value); // Insert in the left subtree
    } 
    else{
        node->right = insert(node->right, value); // Insert in the right subtree
    }
    return node;
}
*/





// another method to create binary tree
// we will use recursion
// The Nodes will be created in recursive tree pattern 

/*
1. if x == -1 return NULL
2. else create Node
3. Left side jao
4. Rigth side jao
5. Return the address of Node
*/

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data = value;
        left = right = NULL;
    }
};

Node* BinaryTree(){
    int x;
    cin >> x;

    if(x==-1){
        return NULL;
    }

    Node* temp = new Node(x);

    // Recursively create the left subtree
    cout << "Enter the left child of "<< x << ": ";
    temp->left = BinaryTree(); 

    // Recursively create the right subtree
    cout << "Enter the right child of "<< x << ": "; 
    temp->right = BinaryTree(); 
    return temp;
}

int main(){
    cout << "Enter the root Node: ";
    Node* root;
    root = BinaryTree();
}





// Traversal

/*
Pre-Order: N-L-R   (pehle mujhe print kerao phir left pae jao aur phir right pae)
In-Order: L-N-R    (pehle left pae jao, phir mujhe print kerao and then right pae jao)
Post-Order: L-R-N  (mujhe print kerwane se pehle, left aur right jao)
*/


// Pre-Order:
/*
1. Print Node
2. Left Side
3. Right Side
*/

void preOrder(Node *node){         // passing address of root node
    if (node == NULL) 
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}


// In-Order:
/*
1. Left Side
2. Print Node
3. Right Side
*/

void inOrder(Node *node){         // passing address of root node
    if (node == NULL) 
        return;
    inOrder(node->left); 
    cout << node->data << " ";
    inOrder(node->right);
}


// Post-Order:
/*
1. Left Side
2. Right Side
3. Print Node
*/

void postOrder(Node *node){         // passing address of root node
    if (node == NULL) 
        return;
    postOrder(node->left); 
    postOrder(node->right);
    cout << node->data << " ";
}


