#include <iostream>
using namespace std;

// Hàm hoán đổi
void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

// Hàm phân hoạch Hoare
int partitionHoare(double arr[], int low, int high) {
    double pivot = arr[(low + high) / 2]; // Chọn pivot ở giữa
    int i = low - 1; // Chỉ số bên trái
    int j = high + 1; // Chỉ số bên phải

    while (true) {
        // Tìm phần tử bên trái >= pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // Tìm phần tử bên phải <= pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // Nếu hai chỉ số gặp nhau
        if (i >= j) {
            return j; // Trả về vị trí phân chia
        }

        // Hoán đổi hai phần tử
        swap(arr[i], arr[j]);
    }
}

// Hàm sắp xếp chính
void quickSortHoare(double arr[], int low, int high) {
    if (low < high) {
        // pi là vị trí phân hoạch
        int pi = partitionHoare(arr, low, high);

        // Đệ quy sắp xếp hai phần
        quickSortHoare(arr, low, pi);
        quickSortHoare(arr, pi + 1, high);
    }
}
int main() {
    int n;
    cin >> n;
    double* numbers = new double[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    quickSortHoare(numbers, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }

    delete[] numbers;
    return 0;
}
