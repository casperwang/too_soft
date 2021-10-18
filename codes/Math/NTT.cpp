template <int mod, int G, int maxn>
struct NTT {
  static_assert (maxn == (maxn & -maxn));
  int roots[maxn];
  NTT () {
    for (int i = 1; i < maxn; i *= 2) {
        for (int j = 0; j < i; j++) {
            roots[i + j] =
              modpow(G, 1LL * (mod - 1) / 2 * j / i);
        }
    }
  }
  // n must be 2^k, and 0 <= F[i] < mod
  void inplace_ntt(int n, int F[], bool inv = false) {
    for (int i = 0, j = 0; i < n; i++) {
        if (i < j) swap(F[i], F[j]);
        for (int k = n>>1; (j^=k) < k; k>>=1);
    }
    for (int s = 1; s < n; s *= 2) {
        for (int i = 0; i < n; i += s * 2) {
            for (int j = 0; j < s; j++) {
                int a = F[i+j];
                int b = modmul(F[i+j+s], roots[s+j]);
                F[i+j] = modadd(a, b);   // a + b
                F[i+j+s] = modsub(a, b); // a - b
            }
        }
    }
    if (inv) {
        int invn = modinv(n);
        for (int i = 0; i < n; i++)
          F[i] = modmul(F[i], invn);
        reverse(F + 1, F + n);
    }
  }
};
const int P=2013265921,root=31;
const int MAXN=1<<20;
NTT<P, root, MAXN> ntt;
