#include <iostream>
using namespace std;

// Hàm hoán đổi
void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

// Hàm phân hoạch Lomuto
int partitionLomuto(double arr[], int low, int high) {
    double pivot = arr[high]; // Chọn pivot là phần tử cuối
    int i = low - 1; // i là chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            i++; // Tăng chỉ số của phần tử nhỏ hơn
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1; // Trả về vị trí pivot
}

// Hàm sắp xếp chính
void quickSortLomuto(double arr[], int low, int high) {
    if (low < high) {
        // pi là chỉ số nơi pivot đã đúng vị trí
        int pi = partitionLomuto(arr, low, high);

        // Đệ quy sắp xếp hai phần
        quickSortLomuto(arr, low, pi - 1);
        quickSortLomuto(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    double* numbers = new double[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    quickSortLomuto(numbers, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }

    delete[] numbers;
    return 0;
}
