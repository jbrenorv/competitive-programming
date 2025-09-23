#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, q, k, f;
vector<string> kb;
unordered_map<string, tuple<int,int,int>> dict;
unordered_map<string, vector<int>> pos;

vector<string> getCandidates(vector<string> &query) {
    vector<string> candidates;
    vector<int> prev = pos[query.back()];
    for (int i = 0; i < k; ++i) {
        vector<int> cur;
        for (int j : prev)
            if (j - i >= 0 && kb[j - i] == query[f - i - 1])
                cur.push_back(j);
        if (cur.empty()) break;
        prev = cur;
    }
    for (int i : prev)
        if (i + 1 < m)
            candidates.push_back(kb[i + 1]);
    return candidates;
}

string predict(vector<string> &query) {
    vector<string> candidates = getCandidates(query);
    if (candidates.empty()) return "*";
    string res;
    int hs = 0, hso = INT32_MAX;
    for (auto &[d, info] : dict) {
        int s = 0;
        auto [ord, x, y] = info;
        for (string c : candidates) {
            int cx = 0, cy = 0;
            if (dict.count(c)) {
                cx = get<1>(dict[c]);
                cy = get<2>(dict[c]);
            }
            s += (x * cx + y * cy);
        }
        if (s > hs || (s == hs && ord < hso)) {
            res = d;
            hs = s;
            hso = ord;
        }
    }
    return res;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string w;
        int x, y;
        cin >> w >> x >> y;
        dict[w] = {i, x, y};
    }
    cin >> m;
    kb.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> kb[i];
        pos[kb[i]].push_back(i);
    }
    cin >> q >> k;
    while (q--) {
        cin >> f;
        vector<string> query(f);
        for (int i = 0; i < f; ++i) {
            cin >> query[i];
            cout << query[i] << ' ';
        }
        cout << predict(query) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
