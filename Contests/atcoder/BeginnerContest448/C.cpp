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

    // it's about neglecting the Bis,
    // since k is small we could brute force this
    int n, q;   std::cin >> n >> q;
    std::vector<std::pair<int,int>> mn(n);
    for (int i = 0; i < n; i++) {
        std::cin >> mn[i].first;
        mn[i].second = i;
    }
    std::sort(mn.begin(), mn.end());

    std::vector<char> block(n, 0);
    while (q--) {
        int k;  std::cin >> k;

        // block
        std::vector<int> b(k);
        for (int i = 0; i < k; i++) {
            std::cin >> b[i];
            b[i]--;
            block[b[i]] = 1;
        }

        // process
        int i = 0;
        while (block[mn[i].second]) i++;
        std::cout << mn[i].first << '\n';

        // unblock
        for (int i = 0; i < k; i++) block[b[i]] = 0;
    }

    return 0;
}
