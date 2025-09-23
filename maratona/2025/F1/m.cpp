#include <bits/stdc++.h>
#define int long long
#define MAXN 100010
#define INF (int)1e17
using namespace std;

int t[4 * MAXN];
int lazy[4 * MAXN];

void build(int v, int tl, int tr, vector<int> &a) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm, a);
        build(v*2+1, tm + 1, tr, a);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int inc) {
    if (l > r) return;
    if (l == tl && tr == r) {
        t[v] += inc;
        lazy[v] += inc;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), inc);
        update(v*2+1, tm + 1, tr, max(l, tm+1), r, inc);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return -INF;
    if (l == tl && tr == r) return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm + 1, tr, max(l, tm+1), r));
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    build(1, 0, n-1, a);
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        int l = max(0LL, i - k);
        int r = i - 1;
        update(1, 0, n - 1, i, i, k);
        update(1, 0, n - 1, l, r, -1);
        ans = max(ans, query(1, 0, n - 1, 0, n - 1));
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
