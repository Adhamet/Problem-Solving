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
        int n, w, d;    std::cin >> n >> w >> d;
        int oneTower = d/w;
        if (oneTower == 0) std::cout << n << '\n';
        else if (oneTower+1 >= n) std::cout << 1 << '\n';
        else {
            int cnt = 0;
            while (n > oneTower+1) {
                debug(n);
                n -= oneTower+1;
                cnt++;
            }
            std::cout << (n? cnt+1: cnt) << '\n';
        }
    }

    return 0;
}
