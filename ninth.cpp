#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<stack>
using namespace std;

const int LOG = 20;
const int SZ = 2e5+1;
int up[SZ][LOG];
int depth[SZ];
int cnt[SZ],ans[SZ];
vector<int> adj[SZ];

void dfs(int root) {
    stack<pair<int,int>> st;
    st.push({root, -1});

    while (!st.empty()) {
        auto [node, parent] = st.top();
        st.pop();

        up[node][0] = parent;

        for (int child : adj[node]) {
            if (child != parent) {
                depth[child] = depth[node] + 1;
                st.push({child, node});
            }
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
void f(int node,int parent){
    for(int child:adj[node]){
        if(child!=parent){
            f(child,node);
            cnt[node]+=cnt[child];
        }
    }
    ans[node]=cnt[node];
}
int main() {
    int n, q;
    cin >> n >> q;

  

    for (int i = 2; i <= n ; i++) {
        int u,v;
        cin >> u >> v;
       
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1); // root = 1
   for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j - 1] != -1)
                up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
        int LCA = lca(u, v);
        cnt[LCA]--;
            if (up[LCA][0] != -1)
                cnt[up[LCA][0]]--;
    }
    f(1,-1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}