#include <iostream>
#include <fstream>

using namespace std;

void findMaxSubmatrix(int matrix[][100], int rows, int cols) {
    int maxSum = matrix[0][0]; // Khởi tạo bằng phần tử đầu tiên
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;

    for (int top = 0; top < rows; top++) {
        int temp[100] = {0}; // Mảng tạm lưu tổng các cột

        for (int bottom = top; bottom < rows; bottom++) { //Với mỗi hàng top, duyệt qua tất cả các hàng bottom từ top trở xuống Cộng dồn giá trị các cột vào mảng temp
            for (int col = 0; col < cols; col++) {
                temp[col] += matrix[bottom][col];
            }

            // Thuật toán Kadane 1D
            //Tìm dãy con có tổng lớn nhất trong mảng 1 chiều temp (đã cộng dồn theo cột)
            int currentSum = temp[0];
            int currentStart = 0;
            int bestSum = temp[0];
            int bestStart = 0, bestEnd = 0;

            for (int col = 1; col < cols; col++) {
                if (currentSum < 0) {  //Nếu currentSum âm, bắt đầu một dãy mới từ vị trí hiện tại
                    currentSum = temp[col];
                    currentStart = col;
                } else {
                    currentSum += temp[col];
                }

                if (currentSum > bestSum) { //Cập nhật bestSum khi tìm được tổng lớn hơn
                    bestSum = currentSum;
                    bestStart = currentStart;
                    bestEnd = col;
                }
            }
            //So sánh kết quả từ Kadane với maxSum hiện tại
            //Nếu tốt hơn thì cập nhật cả tổng và vị trí
            if (bestSum > maxSum) {
                maxSum = bestSum;
                r1 = top;
                c1 = bestStart;
                r2 = bottom;
                c2 = bestEnd;
            }
        }
    }

    // Xuất kết quả ra file
    ofstream out("matrix.out");
    out << r1+1 << " " << c1+1 << " " << r2+1 << " " << c2+1 << " " << maxSum;
}

int main() {
    ifstream in("matrix.txt");
    int rows, cols;
    in >> rows >> cols;

    int matrix[100][100]; // Giả sử kích thước tối đa 100x100
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            in >> matrix[i][j];
        }
    }

    findMaxSubmatrix(matrix, rows, cols);
    return 0;
}
