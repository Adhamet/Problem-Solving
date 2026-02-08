#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

constexpr int MXV = (int)5e5+5;

int dp[MXV];

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, c;   std::cin >> n >> c;
    int cntC = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int x;  std::cin >> x;

        if (x == c) cntC += 1;
        else dp[x] = std::max(dp[x], cntC) + 1;
        
        ans = std::max(ans, dp[x] - cntC);
    }

    return std::cout << cntC + ans, 0;
}
