#include<iostream>
#include<queue> // using queue for order of display
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;
};

void breadthFirstSearch(Node *root) {

    if (root == nullptr) {
        return; // Handle empty tree case
    }

    queue<Node *> q;
    q.push(root);

    while(!q.empty()){

        // process the current node
        Node *currentNode = q.front();
        q.pop();
        cout << currentNode->data << " ";

        // enqueue children if they exist
        if(currentNode->left != nullptr) 
            q.push(currentNode->left);
        if(currentNode->right != nullptr)
            q.push(currentNode->right);
    }

    cout << "\n";
}

int main() {

    Node *root = new Node{1};
    root->left = new Node{2};
    root->right = new Node{3};
    root->left->left = new Node{4};
    root->left->right = new Node{5};

    breadthFirstSearch(root);

    return 0;
}