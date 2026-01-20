#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        std::sort(a.begin(), a.end());
        a.erase(std::unique(a.begin(), a.end()), a.end());

        // for (auto x: a) debug(x);

        int m = (int)a.size();

        int len = 1;
        for (int i = 0; i < m-1;) {
            int cur = 1;
            while (i+1 < m && std::abs(a[i] - a[i+1]) == 1) {
                cur += 1;
                i++;
            }
            len = std::max(len, cur);
            i++;
        }

        std::cout << len << '\n';
    }

    return 0;
}
