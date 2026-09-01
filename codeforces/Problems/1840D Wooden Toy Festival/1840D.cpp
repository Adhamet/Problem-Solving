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

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) std::cin >> a[i];
        std::sort(a, a+n);

        auto can = [&](int k) -> bool {
            int used = 0;
            int i = 0;
            while (i < n) {
                used++;
                int limit = a[i] + 2 * k;
                while (i < n && a[i] <= limit) i++;
                if (used == 3) break;
            }
            return (i >= n);
        };

        int l = 0, r = (int)1e9, ans = r;
        while (l <= r) {
            int md = (l + r) >> 1;
            if (can(md)) ans = md, r = md - 1;
            else l = md + 1;
        }

        std::cout << ans << '\n';
    }

    return 0;
}
