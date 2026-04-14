#include <bits/stdc++.h>
using namespace std;

const int LOG = 20; // enough for n ≤ 2e5

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> up(n + 1, vector<int>(LOG, -1));

    // input: parent of nodes
    for (int i = 2; i <= n; i++) {
        cin >> up[i][0];  // 2^0 = 1st parent
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j - 1] != -1)
                up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;

        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                x = up[x][j];
                if (x == -1) break;
            }
        }

        cout << x << '\n';
    }

    return 0;
}