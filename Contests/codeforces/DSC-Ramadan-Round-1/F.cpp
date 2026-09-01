#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

struct SplitMix64 {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const noexcept {
        static const uint64_t FIXED_RANDOM = 
            std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    // 10000 & 01111 = 0
    // pref[i + k] - pref[i] = 2^x
    // 2^x + pref[i] = pref[i + k]
    int n;  std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    std::unordered_map<i64,i64, SplitMix64> cnt;
    cnt[0] = 1;
    cnt.reserve(n * 2);
    std::vector<i64> pref(n, 0);
    
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        pref[i] = (i == 0 ? a[0] : pref[i-1] + a[i]);
        // debug(pref[i])
        
        {
            auto it = cnt.find(pref[i]);
            if (it != cnt.end()) ans += it->second;
        }
        for (i64 j = 0; j <= 47; j++) {
            i64 v = (1LL << j);
            auto it = cnt.find(pref[i] - v);
            if (it != cnt.end()) ans += it->second;
        }

        cnt[pref[i]]++;
    }

    return std::cout << ans, 0;
}
