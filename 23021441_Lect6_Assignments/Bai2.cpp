#include <iostream>
using namespace std;

class Heap {
private:
    int* arr;         // Mảng động lưu các phần tử
    int capacity;     // Sức chứa tối đa
    int size;         // Số phần tử hiện có
    bool isMinHeap;   // Loại heap (true: min, false: max)

    // Hàm so sánh tùy loại heap
    bool compare(int a, int b) {
        return isMinHeap ? (a < b) : (a > b);// Nếu là min-heap thì so sánh a < b, ngược lại a > b
    }

    // Đẩy phần tử lên đúng vị trí
void heapifyUp(int index) {
    while (index > 0) {                     // Lặp khi chưa đến gốc
        int parent = (index - 1) / 2;       // Tính chỉ số của nút cha
        if (compare(arr[index], arr[parent])) { // Nếu vi phạm tính chất heap
            swap(arr[index], arr[parent]);  // Đổi chỗ với nút cha
            index = parent;                 // Tiếp tục kiểm tra từ vị trí cha
        } else {
            break;                         // Nếu đúng tính chất thì dừng
        }
    }
}

    // Đẩy phần tử xuống đúng vị trí
    void heapifyDown(int index) {
    while (true) {                          // Vòng lặp vô hạn (sẽ break khi cần)
        int left = 2 * index + 1;           // Chỉ số con trái
        int right = 2 * index + 2;          // Chỉ số con phải
        int chosen = index;                 // Giả sử nút hiện tại đúng vị trí

        // So sánh với con trái
        if (left < size && compare(arr[left], arr[chosen])) {
            chosen = left;
        }
        // So sánh với con phải
        if (right < size && compare(arr[right], arr[chosen])) {
            chosen = right;
        }

        if (chosen != index) {             // Nếu cần đổi chỗ
            swap(arr[index], arr[chosen]); // Thực hiện đổi chỗ
            index = chosen;                // Tiếp tục kiểm tra từ vị trí mới
        } else {
            break;                         // Nếu đúng vị trí thì dừng
        }
    }
}

public:
    // Constructor
    Heap(bool isMin, int cap = 100) {          // Constructor
        capacity = cap;                        // Gán sức chứa
        arr = new int[capacity];               // Cấp phát mảng động
        size = 0;                              // Khởi tạo size = 0
        isMinHeap = isMin;                     // Gán loại heap
}

    ~Heap() {                                  // Destructor
        delete[] arr;                          // Giải phóng bộ nhớ
}

    // Chèn phần tử mới
    void insert(int value) {
        if (size >= capacity) {                // Kiểm tra heap đầy
            cout << "Heap da day!\n";
            return;
        }
        arr[size] = value;                     // Thêm vào cuối mảng
        heapifyUp(size);                       // Đẩy lên để đảm bảo tính chất heap
        size++;                                // Tăng số phần tử
}
    // Xóa phần tử (xóa root)
    void removeValue(int value) {
        int index = -1;                        // Khởi tạo chỉ số không tìm thấy
        for (int i = 0; i < size; i++) {       // Duyệt toàn bộ heap
        if (arr[i] == value) {             // Nếu tìm thấy giá trị
            index = i;                     // Lưu lại vị trí
            break;
        }
    }
    if (index == -1) return;               // Không tìm thấy thì thoát

    arr[index] = arr[size - 1];            // Thay thế bằng phần tử cuối
    size--;                                // Giảm số phần tử
    heapifyUp(index);                      // Đẩy lên
    heapifyDown(index);                    // Đẩy xuống
}

    // In heap
    void print(string title) {
    cout << title << ": ";                  // In tiêu đề
    for (int i = 0; i < size; i++) {       // Duyệt các phần tử
        cout << arr[i] << " ";             // In giá trị
    }
    cout << endl;                          // Xuống dòng
}
};

int main() {
    // Tạo max-heap (isMinHeap = false)
    Heap maxHeap(false);

    // Chèn các giá trị ban đầu
    int initValues[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int val : initValues) {
        maxHeap.insert(val);
    }
    maxHeap.print("Max Heap ban dau");

    // Chèn thêm các giá trị
    int addValues[] = {14, 0, 35};
    for (int val : addValues) {
        maxHeap.insert(val);
    }
    maxHeap.print("Max Heap sau khi chen");

    // Xóa các giá trị
    int delValues[] = {6, 13, 35};
    for (int val : delValues) {
        maxHeap.removeValue(val);
    }
    maxHeap.print("Max Heap sau khi xoa");

    return 0;
}
