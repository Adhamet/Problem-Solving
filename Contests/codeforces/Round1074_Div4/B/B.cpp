#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        i64 mx = *std::max_element(a.begin(), a.end());
        std::cout << mx * n << '\n';
    }

    return 0;
}
