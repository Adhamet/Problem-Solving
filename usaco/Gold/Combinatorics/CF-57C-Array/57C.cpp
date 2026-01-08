#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using i64 = long long;

constexpr int MOD = 1e9+7, MXN = 2e5+5;

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
    init_fact(MXN - 3);

    i64 n;  std::cin >> n;
    i64 cond1 = nCr(n+n-1, n - 1);
    std::cout << (cond1 * 2 % MOD) - n;

    return 0;
}
