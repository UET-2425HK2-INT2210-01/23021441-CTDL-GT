// Phuong phap vong lap
#include <iostream>
using namespace std;

double N(int n) {
    double result = 1;
    if (n < 0) {
        for (int i = 0; i < -n; ++i) {
            result *= 2;
        }
        return 1 / result;
    } else {
        for (int i = 0; i < n; ++i) {
            result *= 2;
        }
        return result;
    }
}
int main() {
    int n;
    cin >> n;
    cout << N(n) << endl;
    return 0;
}
/* Giai code:
Hàm N(n)
    Định nghĩa hàm N khởi tạo giá trị ban đầu result = 1
    Xét các trường hợp nếu: n < 0 ==> hàm sẽ tính `2^(-n)` bằng cách nhân `result` với 2(n lần )
                                  Sau đó, hàm trả về nghịch đảo của `result` (tức là `1 / result`)

                            n > 0 ==> hàm sẽ tính `2^n` bằng cách nhân `result` với 2(n lần)
                                  Sau đó, hàm trả về `result`.

                            n = 0 ==> hàm  sẽ trả về result = 1( Do khởi tạo result =1)
Hàm main():
    Đọc giá trị n
    Gọi hàm N(n) và in kết quả
    Độ phức tạp: O(n)
*/
// Phương pháp đệ quy
#include <iostream>
using namespace std;

double N(int n) {
    if (n == 0) return 1;
    if (n > 0) return 2 * N(n - 1);
    return 1.0 / N(-n);
}

int main() {
    int n;
    cin >> n;
    cout << N(n) << endl;
    return 0;
}
/* Giải code:
Hàm N(n):
 tính giá trị của một số nguyên n theo các quy tắc sau:
- Nếu n = 0, trả về 1.
- Nếu n > 0, trả về 2 nhân với kết quả của N(n - 1).
- Nếu n < 0, trả về 1 chia cho kết quả của `N(-n).
Hàm main():
    Đọc giá trị n
    Gọi hàm N(n) và in kết quả
    Độ phức tạp: O(n)


