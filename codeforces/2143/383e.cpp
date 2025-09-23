#include <bits/stdc++.h>
using namespace std;

const int K = 24;

void solve() {
    int n;
    cin >> n;
    vector<int> sos(1 << K);
    for (int i = 0; i < n; ++i) {
        set<char> s;
        // set<char> masks;
        string word;
        cin >> word;
        for (char d : word) s.insert(d);
        for (char d : s) ++sos[(1 << (d - 'a'))];

        // for (int mask = 1; mask < (1 << K); ++mask) {
        //     if (mask & wordMask) {
        //         ++sos[mask];
        //     }
        // }

        // int wordMask = 0;
        // for (char d : word)
        //     wordMask |= (1 << (d - 'a'));

        // for (int mask = 1; mask < (1 << K); ++mask) {
        //     if (mask & wordMask) {
        //         ++sos[mask];
        //     }
        // }

        // for (int j = 1; j < 8; ++j) {
        //     int mask = 0;
        //     for (int k = 0; k < 3; ++k) {
        //         if (j & (1 << k)) {
        //             mask |= (1 << (word[k] - 'a'));
        //         }
        //     }
        //     // ++sos[mask];
        //     masks.insert(mask);
        // }
        // for (int mask : masks) ++sos[mask];
    }
    // long long ans = 0;
    for (int i = 0; i < K; ++i) {
        for (int mask = 0; mask < (1 << K); ++mask) {
        // if (__popcount(mask) <= 3) continue;
            if (mask & (1 << i)) {
                sos[mask] += sos[mask ^ (1 << i)];
            }
        }
        // ans ^= ((long long)sos[mask] * sos[mask]);
    }
    cout << sos[(1 << 0) | (1 << 1)] << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
