#include <bits/stdc++.h>
#define int long long
using namespace std;

int getK(int l, int r) {
    for (int i = 29; i >= 0; --i) {
        if ((l & (1 << i)) != (r & (1 << i))) {
            return i;
        }
    }
    return -1;
}

int getT(int k, int r) {
    return r & (((1 << 30) - 1) ^ ((1 << k) - 1));
}

void solve(int l, int r, int L, vector<int> &a) {
    if (l >= r) {
        if (l == r) a[l - L] = l;
        return;
    }
    int t = getT(getK(l, r), r);
    int start = ((t - l <= r - t + 1) ? l : (t - (r - t + 1)));
    int end = ((t - l <= r - t + 1) ? (t + (t - l) - 1) : r);
    for (int i = start; i < t; ++i) {
        a[i - L] = end - (i - start);
        a[end - (i - start) - L] = i;
    }
    if (start == l) solve(end + 1, r, L, a);
    else solve(l, start - 1, L, a);
}

void solve() {
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vector<int> a(n);
    solve(l, r, l, a);
    int c = 0;
    for (int i = l; i <= r; ++i) c += (a[i - l] | i);
    cout << c << '\n';
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n-1];
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
