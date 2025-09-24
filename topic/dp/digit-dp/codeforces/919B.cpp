/**
 * Problem: https://codeforces.com/contest/919/problem/B
 * Topic: Digit DP
 */

#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[20][11][2];
string num;

int getDigit(int i) {
    if (i >= num.size()) {
        return 0;
    }
    return (num[num.size() - i - 1] - '0');
}

int rec(int i, int sum, bool c) {
    if (i < 0) {
        return (sum == 10);
    }

    if (dp[i][sum][c] != -1) {
        return dp[i][sum][c];
    }

    int result = 0;
    int d = getDigit(i);
    
    for (int dig = 0; dig <= 9; ++dig) {
        if (sum + dig > 10) {
            break;
        }

        int new_sum = sum + dig;
        bool new_c = false;
        
        if (c) {
            if (dig > d) {
                continue;
            }
            new_c = (dig == d);
        }

        result += rec(i - 1, new_sum, new_c);
    }

    return dp[i][sum][c] = result;
}

void solve() {
    int k, l, r;
    cin >> k;
    
    l = 1;
    r = 1e9;
    
    while (l + 1 < r) {
        memset(dp, -1, sizeof dp);
        int m = (l + r) / 2;
        num = to_string(m);
        int cnt = rec(num.size() - 1, 0, 1);
        if (cnt >= k) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
