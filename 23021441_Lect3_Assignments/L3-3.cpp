#include <iostream>
using namespace std;

const int MAX = 1000;
int queue[MAX];
int front = 0, rear = 0;

void print() {
    for (int i = front; i < rear; i++) {
        cout << queue[i] << " ";
    }
}

void enqueue(int x) {
    if (rear == MAX) return;
    queue[rear++] = x;
}

void dequeue() {
    if (front == rear) return;
}

int main() {
    int n;
    cin >> n;
    string operat;
    int x;

    for (int i = 0; i < n; i++) {
        cin >> operat;
        if (operat == "enqueue") {
            cin >> x;
            enqueue(x);
        } else {
            dequeue();
        }
    }

    print();
    return 0;
}/*
Khai báo MAX = 1000
Khai báo mảng queue có kích thước MAX
Khởi tạo front = 0, rear = 0

Hàm print():
    Lặp i từ front đến rear - 1:
        In queue[i]

Hàm enqueue(x):
    Nếu rear == MAX:
        Trả về (Hàng đợi đầy)
    Gán queue[rear] = x
    Tăng rear lên 1

Hàm dequeue():
    Nếu front == rear:
        Trả về (Hàng đợi rỗng)
    Tăng front lên 1

Hàm main():
    Nhập số nguyên n (số thao tác)
    Lặp i từ 0 đến n - 1:
        Nhập operat (chuỗi thao tác)
        Nếu operat là "enqueue":
            Nhập số nguyên x
            Gọi enqueue(x)
        Ngược lại (operat là "dequeue"):
            Gọi dequeue()

    Gọi print()

Độ phức tạp(enqueue,equeue): O(1)

