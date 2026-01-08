#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXN = (int)1e6+5;

int mod;



i64 binexp(i64 a, i64 b) {
    i64 res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int fact[MXN], invfact[MXN];
void init_fact(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;
    
    invfact[n] = binexp(fact[n], mod - 2);
    for (int i = n; i > 0; i--)
        invfact[i - 1] = invfact[i] * i % mod;
}

i64 nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    init_fact(MXN-2);

    int n;  std::cin >> n >> mod;

    i64 inc_exc = 0;
    for (int i = 0; i < n; i++) {
        i64 fct1 = nCr(n, i+1);
        i64 fct2 = fact[n-(i+1)];
        if (i & 1) inc_exc = inc_exc - (fct1 * fct2 % MOD));
        else inc_exc += (fct1 * fct2);
    } 

    return std::cout << fact[n] - inc_exc, 0;
}
