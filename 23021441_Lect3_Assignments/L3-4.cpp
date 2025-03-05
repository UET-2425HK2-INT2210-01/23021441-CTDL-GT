#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    void print() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    string operation;
    int x;
    Queue queue;
    for (int i = 0; i < n; i++) {
        cin >> operation;
        if (operation == "enqueue") {
            cin >> x;
            queue.enqueue(x);
        } else if (operation == "dequeue") {
            queue.dequeue();
        }
    }
    queue.print();
    return 0;
}
/*
Định nghĩa cấu trúc Node:
     Thuộc tính:
         data (lưu trữ giá trị của nút)
        next (con trỏ trỏ đến nút tiếp theo)
    Hàm khởi tạo:
         Nhận vào một giá trị x
         Gán data = x, next = null

Định nghĩa lớp Queue:
    Thuộc tính:
        front (con trỏ trỏ đến phần tử đầu hàng đợi)
        rear (con trỏ trỏ đến phần tử cuối hàng đợi)
    Hàm khởi tạo:
        Gán front = null, rear = null
    Hàm enqueue(x):
        Tạo một nút mới chứa giá trị x
        Nếu rear là null (hàng đợi rỗng) thì:
            Gán front = rear = nút mới
        Ngược lại:
            Gán rear.next = nút mới
            Gán rear = nút mới
    Hàm dequeue():
        Nếu front là null (hàng đợi rỗng) thì thoát
        Lưu nút cần xóa vào biến temp
        Gán front = front.next
        Nếu front trở thành null thì gán rear = null
        Xóa temp
    Hàm print():
        Duyệt từ front đến rear, in ra giá trị từng nút

Hàm main:
    Nhập vào số lượng thao tác n
    Khởi tạo hàng đợi queue
    Lặp n lần:
         Nhập vào thao tác operation
         Nếu operation là "enqueue":
            - Nhập vào giá trị x
            - Gọi queue.enqueue(x)
        Nếu operation là "dequeue":
            - Gọi queue.dequeue()
    Gọi queue.print() để in danh sách các phần tử trong hàng đợi

Đánh giá độ phức tạp
Enqueue() O(1).
Dequeue() O(1).
Print () O(n).
Toàn chương trình O(n)
