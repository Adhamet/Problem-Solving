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
        i64 n;  std::cin >> n;
        i64 vis = 0;
        for (i64 i = 2; i*i <= n; i++)
            vis++; // vis[i*i] = 1;
        std::cout << 1 + (n - vis - 1) * n + vis << '\n';
    }

    return 0;
}
