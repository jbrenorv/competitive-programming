#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

typedef struct
{
  pii pos;
  int dist;
} point;

//(00)------- x
// |
// |
// |
// y

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int isValid(int x, int y, int r, int c)
{
  return ((x >= 0) && (x < c) && (y >= 0) && (y < r));
}

int unvisited(int pos)
{
  return pos == -1;
}

point multiSourceBFS(vector<vector<int>> G, vector<pii> &sources, int r, int c)
{
  int x, y;
  queue<pii> Q;
  point max_dist = (point){sources[0], 0};

  for (pii p : sources)
    Q.push(p);

  while (!Q.empty())
  {
    pii current = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++)
    {
      x = current.second + dx[i];
      y = current.first + dy[i];

      if (isValid(x, y, r, c) && unvisited(G[y][x]))
      {
        G[y][x] = G[current.first][current.second] + 1;
        Q.push({y, x});

        if (G[y][x] > max_dist.dist)
          max_dist = (point){{y, x}, G[y][x]};
      }
    }
  }

  return max_dist;
}

int main()
{
  int t, r, c;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cin >> r >> c;
    vector<vector<char>> M(r);
    vector<vector<int>> G(r);
    vector<pii> sources;
    int min_dist = 0;

    for (int j = 0; j < r; j++)
    {
      for (int k = 0; k < c; k++)
      {
        char ch;
        cin >> ch;
        M[j].push_back(ch);

        if (ch == '1')
        {
          sources.push_back({j, k});
          G[j].push_back(0);
        }
        else
        {
          G[j].push_back(-1);
          min_dist = 1001;
        }
      }
    }

    for (int j = 0; j < r; j++)
    {
      for (int k = 0; k < c; k++)
      {
        if (M[j][k] == '1')
          continue;

        sources.push_back({j, k});
        G[j][k] = 0;
        point aux = multiSourceBFS(G, sources, r, c);

        if (aux.dist < min_dist)
          min_dist = aux.dist;

        sources.pop_back();
        G[j][k] = -1;
      }
    }

    cout << "Case #" << (i + 1) << ": " << min_dist << endl;
  }

  return 0;
}
