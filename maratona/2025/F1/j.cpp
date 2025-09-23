#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    set<int> st;
    for (int i = 0; i < 10; ++i) {
        int x;
        cin >> x;
        st.insert(x);
    }
    cout << (4 - st.size()) << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
