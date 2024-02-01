#include <iostream>
#include <string>

using namespace std;

class StackElem {
public:
    string value;
    StackElem * next;

    StackElem(string insertedVal): value(insertedVal), next(nullptr) {}
};

class Stack {
private:
    StackElem * _top;
public:
    Stack(): _top(nullptr) {}

    void push(string elem) {
        StackElem * newElem = new StackElem(elem);
        newElem -> next = _top;
        _top = newElem;
    }

    string pop() {
        if (!_top) {
            cout << "Stos jest pusty\n";
            return "";
        }
        string poppedValue = _top->value;
        StackElem* temp = _top;
        _top = _top->next;
        delete temp;
        return poppedValue;
    }


    void display() {
        StackElem * current = _top;
        while (current) {
            cout << current -> value << " ";
            current = current -> next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    bool loop = true;
    char ans;
    string elem;
    while (loop) {
        cout << "Podaj jedna z opcji, aby wykonac odpowiednia operacje\n" <<
                  "d - dodanie do stosu\n" <<
                  "u - usuniecie ze stosu\n" <<
                  "w - wyswietlenie zawartosci\n" <<
                  "x - aby zakonczyc\n";
        cin >> ans;
        if (ans == 'd') {
            cout << "Podaj element, ktory ma zostac wprowadzony\n";
            cin >> elem;
            stack.push(elem);
        } else if (ans == 'u') {
            stack.pop();
        } else if (ans == 'w') {
            stack.display();
        } else if (ans == 'x') {
            loop = false;
        } else {
            cout << "Niepoprawna opcja\n";
        }
    }
    return 0;
}