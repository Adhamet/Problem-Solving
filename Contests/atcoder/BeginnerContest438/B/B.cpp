#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;   std::cin >> n >> m;
    std::string s, t;
    std::cin >> s >> t;

    int ans = 1e9;
    for (int i = 0; i + m <= n; i++) {
        int cur = 0;
        for (int j = 0; j < m; j++)
            cur += (s[i+j] - t[j] + 10) % 10;
        ans = std::min(ans, cur);
    }

    return std::cout << ans, 0;
}
