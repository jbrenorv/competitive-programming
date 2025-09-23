#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k, s = 0;
    cin >> n >> k;
    vector<int> a(n), b(k);
    for (int i = 0; i < n; ++i) { cin >> a[i]; s += a[i]; }
    for (int i = 0; i < k; ++i) cin >> b[i];
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    while (i < n && j < k) {
        if (i + b[j] - 1 < n) {
            s -= a[i + b[j] - 1];
        }
        i += b[j];
        ++j;
    }
    cout << s << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
