#include<iostream>
using namespace std;

#define SIZE 5

class CircularQueueArray {
    int items[SIZE], front, rear;

public:

    CircularQueueArray(): front(-1), rear(-1) {}

    bool isFull() {
        return (rear + 1) % SIZE == front;
    }

    bool isEmpty() {
        return front == -1;
    }


    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full\n";
        }else{
            if (isEmpty()) front=0;
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            cout << element << " inserted into queue\n";
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }else{
            int element = items[front];
            cout << element << " removed from queue\n";
            if (front == rear) {
                front = -1;
                rear = -1;
            }else{
                front = (front + 1) % SIZE;
            }
        
            return element;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements are: ";
        if (rear >= front) {
            for(int i=front; i<=rear; i++)
                cout << items[i] << " ";
        }else{
            for(int i=front; i<SIZE; i++)
                cout << items[i] << " ";
            for(int i=0; i<=rear; i++) {
                cout << items[i] << " ";
            }

            cout << "\n";
        }
        cout << "\n";
    }

};

int main() {
    CircularQueueArray q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}