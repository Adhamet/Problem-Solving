#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

void solve() {
    int n;  std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) std::cin >> a[i];

    int final_or = 0;
    std::vector<int> res;
    std::vector<bool> vis(n, false);

    for (int i = 0; i < std::min(31, n); i++) {
        int best_cur = final_or, idx = -1;

        for (int j = 0; j < n; j++) if (!vis[j]) {
            if ((final_or | a[j]) > best_cur) {
                best_cur = (final_or | a[j]);
                idx = j;
            }
        }

        if (~idx) {
            res.push_back(a[idx]);
            final_or = best_cur;
            vis[idx] = true;
        }
    }

    for (auto x: res) std::cout << x << ' ';
    for (int i = 0; i < n; i++) if (!vis[i])
        std::cout << a[i] << ' ';
    std::cout << '\n';
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
