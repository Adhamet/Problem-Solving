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
        i64 moves = n;
        for (i64 i = 1; i * i <= n; i++) {
            moves = std::min(moves, (i-1) + (((n+i-1)/i) - 1));
        }
        std::cout << moves << '\n';
    }

    return 0;
}
