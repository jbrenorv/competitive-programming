#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

struct SegmentTree {
    SegmentTree(int _n) : n(_n) {
        t.assign(4 * n, 0);
    }
    int sum(int l, int r) {
        return sum(1, 0, n - 1, l, r);
    }
    void update(int pos, int new_val) {
        update(1, 0, n - 1, pos, new_val);
    }
private:
    int n;
    vector<int> t;
    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return t[v];
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<int> p2(n + 1);
    p2[0] = 1;
    for (int i = 1; i <= n; ++i) p2[i] = (2 * p2[i - 1]) % MOD;
    sort(a.begin(), a.end(), greater<pair<int,int>>());
    int ans = 1;
    SegmentTree st(n);
    for (int i = 0; i < n; ++i) {
        auto [x, j] = a[i];
        int k = st.sum(0, j - 1);
        int m = j - k;
        int diff = (p2[m] * (k + 1));
        cout << j << ": " << diff << '\n';
        ans = (ans + diff) % MOD;
        st.update(j, 1);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
