#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

constexpr int MOD = (int)998244353;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    std::vector<i64> a(n), b(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < n; i++) std::cin >> b[i];

    for (int i = 0; i < n; i++) {
        a[i] = a[i] * (i64)(n - i) * (i + 1);
    }

    std::sort(a.begin(), a.end());
    std::sort(b.rbegin(), b.rend());

    i64 sm = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= MOD) a[i] %= MOD;
        sm = sm + (a[i] * b[i] % MOD);
        if (sm >= MOD) sm -= MOD;
    }

    return std::cout << sm, 0;
}

