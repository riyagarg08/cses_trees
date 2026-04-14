#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

const int LOG = 20;

vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> depth;

void dfs(int node, int parent) {
   
    for (int child : adj[node]) {
        if (child != parent) {
            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    }
}

int lift(int node, int k) {
    for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) {
            node = up[node][j];
            if (node == -1) break;
        }
    }
    return node;
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    // same level
    u = lift(u, depth[u] - depth[v]);

    if (u == v) return u;

    // jump both
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[u][j] != -1 && up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
}

int main() {
    int n, q;
    cin >> n >> q;

    adj.resize(n + 1);
    up.assign(n + 1, vector<int>(LOG, -1));
    depth.assign(n + 1,0);

    for (int i = 2; i <= n ; i++) {
        int u;
        cin >> u;
        up[i][0] = u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }

    dfs(1, -1); // root = 1
   for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j - 1] != -1)
                up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
    return 0;
}