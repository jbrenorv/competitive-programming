#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, alice = 0, bob = 0;
    cin >> n;
    map<int,int> freq;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++freq[x];
    }

    bool aliceTurn = true;
    auto consume = [&](int x, int f) -> void {
        alice += (x / 2) * f;
        bob += (x / 2) * f;
        if (x & 1) {
            if (aliceTurn) {
                alice += f;
            } else {
                bob += f;
            }
            aliceTurn = !aliceTurn;
        }
    };

    vector<pair<int,int>> a;
    for (auto &[x, f] : freq) {
        a.push_back({f, x});
    }

    sort(a.rbegin(), a.rend());

    for (auto &[x, f] : freq) {
        consume(x, f);
    }

    cout << alice << ' ' << bob << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
