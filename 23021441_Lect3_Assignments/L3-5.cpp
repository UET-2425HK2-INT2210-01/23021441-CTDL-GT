#include <iostream>
using namespace std;
class Stack {
private:
    static const int MAX = 1000;
    int arr[MAX];
    int top;

public:
    Stack() { top = 0; }

    void push(int x) {
        if (top == MAX) return;
        arr[top++] = x;
    }

    void pop() {
        if (top == 0) return;
        top--;
    }

    void print() {
        for (int i = 0; i < top; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    Stack stack;
    int n;
    cin >> n;
    string operat;
    int x;

    for (int i = 0; i < n; i++) {
        cin >> operat;
        if (operat == "push") {
            cin >> x;
            stack.push(x);
        } else {
            stack.pop();
        }
    }
    stack.print();
    return 0;
}
/* giả code:
Khởi tạo:
    MAX = 1000   (Kích thước tối đa của stack)
    n = 0       ( Số phần tử hiện có trong stack)
    Mảng stack[MAX]  ( Mảng dùng để lưu trữ stack)

Hàm push(x):
    Nếu n = MAX thì return   (Nếu stack đầy, không thêm phần tử)
    Nếu n < MAX:
        Gán stack[n] = x
        Tăng n lên 1

Hàm pop():
    Nếu n == 0 thì return ( Nếu stack rỗng, không xóa phần tử)
    Nếu n > 0:
        Giảm n đi 1
Hàm print():
    Nếu n == 0:
        Kết thúc hàm
    Lặp i từ 0 đến n - 1:
        In stack[i] + "

Hàm main():
    Khởi tạo stack
    Đọc số nguyên n
    Lặp n lần:
        Đọc chuỗi operat
        Nếu operat = "push":
            Đọc số nguyên x
            Gọi push(x)
        Nếu operat = "pop":
            Gọi pop()
    Gọi print() để in các phần tử còn lại trong stack
Độ phức tạp ( hàm push và pop): O(1)
Độ phức tạp (hàm print): O(n)
Độ phức tạp (cả chương trình): O(n)
