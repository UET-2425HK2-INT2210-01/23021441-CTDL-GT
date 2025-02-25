#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Stack {
public:
    Stack() : top(nullptr) {}

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void printStack() {
        printStackHelper(top);
        cout << endl;
    }

private:
    Node* top;

    void printStackHelper(Node* node) {
        if (node == nullptr) {
            return;
        }
        printStackHelper(node->next);
        cout << node->data << " ";
    }
};

int main() {
    int n;
    cin >> n;
    Stack s;
    for (int i = 0; i < n; ++i) {
        string operation;
        cin >> operation;
        if (operation == "push") {
            int x;
            cin >> x;
            s.push(x);
        } else if (operation == "pop") {
            s.pop();
        }
    }

    s.printStack();
    return 0;
}
