#include <bits/stdc++.h>

// -- Don't use with doubles -----------
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
// -------------------------------------
#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

i64 binexp(i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    i64 n, m;
    std::cin >> n >> m;
    i64 ans = 0;
    for (int i = 0; i <= m; i++) {
        ans += binexp(n, i);
        if (ans > (int)1e9) break;
    }

    if (ans > (int)1e9) std::cout << "inf";
    else std::cout << ans;
    return 0;
}
