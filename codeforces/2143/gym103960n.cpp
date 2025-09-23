#include <bits/stdc++.h>
#define int long long
using namespace std;

struct LSum {
    LSum(int _l) : l(_l), sum(0) {}
    void add(int x) {
        if (a.size() < l) {
            sum += x;
            a.insert(x);
        } else if (x > *a.begin()) {
            int y = *a.begin();
            sum += (x - y);
            a.insert(x);
            a.extract(y);
            b.insert(y);
        } else {
            b.insert(x);
        }
    }
    void remove(int x) {
        if (x >= *a.begin()) {
            sum -= x;
            a.extract(x);
            if (!b.empty()) {
                int y = *b.rbegin();
                sum += y;
                a.insert(y);
                b.extract(y);
            }
        } else {
            b.extract(x);
        }
    }
    int getSum() {
        return sum;
    }
private:
    int l, sum;
    multiset<int> a, b;
};

void solve() {
    int n, k, l;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    cin >> k >> l;

    int sum = 0;
    LSum ls(l);
    for (int i = 0; i < k; ++i) {
        sum += a[i];
        ls.add(b[i]);
    }

    int ans = sum + ls.getSum();
    for (int i = 1; i <= k; ++i) {
        sum -= a[k - i];
        ls.remove(b[k - i]);

        sum += a[n - i];
        ls.add(b[n - i]);

        ans = max(ans, sum + ls.getSum());
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
