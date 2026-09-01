#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    i64 l, r, ai;   std::cin >> l >> r >> ai;
    i64 k = ai - 1;
    if (ai == 1) std::cout << r << '\n';
    else {
        i64 ll = 0, rr = 1e9, ans = 0;
        while (ll <= rr) {
            i64 md = (ll + rr) >> 1;
            if (k + md * ai <= r) ans = k+md*ai, ll = md + 1;
            else rr = md - 1;
        }

        if (ans < l) ans += ai;
        if (ans > r) ans = r;
        std::cout << (ans / ai) + (ans % ai) << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    // x = pa + r
    // p = floor(x / a)
    // q = x mod a
    // special case: a -= 1, a ++ a while a <= r.
    // k + x*(ai)
    int t;  std::cin >> t;
    while (t--) solve();
    return 0;
}
