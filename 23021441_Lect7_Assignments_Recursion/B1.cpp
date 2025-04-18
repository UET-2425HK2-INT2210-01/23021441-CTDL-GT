#include <iostream>
using namespace std;

// Hàm đệ quy tính tổng từ 1 đến n
int sumToN(int n) {
    if (n == 1) return 1;           // Trường hợp cơ bản
    return n + sumToN(n - 1);       // Đệ quy: n + tổng từ 1 đến n-1
}

int main() {
    int n ;
    cin >> n;
    cout  << sumToN(n) << endl;
    return 0;
}

