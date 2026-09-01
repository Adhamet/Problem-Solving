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
        int n, m;
        std::cin >> n >> m;
        std::vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < m; ++i) std::cin >> b[i];

        std::vector<bool> accessible(1e6+3, false);
        std::vector<int> uqA = a;
        std::sort(uqA.begin(), uqA.end());
        uqA.erase(std::unique(uqA.begin(), uqA.end()), uqA.end());
        for (int x: uqA) {
            for (int mul = x; mul <= 1e6; mul += x) {
                if (accessible[mul]) break;
                accessible[mul] = true;
            }
        }

        int cnt = 0;
        for (int x: b) {
            if (accessible[x]) cnt++;
        }
        
        if (cnt >= (m + 1) / 2) std::cout << "Alice\n";
        else std::cout << "Bob\n";
    }

    return 0;
}
