#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

constexpr int MOD = (int)1e9+7, MXN = 1e6+5;

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
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    init_fact(MXN-2);
    
    int n;  std::cin >> n;
    while (n--) {
        i64 a, b;   std::cin >> a >> b;
        std::cout << nCr(a, b) << '\n';
    }

    return 0;
}
