#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
int inv(int a) {
    return a <= 1 ? a : MOD - (MOD/a) * inv(MOD % a) % MOD;
}
int mod(int a) {
    return ((a % MOD) + MOD) % MOD;
}

vector<int> l(3), r(3), tot(3), totInv(3);
vector<vector<int>> zeroXOR{{0, 0, 0}, {0, 1, 1}, {1, 0, 1}, {1, 1, 0}};

int count(int i, int x) {
    int q = x / (1 << i);
    int r = x % (1 << i);
    if (q & 1) {
        return (q / 2) * (1 << i) + r + 1;
    }
    return (q / 2) * (1 << i);
}

int count(int i, int l, int r) {
    return count(i, r) - count(i, l - 1);
}

int probZeroXOR(int i) {
    int p = 0;
    for (vector<int> triple : zeroXOR) {
        int q = 1;
        for (int k = 0; k < 3; ++k) {
            int c = count(i, l[k], r[k]);
            if (triple[k] == 0) {
                c = tot[k] - c;
            }
            q = (((q * c) % MOD) * totInv[k]) % MOD;
        }
        p = (p + q) % MOD;
    }
    return p;
}

void solve() {
    for (int i = 0; i < 3; ++i) {
        cin >> l[i] >> r[i];
        tot[i] = r[i] - l[i] + 1;
        totInv[i] = inv(tot[i]);
    }
    int ans = 1;
    for (int i = 0; i < 30; ++i) {
        int p = probZeroXOR(i);
        cout << p << ' ';
        ans = (ans * p) % MOD;
    }
    cout << mod(1 - ans) << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    // solve();

    for (int n = 1; n <= 100; ++n) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                for (int k = j+1; k <= n; ++k) {
                    if ((i ^ j ^ k) == 0) {
                        ++cnt;
                    }
                }
            }
        }
        cout << (/*(n * n * n) - */(6 * cnt)) << '\n';
    }

    cout << '\n';

    return 0;
}
