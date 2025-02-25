#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList {
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    int count_triplets() {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return 0;
        }

        int count = 0;
        Node* current = head->next;
        while (current->next != nullptr) {
            int sum = current->prev->data + current->data + current->next->data;
            if (sum == 0) {
                count++;
            }
            current = current->next;
        }
        return count;
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
    Node* tail;
};
int main() {
    int n;
    cin >> n;
    DoublyLinkedList list;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        list.append(x);
    }
    cout << list.count_triplets() << endl;
    return 0;
}
