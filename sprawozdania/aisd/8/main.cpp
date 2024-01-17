#include <iostream>
#include <list>

using namespace std;

template <class T>
struct Priority {
    T value;
    int priority;

    Priority(T val, int prio) : value(val), priority(prio) { }
};

template <typename T>
class Queue {
protected:
    list<T> _elements;

public:
    virtual void enqueue(T element) {
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
        for (const T element: this->_elements) {
            cout << element << " ";
        }
    };
};

template <typename T>
class PriorityQueue : public Queue<Priority<T>> {
public:
    void enqueue(T element) override {

    }
};

int main() {
    PriorityQueue<int> queue;
    queue.enqueue(1);
    queue.enqueue(5);
    queue.enqueue(10);

    queue.printQueue();
    
    return 0;
}
