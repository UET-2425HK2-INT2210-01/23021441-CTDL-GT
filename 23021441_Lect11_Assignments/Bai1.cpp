
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;

// Cấu trúc để lưu cạnh đồ thị
struct Edge {
    int v; // đỉnh kề
    int d; // độ bẩn (trọng số cạnh)
};

// Cấu trúc cho priority queue
struct Node {
    int u;        // đỉnh hiện tại
    int dist;     // khoảng cách từ đỉnh bắt đầu đến đỉnh u

    // Ghi đè toán tử để sử dụng trong priority_queue
    bool operator>(const Node& other) const {
        return dist > other.dist; // khoảng cách nhỏ hơn sẽ được ưu tiên hơn
    }
};

// Phần a: Tìm đường đi từ s đến e với tổng độ bẩn nhỏ nhất
void dijkstra(int n, int s, int e, vector<vector<Edge>>& adj, ofstream& out) {
    vector<int> dist(n + 1, INF);  // Khoảng cách ngắn nhất đến mỗi đỉnh
    vector<int> prev(n + 1, -1);   // Lưu đường đi ngược lại
    priority_queue<Node, vector<Node>, greater<Node>> pq; // Hàng đợi ưu tiên

    dist[s] = 0;
    pq.push({s, 0});


    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int u = node.u;

        if (u == e) break; // Đã đến đỉnh e thì dừng
        if (node.dist > dist[u]) continue; // Nếu là đường không tối ưu thì bỏ qua

        for (Edge& edge : adj[u]) {
            int v = edge.v;
            int new_dist = dist[u] + edge.d;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                prev[v] = u; // Ghi lại đỉnh trước đó để truy vết đường đi
                pq.push({v, new_dist});
        }
    }
}


    // Ghi kết quả phần a
    out << dist[e] << endl;

    // Truy vết đường đi
    vector<int> path;
    for (int u = e; u != -1; u = prev[u]) {
        path.push_back(u);
    }
    for (int i = path.size() - 1; i >= 0; --i) {
        out << path[i];
        if (i > 0) out << " ";
    }
    out << endl;
}

// Phần b: Tìm đường đi ngắn nhất cho mọi cặp đỉnh
void floydWarshall(int n, vector<vector<int>>& dist, ofstream& out) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Ghi ma trận kết quả
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == INF) {
                out << "INF";
            } else {
                out << dist[i][j];
            }
            if (j < n) out << " ";
        }
        out << endl;
    }
}

int main() {
    ifstream in("dirty.txt");
    ofstream out("dirty.out");

    int n, m, s, e;
    in >> n >> m >> s >> e;

    vector<vector<Edge>> adj(n + 1);
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    // Khởi tạo khoảng cách từ mỗi đỉnh đến chính nó là 0
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }

    // Đọc dữ liệu đầu vào
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        in >> u >> v >> d;
        adj[u].push_back({v, d});
        dist[u][v] = min(dist[u][v], d); // Lưu cạnh ngắn nhất
    }

    // Phần a: Tìm đường đi từ s đến e
    dijkstra(n, s, e, adj, out);

    // Phần b: Tìm đường đi ngắn nhất cho mọi cặp đỉnh
    floydWarshall(n, dist, out);

    in.close();
    out.close();
    return 0;
}
