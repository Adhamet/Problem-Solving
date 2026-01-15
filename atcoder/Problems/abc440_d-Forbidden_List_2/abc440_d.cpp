#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);


    int n, q;   std::cin >> n >> q;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::sort(a.begin(), a.end());

    while (q--) {
        i64 x, y;   std::cin >> x >> y;

        int fi = std::lower_bound(a.begin(), a.end(), x) - a.begin();
        int si;
        {
            int l = fi, r = n-1, ans = n;
            while (l <= r) {
                int md = (l + r) >> 1;
                if ((a[md] - x + 1) - (md - fi + 1) >= y) {
                    ans = md, r = md - 1;
                } else l = md + 1;
            }
            si = ans;
        }
        // debug(si,fi);
        std::cout << x + y - 1 + (si - fi) << '\n';
    }

    return 0;
}
