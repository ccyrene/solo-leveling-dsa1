#include<iostream>
using namespace std;

class Node {
public:
    int data;
    int priority;
    Node *next;

    Node(int d, int p): data(d), priority(p), next(nullptr) {}
};

class PriorityQueue {
    Node *head;
public:
    PriorityQueue(): head(nullptr) {}

    void enqueue(int d, int p) {
        Node *newNode = new Node(d, p);
        if (head == nullptr || head->priority > p) {
            newNode->next = head;
            head = newNode;
        }else{
            Node *temp = head;
            // find correct position of priority
            while(temp->next != nullptr && temp->next->priority <= p){
                temp=temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void dequeue() {
        if (head == nullptr) {
            cout << "Queue is empty\n";
            return;
        }

        Node *temp = head;
        cout << temp->data << " dequeued\n";
        head = head->next;
        delete temp; 
    }

    void display(){
        if (head == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        Node *temp = head;
        while(temp != nullptr){
            cout << temp->data << "(" << temp->priority << ") ";
            temp = temp->next;
        }
        cout << "\n";
    }

};

int main() {
    PriorityQueue q;

    q.enqueue(1, 2);
    q.enqueue(2, 2);
    q.enqueue(3, 1);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}