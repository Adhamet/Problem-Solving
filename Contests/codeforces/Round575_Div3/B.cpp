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

    int q;  std::cin >> q;
    while (q--) {
        int n, k;   std::cin >> n >> k;
        int odds = 0;
        std::vector<i64> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i], odds += (a[i] & 1);

        if (odds >= k && (odds - (k - 1)) & 1) {
            std::cout << "YES\n";
            k -= 1;
            for (int i = 0; i < n && k; i++) {
                if (a[i] & 1) {
                    std::cout << i + 1 << ' ';
                    k--;
                }
            }
            std::cout << n << '\n';
        } else std::cout << "NO\n";
    }

    return 0;
}
