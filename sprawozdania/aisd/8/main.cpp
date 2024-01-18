#include <iostream>
#include <list>

using namespace std;

template <typename T>
class Queue {
private:
    list<T> _elements;

public:
    void enqueue(T element) {
        _elements.push_back(element);
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return T();
        }
        T frontElement = _elements.front();
        _elements.pop_front();
        return frontElement;
    }

    bool isEmpty() {
        return _elements.empty();
    }

    T front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return T();
        }
        return _elements.front();
    }

    T back() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return T();
        }
        return _elements.back();
    }

    void printQueue() {
        for (const T element: _elements) {
            cout << element << " ";
        }
        cout << endl;
    }
};

template <typename T>
class PriorityQueue {
private:
    list<pair<int, T>> _elements;

public:
    void enqueue(int priority, const T value) {
        auto iterator = _elements.begin();
        while (iterator != _elements.end() && iterator->first > priority) {
            iterator++;
        }
        _elements.insert(iterator, make_pair(priority, value));
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return T();
        }
        T value = _elements.front().second;
        _elements.pop_front();
        return value;
    }

    bool isEmpty() const {
        return _elements.empty();
    }

    void printQueue() const {
        for (const pair<int, T> element : _elements) {
            cout << element.second << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(5);
    queue.enqueue(10);

    queue.printQueue();

    queue.dequeue();

    queue.printQueue();

    PriorityQueue<int> priorityQueue;
    priorityQueue.enqueue(5, 1);
    priorityQueue.enqueue(0, 2);
    priorityQueue.enqueue(10, 10);
    priorityQueue.enqueue(15, 5);

    priorityQueue.printQueue();

    priorityQueue.dequeue();

    priorityQueue.printQueue();

    return 0;
}
