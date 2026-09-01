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
        int n, k;   std::cin >> n >> k;
        int nn = n, kk = 0, ans = 0;
        while (kk <= std::min(k, 10)) {
            int cur = kk;
            if (nn % 3 == 0) cur += nn/3;
            else if (nn % 2 == 0) cur += nn/2;
            else cur += nn;
            ans = std::max(ans, cur);
            nn--, kk++;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
