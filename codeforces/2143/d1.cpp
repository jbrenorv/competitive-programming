#include <bits/stdc++.h>
// #define int long long
#define MAXN 2001
#define MOD 1000000007

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), iss(n, 1), tot(n, 1);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        // ordered_set os;
        // int g = 0;
        // int d = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (a[j] <= a[i]) {
                iss[i] += iss[j];
                // iss[i] = (iss[i] + iss[j]) % MOD;
                // ans = (ans + tot[j]) % MOD;
                // tot[i] = (tot[i] + tot[j] + (iss[j] * k)) % MOD;
                tot[i] += tot[j];
            } else {
                // int k = 0; //os.order_of_key({a[j] + 1, 0});
                // tot[i] += (iss[j] * (k + 1));
                tot[i] += iss[j];
                // ++g;
                // ans = (ans + iss[j]);
                // d += iss[j];
            }
            // ans += tot[j];
            // os.insert({a[j], j});
        }
        // d += iss[i];
        // cout << i << ": " << tot[i] << '\n';
        // ans = (ans + iss[i]) % MOD;
        ans += tot[i];
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
