#include <bits/stdc++.h>

using i64 = long long;

i64 binexp(i64 a, i64 e, i64 mod) {
    i64 r = 1;
    while (e) {
        if (e & 1) r = r * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return r;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    const int MOD = (int)1e9+7, MXV = (int)2e5;

    int n;  std::cin >> n;
    int totSm = (n * (n + 1)) / 2;
    if (totSm % 2 != 0) {
        std::cout << 0 << '\n';
        return 0;
    }

    std::vector<i64> dp(MXV+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = MXV; j >= i; j--) {
            dp[j] += dp[j - i];
            if (dp[j] >= MOD) dp[j] -= MOD;
        }
    }

    i64 twoInMod = binexp(2, MOD - 2, MOD);
    return std::cout << dp[totSm/2] * twoInMod % MOD, 0;
}
