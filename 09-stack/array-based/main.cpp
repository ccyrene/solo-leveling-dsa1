#include<iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    int top;
    int arr[MAX_SIZE];

public:

    Stack() {
        this->top = -1;
    }

    // Function to add an item to the stack. It increases top by 1
    void push(int x) {
        if(top>=(MAX_SIZE - 1)) {
            cout << "Stack Overflow" << "\n";
        }else{
            arr[++top] = x;
            cout << "pushed into stack\n";
        }
    }

    // Function to remove an item from the stack. It decreases top by 1
    int pop() {
        if(top < 0) {
            cout << "Stack Underflow\n";
            return 0;
        }else{
            int x = arr[top--];
            return x;
        }
    }

    // Function to return the top element of the stack without removing it
    int peek() {
        if (top < 0) {
            cout << "Stack is Empty\n";
            return 0;
        }else{
            int x = arr[top];
            return x;
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }

};


int main() {
    Stack s;
    s.push(10);
    s.push(20);
    cout << "Top element is " << s.peek() << "\n";
    cout << "Popped from stack: " << s.pop() << "\n";
    return 0;
}