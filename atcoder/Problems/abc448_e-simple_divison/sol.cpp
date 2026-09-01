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

    // to be able to fully understand the problem
    // you will need long division comprehension.
    
    const int MOD = 10007;

    int n, m;   std::cin >> n >> m;
    std::vector<std::pair<int,int>> vp(n);
    for (int i = 0; i < n; i++)
        std::cin >> vp[i].first >> vp[i].second;
    
    // we need a vector for holding ancainders
    // another for holding quotients
    // [digit][power of two][going from ancainder x]
    // why is our driver the ancainder rather than the quotient?
    // it's because the ancainder is what we calculate on

    int pw10[31];
    pw10[0] = 10;
    for (int i = 1; i < 31; i++) {
        pw10[i] = pw10[i-1] * pw10[i-1] % MOD;
    }

    std::vector anc(10, std::vector(31, std::vector<int>(m)));
    std::vector quo(10, std::vector(31, std::vector<int>(m)));
    for (int di = 0; di < 10; di++) {
        for (int x = 0; x < m; x++) {
            int v = x * 10 + di;
            anc[di][0][x] = (v % m);
            quo[di][0][x] = (v / m) % MOD;
        }
    }
    for (int di = 0; di < 10; di++) {
        for (int p2 = 1; p2 < 31; p2++) {
            for (int x = 0; x < m; x++) {
                anc[di][p2][x] = anc[di][p2-1][anc[di][p2-1][x]];
                quo[di][p2][x] = (
                    (i64)quo[di][p2-1][x] * pw10[p2-1] % MOD +
                    quo[di][p2-1][anc[di][p2-1][x]]
                ) % MOD;
            }
        }
    }

    int node = 0;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int di = vp[i].first, li = vp[i].second;

        for (int e = 0; e < 31; e++) if ((li >> e) & 1) {
            ans = (ans * pw10[e] % MOD + quo[di][e][node]) % MOD;
            node = anc[di][e][node];
        }
    }

    return std::cout << ans, 0;
}
