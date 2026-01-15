#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        i64 s,k,m; std::cin >> s >> k >> m;
        if (s < k) {
            // int fallStart = 0;
            // int fallEnd = s-1;
            // int nothingStart = s;
            // int nothingEnd = k;
            m %= k;
            if (m >= s) std::cout << 0 << '\n';
            else std::cout << s - m << '\n';
        } else if (s == k) {
            m %= k;
            std::cout << s - m << '\n';
        } else { // s > k
            i64 flips = m/k, rem = m%k;
            if (flips&1) std::cout << k - rem << '\n';
            else std::cout << s - rem << '\n';
        }
    }

    return 0;
}
