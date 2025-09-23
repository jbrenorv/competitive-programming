#include <iostream>

using namespace std;

typedef long long int lii;

int main()
{
  lii l, r, n;
  int t;
  cin >> t;

  for (int i = 0; i < t; i++)
  {
    cin >> l >> r;
    n = min<lii>(l, r);
    cout << "Case #" << (i + 1) << ": " << (((n + 1) * n) / 2) << endl;
  }

  return 0;
}
