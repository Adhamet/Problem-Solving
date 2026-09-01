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

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n, m, l;    std::cin >> n >> m >> l;
        std::vector<int> fl(n), danger(m, 0);
        for (int i = 0; i < n; ++i) std::cin >> fl[i];

        if (m == 1) {
            std::cout << l - fl[n - 1] << '\n';
            continue;
        }

        int curFl = 0;
        for (int i = 1; i <= l; ++i) {
            std::sort(danger.rbegin(), danger.rend());
            int remFlashes = n - curFl;
            int active = std::min(m, remFlashes + 1);
            danger[active - 1]++;
            if (curFl < n && i == fl[curFl]) {
                auto it = std::max_element(danger.begin(), danger.end());
                *it = 0;
                curFl++;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) 
            ans = std::max(ans, danger[i]);
        std::cout << ans << '\n';
    }

    return 0;
}
