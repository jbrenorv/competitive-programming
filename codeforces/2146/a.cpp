#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int,int> freq;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++freq[x];
    }
    int ans = -1;
    for (int k = 1; k <= n; ++k) {
        int cnt = 0;
        for (auto [x, f] : freq) {
            if (f >= k) {
                ++cnt;
            }
        }
        ans = max(ans, k * cnt);
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
