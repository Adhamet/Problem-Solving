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
        int n, w;   std::cin >> n >> w;
        std::vector<i64> c(n);
        for (int i = 0; i < n; i++) std::cin >> c[i];

        std::vector<i64> buckets((int)2*w, 0);
        for (int i = 0; i < n; i++)
            buckets[i%(2*w)] += c[i];

        std::vector<i64> adv_buckets((int)4*w+1, 0);
        for (int i = 0; i < 2*w; i++)
            adv_buckets[i] = adv_buckets[i+2*w] = buckets[i];

        for (int i = 1; i <  4*w; i++) adv_buckets[i] += adv_buckets[i-1];
        
        i64 ans = LLONG_MAX;
        for (int i = 0; i < 2*w; i++) {
            i64 cur = adv_buckets[i+w-1] - (i>0? adv_buckets[i-1]: 0);
            ans = std::min(ans, cur);
        }

        std::cout << ans << '\n';
    }

    return 0;
}

