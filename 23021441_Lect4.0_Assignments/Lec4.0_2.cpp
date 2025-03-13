#include <iostream>
using namespace std;

struct Node {
    int value;
    int priority;
    Node* prev;
    Node* next;

    Node(int v, int p) : value(v), priority(p), prev(nullptr), next(nullptr) {}
};
class PriorityQueue {
private:
    Node* head;
    Node* tail;

public:
    PriorityQueue() : head(nullptr), tail(nullptr) {}

    void enqueue(int value, int priority) {
        Node* newNode = new Node(value, priority);
        if (!head) {
            head = tail = newNode;
        } else {
            Node* current = head;
            while (current && current->priority >= priority) {
                current = current->next;
            }
            if (!current) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            } else if (current == head) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else {
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }
    }

    void dequeue() {
        if (!head) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void printQueue() {
        Node* current = head;
        while (current) {
            cout << "(" << current->value << ", " << current->priority << ")";
            if (current->next) {
                cout << "; ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string operation;
        cin >> operation;
        if (operation == "enqueue") {
            int value, priority;
            cin >> value >> priority;
            pq.enqueue(value, priority);
        } else if (operation == "dequeue") {
            pq.dequeue();
        }
    }

    pq.printQueue();

    return 0;
}
