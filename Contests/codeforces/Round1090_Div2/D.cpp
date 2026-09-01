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
        for (i64 i = 1; i <= n; i++)
            std::cout << (2*i-1) * (2*i+1) << ' ';
        std::cout << '\n';
    }
    return 0;
}
