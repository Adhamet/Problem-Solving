#include <bits/stdc++.h>

using i64 = long long;

template<int MOD> struct mint {
    int v;
    mint(): v(0) {}
    mint(i64 _v) { v = int((_v % MOD + MOD) % MOD); }
    mint& operator+=(const mint& o) { if ((v += o.v) >= MOD) v -= MOD; return *this; }
    mint& operator-=(const mint& o) { if ((v -= o.v) < 0) v += MOD; return *this; }
    mint& operator*=(const mint& o) { v = int((i64)v * o.v % MOD); return *this; }
    friend mint pow(mint a, i64 p) {
        mint res = 1;
        while (p) {
            if (p & 1) res *= a;
            a *= a;
            p >>= 1;
        }
        return res;
    }
    friend mint inv(mint a) { return pow(a, MOD-2); }
    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }
};

using mint_mod = mint<(int)1e9+7>;
using mint_phi = mint<(int)1e9+6>;

void solve() {
    i64 a, b, c;
    std::cin >> a >> b >> c;
    
    mint_phi exp = pow(mint_phi(b), c);
    mint_mod ans = pow(mint_mod(a), exp.v);
    
    std::cout << ans.v << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

