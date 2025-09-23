#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if ((s[0] == '0' && s[1] == '1') || (s[n-2] == '1' && s[n-1] == '0')) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i < n-1; ++i) {
        if (s[i-1] == '1' && s[i] == '0' && s[i+1] == '1') {
            cout << "NO\n";
            return;
        }
    }
    vector<int> p(n);
    int i = 0, j;
    while (i < n) {
        j = i + 1;
        if (s[i] == '1') {
            p[i] = j;
            i = j;
            continue;
        }
        while (j < n && s[j] == '0') ++j;
        for (int k = i; k < j; ++k) {
            p[k] = j - (k - i);
        }
        i = j;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << p[i] << " \n"[i == n-1];
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
