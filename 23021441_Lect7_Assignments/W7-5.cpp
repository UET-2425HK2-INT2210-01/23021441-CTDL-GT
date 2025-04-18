#include <iostream>
using namespace std;

// Hàm in một hoán vị
void printPermutation(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;
}

// Hàm sinh các hoán vị bằng đệ quy và swap
void generatePermutations(int arr[], int start, int n) {
    // Khi đã đến cuối mảng (đủ n phần tử)
    if (start == n) {
        printPermutation(arr, n); // In hoán vị hiện tại
        return;
    }

    // Duyệt qua các phần tử từ vị trí start đến cuối
    for (int i = start; i < n; i++) {
        // Đổi chỗ phần tử hiện tại với phần tử tại vị trí start
        swap(arr[start], arr[i]);

        // Đệ quy để xử lý các vị trí tiếp theo
        generatePermutations(arr, start + 1, n);

        // Đổi lại để trở về trạng thái ban đầu (backtrack)
        swap(arr[start], arr[i]);
    }
}

int main() {
    int n;
    cin >> n; // Nhập vào số n

    // Tạo mảng chứa các số từ 1 đến n
    int numbers[n];
    for (int i = 0; i < n; i++) {
        numbers[i] = i + 1;
    }

    // Gọi hàm sinh hoán vị bắt đầu từ vị trí 0
    generatePermutations(numbers, 0, n);

    return 0;
}
