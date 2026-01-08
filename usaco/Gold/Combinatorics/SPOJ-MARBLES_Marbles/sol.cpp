#include <bits/stdc++.h>

using i64 = long long;

i64 nCr(int n, int r) {
    if (r > n - r) r = n - r;
    i64 ret = 1;
    for (int i = 0; i < r; i++)
        ret = ret * (n - i) / (i + 1);
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n, k;   std::cin >> n >> k;
        std::cout << nCr(n - 1, k - 1) << '\n';
    }

    return 0;
}
