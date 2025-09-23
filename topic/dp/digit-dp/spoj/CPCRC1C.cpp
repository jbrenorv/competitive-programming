/**
 * Problem: https://www.spoj.com/problems/CPCRC1C/
 * Topic: Digit DP
 */

#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[10][2][2][90];
string a, b;

int getDigit(int i, string num) {
    if (i >= num.size()) {
        return 0;
    }
    return (num[num.size() - i - 1] - '0');
}

int rec(int i, bool ca, bool cb, int currentSum, int &targetSum) {
    if (i < 0) {
        return (currentSum == targetSum);
    }

    if (dp[i][ca][cb][currentSum] != -1) {
        return dp[i][ca][cb][currentSum];
    }

    int result = 0;
    int da = getDigit(i, a);
    int db = getDigit(i, b);

    for (int d = 0; d <= 9; ++d) {
        bool new_ca = false;
        bool new_cb = false;

        if (ca) {
            if (d < da) continue;
            new_ca = (d == da);
        }

        if (cb) {
            if (d > db) continue;
            new_cb = (d == db);
        }

        int newSum = currentSum + d;

        result += rec(i - 1, new_ca, new_cb, newSum, targetSum);
    }

    return dp[i][ca][cb][currentSum] = result;
}

void solve() {
    do {
        cin >> a >> b;
        if (a[0] == '-') break;
        int ans = 0;
        for (int s = 1; s < 90; ++s) {
            memset(dp, -1, sizeof dp);
            ans += (s * rec(9, 1, 1, 0, s));
        }
        cout << ans << '\n';
    } while (true);
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
