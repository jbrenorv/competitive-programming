/**
 * Problem: https://codeforces.com/contest/628/problem/D
 * Topic: Digit DP
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXLEN = 2000;
const int MOD = 1e9 + 7;
int dp[MAXLEN][MAXLEN][2][2];
int r[MAXLEN];
int n, d, m;
vector<int> digit_d, digits_without_d;
string a, b;

int getDigit(int i, string num) {
    return (num[n - i - 1] - '0');
}

int getRemainder(int i, int dig) {
    return (dig * r[i]) % m;
}

int rec(int i, bool ca, bool cb, int remainder) {
    if (i < 0) {
        return (remainder == 0);
    }

    if (dp[i][remainder][ca][cb] != -1) {
        return dp[i][remainder][ca][cb];
    }

    int result = 0;
    int da = getDigit(i, a);
    int db = getDigit(i, b);

    vector<int> &digits = ((i % 2 == n % 2) ? digit_d : digits_without_d);

    for (int dig : digits) {
        bool new_ca = false;
        bool new_cb = false;

        if (ca) {
            if (dig < da) continue;
            new_ca = (dig == da);
        }

        if (cb) {
            if (dig > db) continue;
            new_cb = (dig == db);
        }

        int newRemainder = (remainder + getRemainder(i, dig)) % m;
        result = (result + rec(i - 1, new_ca, new_cb, newRemainder)) % MOD;
    }

    return dp[i][remainder][ca][cb] = result;
}

void init() {
    memset(dp, -1, sizeof dp);
    
    digit_d.push_back(d);
    for (int dig = 0; dig <= 9; ++dig) {
        if (dig != d) {
            digits_without_d.push_back(dig);
        }
    }
    
    r[0] = 1;
    for (int i = 1; i < MAXLEN; ++i) {
        r[i] = (r[i - 1] * 10) % m;
    }
}

void solve() {
    cin >> m >> d >> a >> b;
    n = a.length(); // a and b has the same length
    init();
    cout << rec(n - 1, 1, 1, 0) << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
