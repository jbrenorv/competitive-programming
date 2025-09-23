#include <bits/stdc++.h>
#define int long long
using namespace std;

int dist(pair<int,int> &p1, pair<int,int> &p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    vector<int> mxr(n);
    unordered_map<int,unordered_map<int,int>> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        if (i > 0) {
            d[i][i-1] = dist(a[i-1], a[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            mxr[i] = d[i+1][i] - 1;
        } else if (i == n - 1) {
            mxr[i] = d[i][i-1] - 1;
        } else {
            mxr[i] = min(d[i][i-1], d[i+1][i]) - 1;
        }
    }
    int l = 1, r = mxr[0], ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        int prev = m;
        bool ok = true;
        for (int i = 1; i < n && ok; ++i) {
            int cur = d[i][i-1] - prev;
            if (cur < 1) {
                ok = false;
                if (i % 2 == 0) l = m + 1;
                else r = m - 1;
            } else if (cur > mxr[i]) {
                ok = false;
                if (i % 2 == 0) r = m - 1;
                else l = m + 1;
            } else {
                prev = cur;
            }
        }
        if (ok) {
            l = m + 1;
            if (ans == -1) ans = m;
            else ans = max(ans, m);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
