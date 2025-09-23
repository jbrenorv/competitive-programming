#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(2 * n + 1);
    p[2 * n] = n;
    p[n] = n;
    for (int i = (2 * n - 1), j = n - 1; i > n; --i, --j) {
        p[i] = j;
        p[i - 2 * j] = j;
    }
    for (int i = 1; i <= 2 * n; ++i)
        cout << p[i] << " \n"[i == 2 * n];
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
