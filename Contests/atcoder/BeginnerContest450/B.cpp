#include <bits/stdc++.h>

// -- Don't use with doubles -----------
// #pragma GCC optimize ("Ofast")
// #pragma GCC optimize ("unroll-loops")
// -------------------------------------
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

    int n;  std::cin >> n;
    std::vector c(n+1, std::vector<i64>(n+1));
    for (int i = 1; i <= n-1; i++) {
        for (int j = i+1; j <= n; j++) {
            std::cin >> c[i][j];
        }
    }

    // debug("TEST");
    bool acc = false;
    for (int i = 1; i <= n-2 && !acc; i++) {
        for (int j = i + 1; j <= n-1 && !acc; j++) {
            for (int k = j + 1; k <= n && !acc; k++) {
                if (c[i][j] + (i64)c[j][k] < (i64)c[i][k]) {
                    acc = true;
                    break;
                }
            }
        }
    }

    return std::cout << (acc? "Yes": "No") << '\n', 0;
}
