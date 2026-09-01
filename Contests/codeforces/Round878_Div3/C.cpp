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
        i64 n, k, q;    std::cin >> n >> k >> q;
        std::vector<i64> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        i64 ans = 0;
        for (int i = 0; i < n;) {
            i64 len = 0;
            while (i < n && a[i] <= q) len += 1, i += 1;
            i64 x = len - (k - 1);
            if (x > 0) ans += x*(x+1)/2;
            i++;
        }
        
        std::cout << ans << '\n';
    }

    return 0;
}
