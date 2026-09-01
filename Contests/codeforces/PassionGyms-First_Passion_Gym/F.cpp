#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    std::vector<std::array<i64, 2>> pizzas(n);
    for (int i = 0; i < n; i++) {
        i64 s, q, c, v;
        std::cin >> s >> q >> c >> v;
        if (q <= c) pizzas[i][0] = q*s;
        else pizzas[i][0] = q*std::min(2LL,s)+c*std::max(s-2,0LL);
        pizzas[i][1] = v;
    }

    std::sort(pizzas.begin(), pizzas.end(), [](auto a, auto b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    i64 ans = 0;
    int time = 0, i = 0;
    while (i < n) {
        // debug(pizzas, time);
        if (time < pizzas[i][0]) {
            time++;
        } else ans += pizzas[i][1];
        i++;
    }

    return std::cout << ans, 0;
}
