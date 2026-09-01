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
        i64 s, m;   std::cin >> s >> m;
        int ans = 0;
        while (s) {
            i64 v = 0;
            if (m <= s) v = m;
            for (int i = 63; i >= 0; --i) {
                i64 bit = 1LL << i;
                if ((m & bit) == 0) continue;
                i64 curMsk = v | bit;
                curMsk |= (m & (i==0? 0LL: (1LL<<i)-1LL));
                if (curMsk <= s) {
                    v |= curMsk;
                }
            }
            // debug(v);

            if (v == 0) break;
            ans += (s / v);
            s -= (s / v) * v;
        }

        std::cout << (s? -1: ans) << '\n';
    }

    return 0;
}
