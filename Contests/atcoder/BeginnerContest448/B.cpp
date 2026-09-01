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

    int n, m;   std::cin >> n >> m;
    std::vector<int> pep(m);
    for (int i = 0; i < m; i++) std::cin >> pep[i];

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int ai, bi; std::cin >> ai >> bi;
        ai--;

        ans += std::min(pep[ai], bi);
        pep[ai] = std::max(0, pep[ai] - bi);
    }

    return std::cout << ans, 0;
}
