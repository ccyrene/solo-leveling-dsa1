#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element is: " << q.front() << "\n";
    cout << "Back element is: " << q.back() << "\n";

    q.pop();
    cout << "Front element after pop: " << q.front() << "\n";
    
    if (!q.empty()) {
        cout << "Queue is not empty\n";
    }

    cout << "Size of queue is: " << q.size() << "\n";

    return 0;

}