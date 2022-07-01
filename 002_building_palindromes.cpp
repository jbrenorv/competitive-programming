#include <iostream>
#include <string.h>
#define MAXN 100007
#define DIR(i) 2 * i + 1
#define ESQ(i) 2 * i

using namespace std;

typedef struct
{
  int row[30];
  int l, r;
} node;

node tree[4 * MAXN];

node make_node(char c, int p)
{
  node res;
  for (int i = 0; i < 26; i++)
    res.row[i] = 0;
  res.row[c - 65] = 1;
  res.l = res.r = p;

  return res;
}

int isValid(node x)
{
  return (x.l != -1);
}

node combine(node a, node b)
{
  node res;
  for (int i = 0; i < 26; i++)
    res.row[i] = a.row[i] + b.row[i];

  res.l = isValid(a) ? a.l : b.l;
  res.r = isValid(b) ? b.r : a.r;

  return res;
}

void build(char a[], int i, int l, int r)
{
  if (l == r)
  {
    tree[i] = make_node(a[l], l);
  }
  else
  {
    int m = (l + r) / 2;
    build(a, ESQ(i), l, m);
    build(a, DIR(i), m + 1, r);
    tree[i] = combine(tree[ESQ(i)], tree[DIR(i)]);
  }
}

node query(int i, int l, int r)
{
  if (l > r)
    return make_node('[', -1);
  if (tree[i].l == l && tree[i].r == r)
    return tree[i];

  int m = (tree[i].l + tree[i].r) / 2;
  return combine(query(ESQ(i), l, min<int>(r, m)),
                 query(DIR(i), max<int>(l, m + 1), r));
}

int isPossible(node x)
{
  int odd = 0;
  for (int i = 0; i < 26; i++)
  {
    if (x.row[i] % 2)
      odd++;

    if (odd > 1)
      return 0;
  }
  return 1;
}

int main()
{
  int t, n, q, l, r, ans;
  char a[MAXN];
  cin >> t;

  for (int i = 0; i < t; i++)
  {
    cin >> n >> q;
    cin >> a;
    build(a, 1, 0, n - 1);
    ans = 0;

    for (int j = 0; j < q; j++)
    {
      cin >> l >> r;
      node x = query(1, l - 1, r - 1);
      if (isPossible(x))
        ans++;
    }

    cout << "Case #" << (i + 1) << ": " << ans << endl;
  }

  return 0;
}
