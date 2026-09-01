#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    i64 n,k;    std::cin >> n >> k;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i], a[i] -= k;

    std::map<int, int> firstOcc;
    firstOcc[0] = -1;

    int ans = 0;
    i64 sm = 0;
    for (int i = 0; i < n; i++) {
        sm += a[i];
        if (firstOcc.find(sm) != firstOcc.end()) {
            ans = std::max(ans, i - firstOcc[sm]);
        } else firstOcc[sm] = i;
    }

    return std::cout << ans, 0;
}
