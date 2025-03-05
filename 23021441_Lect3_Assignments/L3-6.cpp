#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};
class Stack {
private:
    Node* tail;

public:
    Stack() : tail(nullptr) {}

    ~Stack() {
        while (tail) pop();
    }

    void push(int x) {
        Node* newNode = new Node(x);
        if (!tail) {
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop() {
        if (!tail) return;
        Node* tmp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        delete tmp;
    }

    void print() const {
        Node* current = tail;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};
int main() {
    int n;
    cin >> n;
    Stack stack;

    for (int i = 0; i < n; ++i) {
        string operation;
        cin >> operation;
        if (operation == "push") {
            int x;
            cin >> x;
            stack.push(x);
        } else if (operation == "pop") {
            stack.pop();
        }
    }
    stack.print();
    return 0;
}
/*    Mã giả:
        Khai báo Node: data, next và prev
        Khai báo Stack: tail = nullptr
        Hàm print():
            tmp = tail, lặp qua danh sách ngược và in ra tmp->data
            tmp = tmp->prev
        Hàm push(x):
            Nếu danh sách trống: tail = newNode
            Nếu không: newNode->prev = tail, tail->next = newNode, tail = newNode
        Hàm pop():
            Nếu danh sách trống: return
            tmp = tail, tail = tmp->prev, nếu tail != nullptr thì tail->next = nullptr, xóa tmp
        Hàm main():
            Đọc n
            Lặp n lần:
                Đọc operat
                Nếu operat = push:
                    Đọc x, gọi hàm push(x)
                Nếu operat = pop:
                    Gọi hàm pop()
            Gọi hàm print()
Độ phức tạp ( hàm push và pop): O(1)
Độ phức tạp (hàm print): O(n)
Độ phức tạp (cả chương trình): O(n)
