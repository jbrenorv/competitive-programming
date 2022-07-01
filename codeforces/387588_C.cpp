#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (int)1e9
#define LONGINF (long long)1e18
#define MEM(arr, val) memset(arr, (val), sizeof(arr))
#define FASTIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
const int MOD = 1000000007; // 10^9 + 7

typedef long long int lii;

void phi_1_to_n(vector<int> &phi, int n)
{
  for (int i = 2; i <= n; i++)
    for (int j = 2 * i; j <= n; j += i)
      phi[j] -= phi[i];
}

int main()
{
  FASTIO;

  vector<int> phi;
  int d;
  cin >> d;

  phi.push_back(0);
  phi.push_back(1);
  for (int i = 2; i <= d; i++)
    phi.push_back(i - 1);

  phi_1_to_n(phi, d);
  lii ans = 0;
  for (int i = 2; i <= d; i++)
  {
    ans += phi[i];
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}