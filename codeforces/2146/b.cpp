#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> sets(n, vector<int>());
    vector<int> freq(m + 1);
    for (int i = 0; i < n; ++i) {
        int x, len;
        cin >> len;
        for (int j = 0; j < len; ++j) {
            cin >> x;
            sets[i].push_back(x);
            ++freq[x];
        }
    }
    for (int x = 1; x <= m; ++x) {
        if (freq[x] == 0) {
            cout << "NO\n";
            return;
        }
    }
    int goodSets = 0;
    for (int i = 0; i < n; ++i) {
        bool isGood = true;
        for (int x : sets[i]) {
            if (freq[x] == 1) {
                isGood = false;
                break;
            }
        }
        if (isGood) ++goodSets;
    }
    cout << ((goodSets > 1) ? "YES\n" : "NO\n");
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
