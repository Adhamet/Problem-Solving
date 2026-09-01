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
    std::cout << std::fixed << std::setprecision(10);

    int t;
    std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<int> c(n), p(n);
        for (int i = 0; i < n; i++) std::cin >> c[i] >> p[i];
        double dp = 0.0;
        for (int i = n - 1; i >= 0; i--)
            dp = std::max(dp, c[i] + dp * (1.0 - p[i] / 100.0));
        std::cout << dp << '\n';
    }

    return 0;
}
