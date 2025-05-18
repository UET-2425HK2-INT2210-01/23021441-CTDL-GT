#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc dữ liệu cạnh
struct Edge {
    int u, v, d; // d: trọng số cạnh giữa u và v

    // Toán tử < dùng cho sort() để sắp xếp theo trọng số tăng dần
    bool operator<(const Edge& other) const {
        return d < other.d;
    }
};

vector<int> parent; // Mảng đại diện cho DSU (Disjoint Set Union)

// Hàm tìm gốc của tập chứa u (có path compression)
int findSet(int u) {
    if (parent[u] == u) return u;
    return parent[u] = findSet(parent[u]); // Gán luôn gốc khi tìm được
}

// Hàm hợp nhất hai tập hợp chứa u và v (nếu khác nhau)
bool unionSet(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if (u == v) return false; // Cùng một tập thì không nối nữa (tránh tạo chu trình)
    parent[v] = u; // Hợp nhất: gán gốc v về gốc u
    return true;
}

int main() {
    ifstream infile("connection.txt");     // Mở file đầu vào
    ofstream outfile("connection.out");    // Mở file đầu ra

    int n, m; // n: số đỉnh, m: số cạnh
    infile >> n >> m;

    vector<Edge> edges(m); // Danh sách cạnh
    for (int i = 0; i < m; ++i) {
        infile >> edges[i].u >> edges[i].v >> edges[i].d; // Đọc thông tin từng cạnh
    }

    // Sắp xếp các cạnh theo trọng số tăng dần (cho Kruskal)
    sort(edges.begin(), edges.end());

    // Khởi tạo DSU: mỗi đỉnh là một tập riêng biệt
    parent.resize(n + 1); // Đánh chỉ số từ 1 đến n
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    int totalCost = 0;          // Tổng chi phí của cây khung nhỏ nhất
    vector<Edge> result;        // Danh sách các cạnh trong cây khung nhỏ nhất

    // Duyệt qua các cạnh đã sắp xếp
    for (const Edge& e : edges) {
        if (unionSet(e.u, e.v)) {         // Nếu nối được hai đỉnh chưa cùng tập
            totalCost += e.d;             // Cộng trọng số vào tổng chi phí
            result.push_back(e);          // Thêm cạnh vào kết quả
        }
    }

    outfile << totalCost << endl;
    for (const Edge& e : result) {
        outfile << e.u << " " << e.v << " " << e.d << endl;

    infile.close();
    outfile.close();
    return 0;
}
}

