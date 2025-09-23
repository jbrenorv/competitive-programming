#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    
    int i = 0, j;
    while (i < n) {
        j = i + 1;

        while (j < n && s[j] != s[j - 1]) ++j;

        int len = j - i;
        if (s[j - 1] == '1' && len % 4 == 3) {
            cout << "NO\n";
            return;
        }
        
        i = j;
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
