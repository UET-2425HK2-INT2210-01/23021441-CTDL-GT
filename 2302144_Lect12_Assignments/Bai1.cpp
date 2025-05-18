#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> inDegree;

vector<int> topologicalSort(int n) {
    vector<int> result;
    queue<int> q;

    // Khởi tạo hàng đợi với các đỉnh có bậc vào bằng 0
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) { //Nếu một đỉnh không bị phụ thuộc bởi đỉnh nào khác (inDegree[i] == 0) đưa vào hàng đợi.
            q.push(i);
        }
    }

    while (!q.empty()) { //Lặp cho đến khi hàng đợi rỗng.
        int u = q.front(); //Lấy đỉnh đầu hàng đợi ra (u), và xóa nó khỏi hàng đợi.
        q.pop();
        result.push_back(u);//Thêm u vào danh sách kết quả (result) vì đây là một đỉnh được xử lý theo thứ tự topo.


        // Duyệt qua các đỉnh kề
        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return result;
}

int main() {
    ifstream infile("jobs.txt");
    ofstream outfile("jobs.out");

    int n, m;
    infile >> n >> m;

    adj.resize(n + 1);
    inDegree.resize(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        infile >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    vector<int> order = topologicalSort(n);

    for (int job : order) {
        outfile << job << " ";
    }

    infile.close();
    outfile.close();
    return 0;
}
