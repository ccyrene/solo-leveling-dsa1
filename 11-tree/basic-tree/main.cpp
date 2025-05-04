#include<iostream>
using namespace std;


// basic tree (binary tree)

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data) {
    Node *node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

// Function to insert a node in a binary search tree (BST)
void insert(Node *&root, int data) {
    
    // base case
    if (root == nullptr) {
        root = newNode(data);
        return;
    }

    // recursive case
    if(data < root->data){
        insert(root->left, data);
    }else{
        insert(root->right, data);
    }
}

// Function for inorder traversal (left, root, right)
void inorderTraversal(Node *root) {

    // base case
    if(root == nullptr){
        return;
    }

    // traversal left-side
    inorderTraversal(root->left);
    cout << root->data << " ";

    //traversal right-side
    inorderTraversal(root->right);

}

int main() {
    Node *root = nullptr;

    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 8);

    cout << "Inorder Travelsal: ";
    inorderTraversal(root);
    cout << "\n";

    return 0;
}