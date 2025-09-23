#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

struct mod {
    mod() { _value = 0; }
    mod(int value) { _value = ((value + MOD) % MOD); }
    mod(int p, int q) { _value = ((p % MOD) * inv(q)) % MOD; }
    int get() { return _value; }
    mod operator*(int value) { return mod(_value * value); }
    mod operator*(mod other) { return mod(_value * other.get()); }
    mod operator+(mod other) { return mod(_value + other.get()); }
    mod operator-(mod other) { return mod(_value - other.get()); }
private:
    int _value;
    int inv(int a) {
        return a <= 1 ? a : MOD - (MOD/a) * inv(MOD % a) % MOD;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> c(q);
    vector<vector<int>> idx(n, vector<int>());
    for (int i = 0; i < q; ++i) {
        cin >> c[i];
        idx[c[i] - 1].push_back(i);
    }
    vector<int> p2(q);
    p2[0] = 1;
    for (int i = 1; i < q; ++i) {
        p2[i] = (2 * p2[i - 1]) % MOD;
    }
    vector<mod> prefix(q);
    for (int i = 0; i < q; ++i) {
        prefix[i] = mod(c[i], p2[i]);
        if (i > 0) {
            prefix[i] = prefix[i] + prefix[i - 1];
        }
    }
    auto suffix = [&](int j) {
        return prefix[q - 1] - prefix[j];
    };
    for (int i = 0; i < n; ++i) {
        mod e;
        if (i == 0) {
            e = mod(1, 2) * prefix[q - 1];
        }
        for (int index : idx[i]) {
            e = e + (mod(1, 2) * suffix(index) * p2[index]);
        }
        cout << e.get() << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
