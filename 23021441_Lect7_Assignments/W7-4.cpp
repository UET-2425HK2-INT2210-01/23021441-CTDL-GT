#include <iostream>
using namespace std;

void printBinary(int arr[], int n) { // Ham in ra mảng số nguyên dưới dạng chuỗi nhị phân .Tham số: mảng arr và độ dài n
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;
}

void generateBinary(int arr[], int position, int n) {
    if (position == n) { // in kết quả và kết thúc đệ quy
        printBinary(arr, n);
        return;
    }

    // Gán 0 và đệ quy
    arr[position] = 0;
    generateBinary(arr, position + 1, n);

    // Gán 1 và đệ quy
    arr[position] = 1;
    generateBinary(arr, position + 1, n);
}

int main() {
    int n;
    cin >> n;

    int binaryArray[n]; // Tạo mảng với kích thước n
    generateBinary(binaryArray, 0, n);

    return 0;
}
