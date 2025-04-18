#include <iostream>
#include <fstream>

using namespace std;

void bubbleSort(double arr[], int n) {
    for (int i = 0; i < n-1; i++) {//chạy từ đầu mảng đến phần tử áp chót
        for (int j = 0; j < n-i-1; j++) {//chạy từ đầu mảng đến phần tử chưa được sắp xếp
            if (arr[j] > arr[j+1]) { //So sánh 2 phần tử liền kề
                //khối lệnh trong if thực hiện đổi chỗ 2 phần tử nếu chúng không đúng thứ tự
                double temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    ifstream in("numbers.txt");
    ofstream out("numbers.sorted");

    double numbers[1000]; // Giả sử tối đa 1000 số
    int count = 0;

    while (in >> numbers[count]) {
        count++;
    }

    bubbleSort(numbers, count);

    for (int i = 0; i < count; i++) {
        if (i != 0) out << " ";
        out << numbers[i];
    }

    return 0;
}
