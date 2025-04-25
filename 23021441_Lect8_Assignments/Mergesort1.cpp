#include <iostream>
using namespace std;

// Hàm trộn hai mảng con đã sắp xếp
void merge(double arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Kích thước mảng con trái
    int n2 = right - mid;    // Kích thước mảng con phải

    // Tạo mảng tạm để chứa hai nửa
    double* L = new double[n1];
    double* R = new double[n2];

    // Sao chép dữ liệu vào mảng tạm
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left; // Khởi tạo chỉ số cho các mảng

    // Trộn hai mảng con lại với nhau
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L[] (nếu có)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của R[] (nếu có)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Giải phóng bộ nhớ
    delete[] L;
    delete[] R;
}

// Hàm sắp xếp chính
void mergeSort(double arr[], int left, int right) {
    if (left < right) { // Điều kiện dừng đệ quy
        int mid = left + (right - left) / 2; // Tìm điểm giữa

        // Sắp xếp nửa đầu và nửa sau
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Trộn hai nửa đã sắp xếp
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    double* numbers = new double[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    mergeSort(numbers, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }

    delete[] numbers;
    return 0;
}
