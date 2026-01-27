#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    
    i64 C[61][61];
    for (int i = 0; i <= 60; i++)
        for (int j = 0; j <= 60; j++)
            C[i][j] = 0;
    for (int i = 0; i <= 60; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    int t;  std::cin >> t;
    while (t--) {
        i64 n, k;   std::cin >> n >> k;

        if (k >= 60) {
            std::cout << 0 << '\n';
            continue;
        }

        i64 ans = 0;
        for (int len = 1; len <= 60; len++) {
            i64 mx = (1<<len) - 1;
            i64 s = (1LL << (len-1)), e = std::min(mx,n);
            if (s > n) break;

            int mnOnes = k - len + 2;
            if (mnOnes < 1) mnOnes = 1;
            if (mnOnes > len) continue;

            if (e == mx) {
                for (int ones = mnOnes; ones <= len; ones++)
                    ans += C[len-1][ones-1];
            } else {
                for (i64 x = s; x <= e; x++) {
                    int ones = __builtin_popcountll(x);
                    if (len + ones - 1 > k) ans++;
                }
            }
        }

        std::cout << ans << '\n';
    }
    

    return 0;
}
