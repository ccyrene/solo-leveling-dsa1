#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Stack {
private:
    Node *top;

public:
    Stack() {
        this->top = nullptr;
    }

    // Function to add an item to the stack. It changes the top pointer
    void push(int x) {
        Node *newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << x << " pushed into stack\n";
    }

    // Function to remove an item from the stack. It changes the top pointer
    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return 0;
        }
        Node *temp = top;
        int poppedValue = top->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    // Function to check if the stack is empty
    bool isEmpty() { return top == nullptr; }

    // Function to return the top element of the stack without removing it
    int peek() {
        if(!isEmpty()) {
            return top->data;
        }else{
            cout << "Stack is empty\n";
            return -1;
        }
    }

};

int main(){
    Stack s;
    s.push(10);
    s.push(20);

    cout << "Top element is " << s.peek() <<"\n";
    cout << "Popped from stack: " << s.pop() << "\n";
    cout << "Top element is " << s.peek() <<"\n";
    return 0;
}