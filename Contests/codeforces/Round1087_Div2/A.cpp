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

void solve() {
    int n;    std::cin >> n;
    i64 c, k;  std::cin >> c >> k;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (a[i] < c) {
            int inc = std::min(k, c - a[i]);
            k -= inc;
            a[i] += inc;
            c += a[i];
        } else if (a[i] == c) c += a[i];
        else break;
    }

    std::cout << c << '\n';
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t;  std::cin >> t;
    while (t--) solve();
    return 0;
}
