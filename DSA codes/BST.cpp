#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }

    Node() {
        this->value = 0;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
public:
    Node* root;
    int height;

    BST() {
        this->root = NULL;
        height = 0;
    }

    void insertBST(int value) {
       Node* new_node = new Node(value);
       if (root == NULL) {
           this->root = new_node;
           return;
       }
       Node* parent = NULL;
       Node* current = this->root;

       while (current != NULL) {
           parent = current;
           if (new_node->value < current->value) {
               current = current->left;
           } else if (new_node->value > current->value) {
               current = current->right;
           } else {
               cout << "Already exists! Duplicates are not allowed." << endl;
               return;
           }
        }

       if (new_node->value < parent->value) {
           parent->left = new_node;
           cout << "Added to the left!" << endl;
       } else {
           parent->right = new_node;
           cout << "Added to the right!" << endl;
       }
    }
    
	Node* delete_node(Node* node, int val){
		if (node == NULL){
			return node;
		}
		if (val < node->value){
			node->left = delete_node(node->left, val);
		}
		else if (val > node->value){
			node->right = delete_node(node->right, val);
		}
		
		else{
			if(node->left == NULL){
				Node* temp = node->right;
				delete node;
				return temp;
			}
			else if(node->right == NULL){
				Node* temp = node->left;
				delete node;
			    return temp;
			}
			else{
				Node* successor = find_min(node->right);
				node->value = successor->value;
				node->right = delete_node(node->right, successor->value);
			}
		}
		return node;
	}
	
	Node* find_min(Node* node){
		Node* current = node;
		int minVal = 0;
		while (current->left != NULL){
			minVal = current->value;
			current = current->left;
		}
		return current;
	}  
    
    void inorderBST(Node* current) {
        if (current == NULL) {
            return;
        }

        inorderBST(current->left);
        cout << current->value << endl;
        inorderBST(current->right);
    }
};

int main() {
    BST bst1;
    bst1.insertBST(3);
    bst1.insertBST(5);
    bst1.insertBST(1);

    bst1.inorderBST(bst1.root);
    cout<<"-----------------------------------------------------"<<endl;
    bst1.delete_node(bst1.root, 5);
    bst1.inorderBST(bst1.root);

    return 0;
}

