#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 20;

vector<int> SOSDP(vector<int> &a) {
    vector<int> f(1 << N);
    for(int i = 0; i<(1<<N); ++i)
	    f[i] = a[i];
    for(int i = 0;i < N; ++i)
        for(int mask = 0; mask < (1<<N); ++mask)
            if(mask & (1<<i))
                f[mask] += f[mask^(1<<i)];
    return f;
}

void comb(vector<int> &a) {
    for (int i = 0; i < (1 << N); i++)
        a[i] = (a[i] * (a[i] - 1) * (a[i] - 2)) / 6;
}

void SOSDP_inv(vector<int> &a) {
    for (int i = N - 1; i >= 0; i--)
        for (int j = (1 << N) - 1; j >= 0; j--)
            if ((j >> i) & 1)
                a[j] -= a[j - (1 << i)];
}

void solve() {
    int n, k, m;
    cin >> n >> k;
    string s;
    vector<int> a(1 << N);
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int x = stoi(s, nullptr, 2);
        ++a[x];
    }
    vector<int> f = SOSDP(a);
    comb(f);
    SOSDP_inv(f);
    cin >> m;
    while (m--) {
        cin >> s;
        cout << f[stoi(s, nullptr, 2)] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
