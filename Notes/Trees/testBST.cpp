#include <iostream>

using namespace std;

class BST{
	struct Node{
		int data;
		Node* left;
		Node* right;

		Node(int val=0){
			data=val;
			left=right=nullptr;
		}

	};
	Node* root;


//tree operations 

	//tree treversal methods
	void preorder(Node* root) {
	    if (root == nullptr) return;
	    cout << root->data << " ";  // Visit the root
	    preorder(root->left);  // Traverse left
	    preorder(root->right);  // Traverse right
    }
	void inorder(Node* root){
		if(root==nullptr){
			return;
		}
		inorder(root->left);
		cout<<root->data<<" ",
		inorder(root->right);
	}
	void postorder(Node* root) {
	    if (root == nullptr) return;
	    postorder(root->left);  // Traverse left
	    postorder(root->right);  // Traverse right
	    cout << root->data << " ";  // Visit the root
	}

//add new node 
	void insertNode(Node*& root, int val){
		if(root ==nullptr){
			root=new Node(val);
		}
		if(val==root->data){
			return;
		}
		else if(val>root->data){
			insertNode(root->right, val);
		}
		else{
			insertNode(root->left, val);
		}
	}
	// private search element 
	Node* searchNode(Node* root, int key){
		if(root==nullptr){
			return root;
		}
		Node* temp=root;
		while(!temp){
			if(key==temp->data){
				return temp;
			}
			else if(key>temp->data){
				temp=temp->right;
			}
			else{
				temp=temp->left;
			}
		}
		return temp;
	}

	bool searchRecursion(Node* node, int key) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == key) {
            return true;
        }
        if (key < node->data) {
            return searchRecursion(node->left, key);
        }
        return searchRecursion(node->right, key);
    }
    //insert new node using loop
    void insertNewNode(Node*& root, int val){
    	Node* newNode=new Node(val);
    	if(root==nullptr){  
    		root=newNode;
    		return;
    	}
    	if(root->data==val){
    		return;
    	}
    	Node* temp=root;
    	while(true){
    		//left sub tree
    		if(val<temp->data){
    			if(temp->left!=nullptr)
    				temp=temp->left;
    			else{
    				temp->left=newNode; //newnode
    				break;
    			}

    		}	
    		//right sub tree
    		else{
    			if(temp->right!=nullptr)
    				temp=temp->right;
    			else{
    				temp->right=newNode;
    				break;
    			}

    		}
    	}
    }

int height(Node* root) {
    if (root == nullptr) {
        return -1; 
    } else {
        int lheight = height(root->left); 
        int rheight = height(root->right); 
        return (lheight > rheight) ? lheight + 1 : rheight + 1; 
    }
}

void printGivenLevel(Node* root, int level) {
    if (root == nullptr) {
        return; 
    } else if (level == 0) {
        cout << root->data << " "; 
    } else {
        printGivenLevel(root->left, level - 1); 
        printGivenLevel(root->right, level - 1); 
    }
}
//find minValueNode


void printLevelOrderBFS(Node* root) {
    int h = height(root); 
    for (int i = 0; i <= h; i++) {
        printGivenLevel(root, i); 
    }
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

public:
	BST(){
		root=nullptr;
	}
	
	//public method - add a new node
	void insertNode(int val){
		insertNode(root, val);
	}
	

	//public function for insertNewNode
	void insertNewNode(int val){
		insertNewNode(root, val);
	}

	// Function to insert a node into the BST (without duplicates)
// void insertNode(int newData) {
// 	//create a new Node 
// 	Node* newNode= new Node(newData);
//     // If the root is null, make the newNode the root
//     if (root == NULL) {
//         root = newNode;
//         return;
//     }

//     Node* temp = root; // Set temporary pointer to root
    
//     while (temp != NULL) {
//         // If the newNode's value already exists in the tree, do nothing
//         if (newNode->data == temp->data) {
//             return; // No duplicates allowed
//         }
//         // If newNode value is smaller, insert on the left if left is empty
//         else if (newNode->data < temp->data && temp->left == NULL) {
//             temp->left = newNode; // Insert on the left
//             break; // Exit the function
//         }
//         // Otherwise, move to the left subtree
//         else if (newNode->data < temp->data) {
//             temp = temp->left;
//         }
//         // If newNode value is larger, insert on the right if right is empty
//         else if (newNode->data > temp->data && temp->right == NULL) {
//             temp->right = newNode; // Insert on the right
//             break; // Exit the function
//         }
//         // Otherwise, move to the right subtree
//         else {
//             temp = temp->right;
//         }
//     }
// }

//public search method
	void searchNode(int key){
		Node* foundNode=searchNode(root, key);
		if(foundNode!=nullptr)
			cout<<"Element found!!"<<endl;
		else
			cout<<"Element not found!"<<endl;
	}
//public preorder method 
	void preorder(){
		preorder(root);
	}
//public inorder method 
	void inorder(){
		inorder(root);
	}
//public postorder method 
	void postorder(){
		postorder(root);
	}

//public method 
	  void searchRecursion(int key) {
        bool flag= searchRecursion(root, key);
        if(flag)
        	cout<<"Element found!!"<<endl;
        else
        	cout<<"Element not found!!"<<endl;
    }

void printLevelOrderBFS(){
	cout<<"BFS"<<endl;
	printLevelOrderBFS(root);
}
void deleteNode(int key){
	Node* n = deleteNode(root, key);
	if(n)
		cout<<"Node deleted !"<<endl;
	else
		cout<<"Node doesn't exist in tree hence not deleted !!"<<endl;
}


};

int main(){
	//create object of BST 
	BST tree;
	tree.insertNode(20);
	tree.insertNode(50);
	tree.insertNode(30);
	tree.insertNode(55);
	tree.insertNode(51);
	tree.insertNode(10);
	cout<<"Inorder traveral : "<<endl;
	tree.postorder();
	cout<<endl;

	cout<<"Search for 52"<<endl;
	tree.searchRecursion(55);

	
	tree.printLevelOrderBFS();
	tree.deleteNode(10);
	tree.printLevelOrderBFS();
	return 0;
}