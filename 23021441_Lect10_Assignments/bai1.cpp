#include<iostream>
#include<vector>
using namespace std;

void DFS(int u, vector<vector<int>>& adj, vector<bool>& visited){
    visited[u] = true; // Đánh dấu đỉnh u đã được thăm
    for (int v : adj[u]){ // Duyệt các đỉnh kề với u
        if(!visited[v]){ // Nếu đỉnh v chưa được thăm
            DFS(v, adj, visited); // Gọi đệ quy DFS với v
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
        vector<vector<int>> adj(n + 1);
    // Xây dựng danh sách kề
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);  // Đối với đồ thị vô hướng
    }

    vector<bool> visited(n + 1, false);
    int components = 0;

    // Đếm các thành phần được kết nối
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i, adj, visited);
            components++;
        }
    }

    cout << components << endl;
    return 0;
}


