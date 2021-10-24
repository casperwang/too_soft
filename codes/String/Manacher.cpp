int z[maxn];
int manacher(const string& s) {
  string t = ".";
  for(char c: s) t += c, t += '.';
  int l = 0, r = 0, ans = 0;
  for (int i = 1; i < t.length(); ++i) {
    z[i] = (r > i ? min(z[2 * l - i], r - i) : 1);
    while (i - z[i] >= 0 && i + z[i] < t.length()) {
      if(t[i - z[i]] == t[i + z[i]]) ++z[i];
      else break;
    }
    if (i + z[i] > r) r = i + z[i], l = i;
  }
  for(int i=1;i<t.length();++i) ans = max(ans, z[i]-1);
  return ans;
}
