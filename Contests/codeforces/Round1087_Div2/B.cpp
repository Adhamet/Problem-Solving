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
    int n;  std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    std::vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int mns = 0, mxs = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) mns++;
            else if (a[j] > a[i]) mxs++;
        }
        ans[i] = std::max(mns, mxs);
    }

    for (auto x: ans) std::cout << x << ' ';
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    
    int t;  std::cin >> t;
    while (t--) solve();
    return 0;
}
