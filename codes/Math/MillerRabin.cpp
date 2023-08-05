bool isprime(llu x) {
  static auto witn = [](llu a, llu n, int t) {
    if (!a) return false;
    while (t--) {
      llu a2 = mmul(a, a, n);
      if (a2 == 1 && a != 1 && a != n - 1) return true;
      a = a2;
    }
    return a != 1;
  };
  if (x < 2) return false;
  if (!(x & 1)) return x == 2;
  int t = __builtin_ctzll(x - 1);
  llu odd = (x - 1) >> t;
  for (llu m:
    {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
    if (witn(mpow(m % x, odd, x), x, t))
      return false;
  return true;
}