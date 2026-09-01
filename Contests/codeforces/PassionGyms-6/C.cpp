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
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        if (n == 2) {
            if (a[0] == a[1]) std::cout << 1 << '\n';
            else std::cout << 0 << '\n';
        } else {
            std::vector<int> prefGCD(n, 0), suffGCD(n, 0);
            prefGCD[0] = a[0], suffGCD[n-1] = a[n-1];
            for (int i = 1; i < n; i++) 
                prefGCD[i] = std::gcd(prefGCD[i-1], a[i]);
            for (int i = n - 2; i >= 0; i--)
                suffGCD[i] = std::gcd(suffGCD[i+1], a[i]);

            int ans = 0;
            for (int i = 0; i < n-1; i++) {
                int lhs = prefGCD[i];
                int rhs = suffGCD[i+1];
                if (lhs == 1 || rhs == 1) ans += 1;
                else {
                    int mx = std::max(lhs, rhs);
                    int mn = std::min(lhs, rhs);
                    if (mx % mn == 0) ans++;
                }
            }

            std::cout << ans << '\n';
        }

    }

    return 0;
}
