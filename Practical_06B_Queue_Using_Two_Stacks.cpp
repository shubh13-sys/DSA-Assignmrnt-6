#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

    void transferIfNeeded() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    void enqueue(int value) {
        s1.push(value);
        cout << value << " inserted\n";
    }

    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!\n";
            return;
        }

        transferIfNeeded();
        cout << "Deleted: " << s2.top() << endl;
        s2.pop();
    }

    void peek() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!\n";
            return;
        }

        transferIfNeeded();
        cout << "Front element: " << s2.top() << endl;
    }

    bool empty() const {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.peek();
    q.dequeue();
    q.dequeue();
    q.peek();

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;
    return 0;
}
