#include <iostream>
#include <vector>
using namespace std;

bool hasSubsetSum(vector<int>& nums, int target) {
    // Khởi tạo mảng DP 1 chiều
    vector<bool> dp(target + 1, false);

    //  Tổng 0 luôn đạt được (không chọn phần tử nào)
    dp[0] = true;

    //  Duyệt qua từng số trong mảng
    for (int num : nums) {
        //  Duyệt ngược từ target về num
        for (int j = target; j >= num; j--) {
            //  Cập nhật dp[j]: có thể tạo tổng j bằng cách:
            // - Không chọn num (giữ nguyên dp[j])
            // - Chọn num (kiểm tra dp[j - num])
            dp[j] = dp[j] || dp[j - num];
        }
    }

    // Kết quả cuối cùng
    return dp[target];
}

int main() {
    int n, X;
    cin >> n >> X;

    vector<int> ages(n);
    for (int i = 0; i < n; ++i) {
        cin >> ages[i];
    }

    cout << (hasSubsetSum(ages, X) ? "YES" : "NO");
    return 0;
}
