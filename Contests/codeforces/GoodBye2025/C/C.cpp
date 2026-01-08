#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

i64 toPos(i64 x) {
    return (x<0? -x: x);
}

void solve() {
    int n;  std::cin >> n;

    i64 a[n];
    for (int i = 0; i < n; i++) std::cin >> a[i];
    
    if (n == 1) return void(std::cout << a[0] << '\n');
    else if (n == 2) return void(std::cout << std::max(a[0], -a[1]) << '\n');

    std::vector<i64> prefPos(n), suffNeg(n);
    prefPos[0] = a[0], suffNeg[n-1] = (-a[n-1]);
    for (int i = 1; i < n; i++) prefPos[i] = prefPos[i-1] + toPos(a[i]);
    for (int i = n-2; i >= 0; i--) suffNeg[i] = suffNeg[i+1] + (-a[i]);

    i64 ans = -LONG_MAX;
    for (int i = 0; i < n; i++) {
        i64 contrib1 = 0;
        i64 contrib2 = 0;
        if (i > 0) contrib1 = prefPos[i-1];
        if (i < n-1) contrib2 = suffNeg[i+1];
        debug(i), debug(suffNeg[i]), debug(suffNeg[n-1]), debug(contrib1), debug(contrib2);
        ans = std::max(ans, contrib1 + contrib2);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
