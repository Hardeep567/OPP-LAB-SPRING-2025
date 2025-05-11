#include <iostream>
#include <exception>
using namespace std;

class QueueOverflowException : public exception {};
class QueueUnderflowException : public exception {};

template <typename T>
class Queue {
private:
    T* data;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int size) : capacity(size), front(0), rear(-1), count(0) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(const T& item) {
        if (count == capacity) {
            throw QueueOverflowException();
        }
        rear = (rear + 1) % capacity;
        data[rear] = item;
        ++count;
    }

    T dequeue() {
        if (count == 0) {
            throw QueueUnderflowException();
        }
        T item = data[front];
        front = (front + 1) % capacity;
        --count;
        return item;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    int size() const {
        return count;
    }
};

int main() {
    Queue<int> q(3);

    try {
        cout << "Attempting to enqueue to a full queue" << endl;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
    }
    catch (QueueOverflowException& e) {
        cout << "Caught QueueOverflowException - what(): " << e.what() << endl;
    }

    try {
        cout << "\nDequeuing all elements"<< endl;
        while (!q.isEmpty()) {
            cout << "Dequeued: " << q.dequeue() << endl;
        }

        cout << "\nAttempting to dequeue from an empty queue"<< endl;
        q.dequeue();
    }
    catch (QueueUnderflowException& e) {
        cout << "Caught QueueUnderflowException - what(): " << e.what() << endl;
    }

    return 0;
}
