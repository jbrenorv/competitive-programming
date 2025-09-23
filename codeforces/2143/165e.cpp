#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 22;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), rep(1 << K, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        rep[a[i]] = a[i];
    }
    for (int mask = 0; mask < (1 << K); ++mask) {
        if (rep[mask] != -1) continue;
        for (int i = 0; i < K; ++i) {
            if ((mask & (1 << i)) && (rep[mask ^ (1 << i)] != -1)) {
                rep[mask] = rep[mask ^ (1 << i)];
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << rep[(~a[i] & ((1 << K) - 1))] << " \n"[i == n - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
