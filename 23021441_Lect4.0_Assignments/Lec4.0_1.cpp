#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void search(int data) {
        Node* temp = head;
        int position = 0;
        while (temp) {
            if (temp->data == data) {
                cout << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "NO" << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList ll;
    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;
        if (command == "append") {
            int x;
            cin >> x;
            ll.append(x);
        } else if (command == "search") {
            int x;
            cin >> x;
            ll.search(x);
        } else if (command == "reverse") {
            ll.reverse();
            ll.printList();
        }
    }
    return 0;
}
