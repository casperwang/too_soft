namespace simplex {
// maximize c^Tx under Ax <= B and x >= 0
// return VD(n, -inf) if the solution doesn't exist
// return VD(n, +inf) if the solution is unbounded
using VD = vector<llf>;
using VVD = vector<vector<llf>>;
const llf eps = 1e-9, inf = 1e+9;
int n, m; VVD d; vector<int> p, q;
void pivot(int r, int s) {
  llf inv = 1.0 / d[r][s];
  for (int i = 0; i < m + 2; ++i)
    for (int j = 0; j < n + 2; ++j)
      if (i != r && j != s)
        d[i][j] -= d[r][j] * d[i][s] * inv;
  for(int i=0;i<m+2;++i) if (i != r) d[i][s] *= -inv;
  for(int j=0;j<n+2;++j) if (j != s) d[r][j] *= +inv;
  d[r][s] = inv; swap(p[r], q[s]);
}
bool phase(int z) {
  int x = m + z;
  while (true) {
    int s = -1;
    for (int i = 0; i <= n; ++i) {
      if (!z && q[i] == -1) continue;
      if (s == -1 || d[x][i] < d[x][s]) s = i;
    }
    if (s == -1 || d[x][s] > -eps) return true;
    int r = -1;
    for (int i = 0; i < m; ++i) {
      if (d[i][s] < eps) continue;
      if (r == -1 ||
        d[i][n+1]/d[i][s] < d[r][n+1]/d[r][s]) r = i;
    }
    if (r == -1) return false;
    pivot(r, s);
  }
}
VD solve(const VVD &a, const VD &b, const VD &c) {
  m = (int)b.size(), n = (int)c.size();
  d = VVD(m + 2, VD(n + 2));
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j) d[i][j] = a[i][j];
  p.resize(m), q.resize(n + 1);
  for (int i = 0; i < m; ++i)
    p[i] = n + i, d[i][n] = -1, d[i][n + 1] = b[i];
  for (int i = 0; i < n; ++i) q[i] = i,d[m][i] = -c[i];
  q[n] = -1, d[m + 1][n] = 1;
  int r = 0;
  for (int i = 1; i < m; ++i)
    if (d[i][n + 1] < d[r][n + 1]) r = i;
  if (d[r][n + 1] < -eps) {
    pivot(r, n);
    if (!phase(1) || d[m + 1][n + 1] < -eps)
      return VD(n, -inf);
    for (int i = 0; i < m; ++i) if (p[i] == -1) {
      int s = min_element(d[i].begin(), d[i].end() - 1)
              - d[i].begin();
      pivot(i, s);
    }
  }
  if (!phase(0)) return VD(n, inf);
  VD x(n);
  for (int i = 0; i < m; ++i)
    if (p[i] < n) x[p[i]] = d[i][n + 1];
  return x;
}}
