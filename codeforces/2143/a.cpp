#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    int x = 1, i = 0, j = n - 1;
    while (i < j) {
        if (x == p[i]) ++i;
        else if (x == p[j]) --j;
        else {
            cout << "NO\n";
            return;
        }
        ++x;
    }
    cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
