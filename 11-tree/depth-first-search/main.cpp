#include<iostream>
#include<stack>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

// recursive based
void depthFirstSearch(Node *root) {

    // base case
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";

    // recursive case

    // depth for left-side
    depthFirstSearch(root->left);

    // depth for right-side
    depthFirstSearch(root->right);
}

// stack based
void depthFirstSearchStack(Node *root){
    if (root == nullptr)
        return; // handle empty tree

    stack<Node *> s;
    s.push(root);

    while(!s.empty()) {

        Node *currentNode = s.top();
        s.pop();

        cout << currentNode->data << " ";

        // push from right first, because stack concept (LIFO)
        if(currentNode->right != nullptr)
            s.push(currentNode->right);

        if(currentNode->left != nullptr)
            s.push(currentNode->left);

    }

    cout << "\n";

}

int main() {

    Node *root = new Node{1};
    root->left = new Node{2};
    root->right = new Node{3};
    root->left->left = new Node{4};
    root->left->right = new Node{5};

    depthFirstSearch(root);
    cout << "\n";

    depthFirstSearchStack(root);

    return 0;
}