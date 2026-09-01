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
    int n;
    i64 k;
    std::cin >> n >> k;

    std::vector<i64> a(n);
    i64 mx = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        mx = std::max(mx, a[i]);
    }
    for (int i = 0; i < n; i++) {
        i64 diff = mx - a[i];
        a[i] += ((diff+k-1)/k) * k;
    }
    std::sort(a.begin(), a.end());

    i64 ans = a.back() - a.front();
    for (int i = 0; i < n - 1; i++)
        ans = std::min(ans, (a[i] + k) - a[i+1]);
    std::cout << ans;
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    // let P = a[i] + kx, Q = a[j] + ky
    // minimize(P - Q)
    // where P >= Q & P is current max & Q is current min
    // I have no proof but I think we start off by adding to
    // all of them and making them just exactly below the max, 
    // first we check the current max - current min, then
    // for each number (each case is independent) 
    // try to make some ai just above the max and check its
    // relation with the min
    solve();
    return 0;
}
