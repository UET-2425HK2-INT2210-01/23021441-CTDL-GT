#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};
class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void insert(int p, int x) {
        Node* newNode = new Node(x);
        if (p == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < p - 1 && temp != nullptr; ++i) {
                temp = temp->next;
            }
            if (temp != nullptr) {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
    void deleteNode(int p) {
        if (p == 0 && head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* temp = head;
            for (int i = 0; i < p - 1 && temp != nullptr; ++i) {
                temp = temp->next;
            }
            if (temp != nullptr && temp->next != nullptr) {
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            }
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

private:
    Node* head;
};
int main() {
    int n;
    cin >> n;
    LinkedList list;
    for (int i = 0; i < n; ++i) {
        string operation;
        cin >> operation;
        if (operation == "insert") {
            int p, x;
            cin >> p >> x;
            list.insert(p, x);
        } else if (operation == "delete") {
            int p;
            cin >> p;
            list.deleteNode(p);
        }
    }
    list.printList();
    return 0;
}
