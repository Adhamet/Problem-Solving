#include <bits/stdc++.h>
#include <vector>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

constexpr int MOD = 1e9+7, MXN = 2e5+150;

inline i64 addm(i64 a, i64 b) { a += b; if (a >= MOD) a -= MOD; return a; }
inline i64 subm(i64 a, i64 b) { a -= b; if (a < 0) a += MOD; return a; }

i64 binexp(i64 a, i64 b) {
    i64 res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

i64 fact[MXN], invfact[MXN];
void init_fact(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invfact[n] = binexp(fact[n], MOD - 2);
    for (int i = n; i > 0; i--)
        invfact[i - 1] = invfact[i] * i % MOD;
}

i64 nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    init_fact(MXN-95);
    
    int t; std::cin >> t;
    while (t--) {
        int n, m, k;  std::cin >> n >> m >> k;

        std::vector<i64> cnt(n+1,0);
        for (int i = 0; i < n; i++) {
            int x;  std::cin >> x;
            cnt[x]++;
        }

        std::vector<i64> pref(n+1,0);
        for (int i = 1; i <= n; i++) pref[i] = pref[i-1] + cnt[i];

        i64 ans = 0;
        for (int mn = 1; mn <= n; mn++) {
            int mx = std::min(n, k + mn);
            i64 rng = pref[mx] - pref[mn - 1];
            i64 rng2 = pref[mx] - pref[mn];
            ans = addm(ans, subm(nCr(rng,m), nCr(rng2, m)));
        } 

        std::cout << ans << '\n';
    }

    return 0;
}
