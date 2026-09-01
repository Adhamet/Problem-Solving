#include <bits/stdc++.h>

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

    // Special Cases:
    // 1. 2 1 1 2
    // no both pairs must not be adjacent

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<int> a(2*n);
        std::vector<std::pair<int,int>> occ(n, {-1,-1});
        for (int i = 0; i < 2*n; i++) {
            std::cin >> a[i];
            a[i]--;
            if (occ[a[i]].first != -1) occ[a[i]].second = i;
            else occ[a[i]].first = i;
        }

        int ans = 0;
        std::vector<char> vis(n, 0);
        for (int i = 0; i < 2*n; i++) {
            if (vis[a[i]]) continue;
            vis[a[i]] = 1;
            int j = occ[a[i]].first;
            int k = occ[a[i]].second;

            if (std::abs(j - k) == 1) continue;

            if (j - 1 >= 0) {
                if (k+1 < 2*n && a[j-1]==a[k+1]) {
                    if (std::abs((j-1) - (k+1)) > 1) ans++;
                } else if (k-1 >= 0 && a[j-1]==a[k-1])
                    if (std::abs((j-1) - (k-1)) > 1) ans++;
            }

            if (j + 1 < 2*n) {
                if (k+1 < 2*n && a[j+1]==a[k+1]) {
                    if (std::abs((j+1) - (k+1)) > 1) ans++;
                } else if (k-1 >= 0 && a[j+1]==a[k-1])
                    if (std::abs((j+1) - (k-1)) > 1) ans++;
            }
        }

        std::cout << ans / 2 << '\n';
    }

    return 0;
}
