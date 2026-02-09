#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;
        i64 x, y;
        std::cin >> n >> x >> y;

        i64 a[n];
        for (int i = 0; i < n; i++) std::cin >> a[i];

        i64 tot = 0;
        for (int i = 0; i < n; i++) tot += (a[i] / x);

        i64 ans = 0;
        for (int i = 0; i < n; i++) 
            ans = std::max(ans, a[i] + (tot-(a[i]/x)) * y);

        std::cout << ans << '\n';
    }

    return 0;
}
