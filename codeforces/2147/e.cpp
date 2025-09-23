#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> zero {{0,0,0}, {0,1,1}, {1,0,1}, {1,1,0}};
const int M = 1e9 + 7;
int dp[30][2][2][2];
int LIM0, LIM1, LIM2;
int L[3], R[3];

int inv(int a) {
    return a <= 1 ? a : M - (M / a) * inv(M % a) % M;
}

int mod(int a) {
    if (a < 0) {
        return (((a % M) + M) % M);
    }
    return a % M;
}

int rec(int i, bool t0, bool t1, bool t2) {
    if (i < 0) return 1;

    if (dp[i][t0][t1][t2] != -1) {
        return dp[i][t0][t1][t2];
    }

    int result = 0;

    int d0 = bool(LIM0 & (1 << i));
    int d1 = bool(LIM1 & (1 << i));
    int d2 = bool(LIM2 & (1 << i));

    for (vector<int> comb : zero) {
        int comb_d0 = comb[0];
        int comb_d1 = comb[1];
        int comb_d2 = comb[2];
        
        bool new_t0 = false;
        bool new_t1 = false;
        bool new_t2 = false;
        
        if (t0) {
            if (comb_d0 > d0) continue;
            if (comb_d0 == d0) new_t0 = true;
        }
        if (t1) {
            if (comb_d1 > d1) continue;
            if (comb_d1 == d1) new_t1 = true;
        }
        if (t2) {
            if (comb_d2 > d2) continue;
            if (comb_d2 == d2) new_t2 = true;
        }

        result = mod(result + rec(i - 1, new_t0, new_t1, new_t2));
    }

    return dp[i][t0][t1][t2] = result;
}

int count(int lim0, int lim1, int lim2) {
    LIM0 = lim0;
    LIM1 = lim1;
    LIM2 = lim2;
    memset(dp, -1, sizeof dp);
    return rec(29, 1, 1, 1);
}

void solve() {
    int T = 1;
    for (int i = 0; i < 3; ++i) {
        cin >> L[i] >> R[i];
        T = (T * (R[i] - L[i] + 1)) % M;
    }

    int A = count(R[0]    , R[1]    , R[2]    ); // RRR
    int B = count(L[0] - 1, R[1]    , R[2]    ); // LRR
    int C = count(R[0]    , L[1] - 1, R[2]    ); // RLR
    int D = count(R[0]    , R[1]    , L[2] - 1); // RRL
    int E = count(R[0]    , L[1] - 1, L[2] - 1); // RLL
    int F = count(L[0] - 1, R[1]    , L[2] - 1); // LRL
    int G = count(L[0] - 1, L[1] - 1, R[2]    ); // LLR
    int H = count(L[0] - 1, L[1] - 1, L[2] - 1); // LLL

    int zeroXor = A - (B + C + D) + (E + F + G) - H;
    int aliceWin = T - zeroXor;
    int prob = mod(aliceWin * inv(T));

    cout << prob << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
