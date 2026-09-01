#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

constexpr i64 MOD = (i64)1e9+7;

inline i64 addm(i64 a, i64 b) { a += b; if (a >= MOD) a -= MOD; return a; }

i64 binexp(i64 a, i64 b) {
    i64 res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        i64 n;  std::cin >> n;
        std::vector<i64> a(n);
        std::map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            cnt[a[i]]++;
        }
        
        int mex = 0;
        while (cnt.count(mex)) mex++;
        i64 ans = 0, lhs = 1, rhs = n;

        for (int x = 1; x <= mex + 1; x++) {
            if (cnt[x-1] == 0) break;
            i64 curLHS = (binexp(2, cnt[x-1]) - 1 + MOD) % MOD;
            lhs = (lhs * curLHS) % MOD;
            rhs -= cnt[x-1];
            i64 cur = (lhs * binexp(2, rhs)) % MOD;
            ans = addm(ans, cur);
        }

        std::cout << ans << '\n';
    }

    return 0;
}
