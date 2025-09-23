#include <bits/stdc++.h>
using namespace std;

const int K = 6;
const int N = 21;
vector<int> SOS(1 << N, 0);
const vector<pair<int,int>> D {
    {1,1},{1,2},{1,3},{1,4},{1,5},{1,6},
    {2,2},{2,3},{2,4},{2,5},{2,6},
    {3,3},{3,4},{3,5},{3,6},
    {4,4},{4,5},{4,6},
    {5,5},{5,6},
    {6,6}
};


void initSOS() {
    vector<vector<int>> adj(K+1, vector<int>());
    vector<char> visited(K+1);
    vector<int> in(K+1);
    vector<int> s;
    for (int mask = 0; mask < (1 << N); ++mask) {
        for (int v = 1; v <= K; ++v) {
            adj[v].clear();
            visited[v] = 0;
            in[v] = 0;
        }
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                adj[D[i].first].push_back(D[i].second);
                adj[D[i].second].push_back(D[i].first);
                ++in[D[i].first];
                ++in[D[i].second];
            }
        }
        int cc = 0, oc = 0;
        for (int v = 1; v <= K; ++v) {
            oc += (in[v] & 1);
            if (in[v] > 0 && !visited[v]) {
                ++cc;
                s.push_back(v);
                visited[v] = 1;
                while (!s.empty()) {
                    int u = s.back();
                    s.pop_back();
                    for (int w : adj[u]) {
                        if (in[w] > 0 && !visited[w]) {
                            visited[w] = 1;
                            s.push_back(w);
                        }
                    }
                }
            }
        }
        SOS[mask] = (cc == 1 && oc <= 2);
    }
}

void SOSdp() {
    for (int i = 0; i < N; ++i)
        for (int mask = 0; mask < (1 << N); ++mask)
            if (mask & (1 << i))
                SOS[mask] += SOS[mask ^ (1 << i)];
}

void solve() {
    int n, mask = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b, pos;
        cin >> a >> b;
        for (int j = 0; j < N; ++j)
            if (D[j].first == a && D[j].second == b)
                pos = j;
        mask |= (1 << pos);
    }
    cout << SOS[mask] << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    initSOS();
    SOSdp();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
