#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    i64 n, k;   std::cin >> n >> k;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    i64 tot = std::accumulate(a.begin(), a.end(), 0LL);

    i64 l = 1, r = (i64)1e13, ans = 0;
    while (l <= r) {
        i64 md = (l + r) >> 1;
        if (k * md >= tot) ans = md, r = md - 1;
        else l = md + 1;
    }

    return std::cout << ans, 0;
}
