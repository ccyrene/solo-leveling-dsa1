#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "The top element is: " << myStack.top() << "\n";

    myStack.pop();
    cout << "After popping, the top element is: " << myStack.top() << "\n";

    if(!myStack.empty()) {
        cout << "The stack is not empty\n";
    }

    cout << "The stack size is: " << myStack.size() << "\n";

    return 0;

}