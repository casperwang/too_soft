#define all(x) begin(x), end(x)
#ifdef too_soft
#define safe cerr<<__PRETTY_FUNCTION__<<" line "<<__LINE__<<" safe\n"
#define debug(args...) kout("\e[1;32m[ " + string (#args) + " ]\e[0m", args)
void kout() { cerr << endl; }
template <class T, class ...U> void kout(T a, U ...b) { cerr << a << ' ',kout(b...); }
template <class T> void pary(T L, T R) { while (L != R) cerr << *L << " \n"[++L==R]; }
#else
#define safe ((void)0)
#define debug(...) safe
#define pary(...) safe
#endif
