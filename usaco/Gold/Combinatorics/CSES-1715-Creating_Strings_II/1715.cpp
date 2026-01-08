#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

constexpr int MXN = (int)1e6+5, MOD = (int)1e9+7;

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

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    init_fact(MXN-2);

    std::string s;  std::cin >> s;
    std::map<char, int> freq;
    for (auto c: s) freq[c]++;

    i64 ans = fact[(int)s.size()];
    for (auto [c, v]: freq) {
        ans = ans * invfact[v] % MOD;
    }

    return std::cout << ans, 0;
}
