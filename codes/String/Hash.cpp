class Hash {
  private:
    static constexpr int P = 127, Q = 1051762951;
    vector<int> h, p;
  public:
    void init(const string &s){
      h.assign(s.size(), 0); p.resize(s.size());
      for (size_t i = 0; i < s.size(); ++i)
        h[i + 1] = add(mul(h[i], P), s[i]);
      generate(p.begin(), p.end(),
          [x=1, this]()mutable{return x=mul(x, P);});
    }
    int query(int l, int r){ // 1-base (l, r]
      return sub(h[r], mul(h[l], p[r-l]));}
};
