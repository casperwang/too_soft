struct SA {
  int n; vector<int> sa, rk, tmp, c, lcp;
  SA(auto &v, int z = 256) : n(v.size()), sa(n),
    rk(all(v)), tmp(n), c(max(n,z)+1), lcp(n) {
    iota(all(sa), 0); rk.insert(rk.end(), n, -1);
    const auto radix = [&](int s) {
      for (int i = 0; i <= z; i++) c[i] = 0;
      for (int i = 0; i < n; i++) ++c[rk[i + s] + 1];
      for (int i = 1; i <= z; i++) c[i] += c[i - 1];
      for (int i = n - 1; i >= 0; i--)
        tmp[--c[rk[sa[i] + s] + 1]] = sa[i];
      sa = tmp;
    };
    for (int L = 1; L < n; L *= 2, z = n) {
      for (int s: {L, 0}) radix(s);
      auto F = [&](int a) {
        return pair(rk[a], rk[a + L]); };
      tmp[0] = 0;
      for (int i = 1; i < n; i++)
        tmp[i] = tmp[i - 1] + (F(sa[i - 1]) < F(sa[i]));
      for (int i = 0; i < n; i++) rk[sa[i]] = tmp[i];
    }
    for (int i = 0, h = 0; i < n; i++) if (rk[i]) {
      if (h > 0) --h;
      int j = sa[rk[i] - 1];
      while (i + h < n && j + h < n
          && v[i + h] == v[j + h]) ++h;
      lcp[rk[i] - 1] = h;
    }
  }
}; // test @ yosupo judge
