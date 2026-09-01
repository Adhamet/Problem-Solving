#include <bits/stdc++.h>

// -- Don't use with doubles -----------
// #pragma GCC optimize ("Ofast")
// #pragma GCC optimize ("unroll-loops")
// // -------------------------------------
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    // pair (a,b)
    // 2^a * b^2
    // N <= 1e18
    // maximum a = 61 (2^61 = 2e18)
    // maximum b = 1e9.
    // how many Bs exist for a fixed a s.t.
    // (2^a * b^2) <= n
    // b^2 <= n/2^a     ==>     b <= sqrt(n / 2^a)
    // 2*2*b*b = 2b*2b = (2b)^2
    // all odd values they can be turned into
    // 2^x * b^2 => 2^1 * 2^x-1 * b^2 => 2^1 * (2^(x-1)/2 * b)^2
    // all even values can be
    // 2^2 * 2^x-2 * b^2 => 2^2 * (2^(x-2)/2 * b)^2
    // for a = 1,2
    i64 n;  std::cin >> n;
    i64 ans = 0;
    for (int a = 1; a <= 2; a++) ans += std::sqrtl(n / (1LL<<a));
    return std::cout << ans, 0;
}
