#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXN = 1e3+5;

i64 nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r > n - r) r = n - r;
    i64 res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * n / i;
        n--;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, k;   std::cin >> n >> k;
    int d[] = {1,0,1,2,9};

    i64 ans = 0;
    for (int i = 0; i <= k; i++) {
        ans += nCr(n, i) * d[i];
    } 

    return std::cout << ans, 0;
}
