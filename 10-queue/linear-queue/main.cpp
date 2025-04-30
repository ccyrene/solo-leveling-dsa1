#include<iostream>
using namespace std;

#define SIZE 5

class Queue {

    int items[SIZE], front, rear;

public:
    Queue() {
        this->front=-1;
        this->rear=-1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full\n";
        }else{
            if (isEmpty()) front = 0;
            items[++rear] = element;
            cout << element << " inserted\n";
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }else{
            int element = items[front];
            if(front >= rear) {
                front = -1;
                rear = -1;
            }else{
                front++;
            }
            return element;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        }else{
            for(int i=front; i<=rear; i++) 
                cout << items[i] << " ";
            cout << "\n";
        }
    }

};


int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}