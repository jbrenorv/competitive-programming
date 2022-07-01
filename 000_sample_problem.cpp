#include <iostream>

using namespace std;

int main()
{
  int t, n, m, sum, c;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cin >> n >> m;
    sum = 0;
    for (int j = 0; j < n; j++)
    {
      cin >> c;
      sum += c;
    }
    cout << "Case #" << (i + 1) << ": " << sum % m << endl;
  }

  return 0;
}
