#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, k;   std::cin >> n >> k;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int curSm = 0;
        int tmp = i;
        while (tmp > 0) {
            curSm += (tmp % 10);
            tmp /= 10;
        }
        if (curSm == k) ans++;
    }

    return std::cout << ans, 0;
}
