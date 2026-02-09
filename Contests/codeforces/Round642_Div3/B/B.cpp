#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n, k;   std::cin >> n >> k;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        for (int i = 0; i < n; i++) std::cin >> b[i];
        std::sort(a.begin(), a.end());
        std::sort(b.rbegin(), b.rend());

        for (int i = 0; i < std::min(n,k); i++) {
            if (b[i] > a[i]) std::swap(a[i], b[i]);
            else break;
        }

        std::cout << std::accumulate(a.begin(), a.end(), 0LL) << '\n';
    }

    return 0;
}
