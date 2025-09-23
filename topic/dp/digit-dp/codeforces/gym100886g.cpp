/**
 * Problem: https://codeforces.com/gym/100886/problem/G
 * Topic: Digit DP
 */

#include <bits/stdc++.h>
#define int long long
using namespace std;

string a, b;

int getDigit(int i, string num) {
    if (i >= num.size()) {
        return 0;
    }
    return (num[num.size() - i - 1] - '0');
}

int getProduct(int num) {
    int product = 1;
    do {
        product *= (num % 10);
        num /= 10;
    } while (num > 0);
    return product;
}

pair<int,int> rec(int i, bool cl, bool cr, int currentNumber) {
    if (i < 0) {
        return pair<int,int>(getProduct(currentNumber), currentNumber);
    }

    if (!cr) {
        int newNumber = (currentNumber * 10 + 9);
        return rec(i - 1, 0, 0, newNumber);
    }

    pair<int,int> result(-1, -1);
    int dl = getDigit(i, a);
    int dr = getDigit(i, b);

    for (int d = max(0LL, dr - 1); d <= dr; ++d) {
        bool new_cr = (d == dr);
        bool new_cl = false;

        if (cl) {
            if (d < dl) continue;
            new_cl = (d == dl);
        }

        int newNumber = (currentNumber * 10 + d);

        result = max(result, rec(i - 1, new_cl, new_cr, newNumber));
    }

    return result;
}

void solve() {
    cin >> a >> b;
    cout << rec(19, 1, 1, 0).second << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
