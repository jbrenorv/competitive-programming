#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> ts;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    ts.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ts.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

void solve() {
    cin >> n;
    adj.assign(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        --u, --v;
        if (x >= y) adj[u].push_back(v);
        else adj[v].push_back(u);
    }
    topological_sort();
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        p[ts[i]] = i + 1;
    for (int i = 0; i < n; ++i)
        cout << p[i] << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
