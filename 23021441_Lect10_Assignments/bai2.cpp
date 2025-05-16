#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(int start, int target, vector<vector<int>>& adj, int n) {
    //Khởi tạo dữ liệu hỗ trợ duyệt BFS
    vector<bool> visited(n + 1, false); // Đánh dấu đỉnh đã thăm (false là chưa thăm)
    vector<int> distance(n + 1, -1);    // Lưu khoảng cách từ 'start' đến mỗi đỉnh (khởi tạo -1 là chưa thể đến)
    queue<int> q;                       // Hàng đợi để duyệt BFS

    //Bắt đầu duyệt từ đỉnh start
    q.push(start);          // Đưa đỉnh bắt đầu vào hàng đợi
    visited[start] = true;  // Đánh dấu đã thăm đỉnh start
    distance[start] = 0;    // Khoảng cách từ start đến chính nó là 0

    // Bắt đầu vòng lặp BFS
    while (!q.empty()) {
    int current = q.front(); // Lấy đỉnh ở đầu hàng đợi
    q.pop();                 // Loại bỏ khỏi hàng đợi

        //Nếu đã đến đỉnh cần tìm, trả về khoảng cách
            if (current == target) {
            return distance[current]; // Đã đến target, trả về khoảng cách ngắn nhất
        }

        //Duyệt các đỉnh kề của đỉnh hiện tại
        for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                visited[neighbor] = true; // Đánh dấu đã thăm
                distance[neighbor] = distance[current] + 1; // Cập nhật khoảng cách
                q.push(neighbor);  // Đưa vào hàng đợi để tiếp tục duyệt
            }

        }
    }

    return -1;  // Nếu không tìm được target, trả về -1 (không có đường đi)
}

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    vector<vector<int>> adj(n + 1); // Sử dụng index từ 1 đến n

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Đồ thị có hướng
    }

    int result = BFS(X, Y, adj, n);
    cout << result << endl;

    return 0;
}
