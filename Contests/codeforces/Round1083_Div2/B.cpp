#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        i64 n;  std::cin >> n;

        i64 tmp = n, k = 1;
        for (i64 p = 2; p * p <= tmp; ++p) {
            if (tmp % p == 0) {
                k *= p;
                while (tmp % p == 0) tmp /= p;
            }
        }
        if (tmp > 1) k *= tmp;

        std::cout << k << '\n';
    }

    return 0;
}
