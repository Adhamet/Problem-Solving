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
        int gcdA = 0, gcdB = 0;
        for (int i = 0; i < n; i++) {
            int x;  std::cin >> x;
            gcdA = std::gcd(gcdA, x);
        }
        for (int i = 0; i < n; i++) {
            int x;  std::cin >> x;
            gcdB = std::gcd(gcdB, x);
        }

        if (gcdA == gcdB) std::cout << 0 << '\n';
        else if (gcdA%gcdB == 0 || gcdB%gcdA == 0)
                std::cout << 1 << '\n';
        else std::cout << 2 << '\n';
    }

    return 0;
}
