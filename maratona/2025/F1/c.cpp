#include <bits/stdc++.h>
#define int long long
using namespace std;

void mul(vector<int> &c) {
    int n = c.size();
    vector<int> original(c);
    c.push_back(0);
    for (int i = 1; i < n; ++i) {
        if (original[i - 1] == 1) ++c[i];
        if (c[i] >= 2) c[i] = 0;
    }
}

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> c(n + 1);
    for (int i = 0; i <= n; ++i) cin >> c[i];
    while (c.size() != 1) {
        ++ans;
        if (c.back() == 1) mul(c);
        else c.pop_back();
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
