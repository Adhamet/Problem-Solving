#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const int MOD = 1e9+7;

    int n;
    std::cin >> n;

    i64 phi[n + 3];
    for (i64 i = 0; i <= n; i++) {
        phi[i] = i;
    }
    phi[0] = 0, phi[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }

    std::vector<i64> divs[n + 2];
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = i + i; j <= n; j += i) {
            divs[j].push_back(i);
        }
    }

    i64 ans = 0;
    for (i64 c = 1; c <= n - 2; c++) {
        for (auto div: divs[n - c]) {
            ans = (ans + (phi[(n-c) / div] * std::lcm((i64)c, (i64)div) % MOD)) % MOD;
        }
    }

    return std::cout << ans, 0;
}
