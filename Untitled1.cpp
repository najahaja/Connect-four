#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    else if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}
Node* createBST() {
    Node* root = NULL;
    int value;
    cout << "Enter the data to create a BST (enter -1 to stop): ";
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        root = insert(root, value);
    }
    return root;
}
void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    } 
     preorderTraversal(root->left); 
    preorderTraversal(root->right); 
     cout<< root->data << " "; 
}
int main() {
    Node* root = createBST();
    cout << "postorder Traversal: ";
    preorderTraversal(root);
    cout << endl;
    return 0;
}

