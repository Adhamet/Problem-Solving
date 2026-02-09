#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<int> a(n);
        std::iota(a.begin(), a.end(), 1);
        std::reverse(a.begin(), a.end());
        if (n & 1) std::swap(a[n/2], a[0]);
        for (auto x: a) std::cout << x << ' ';
        std::cout << '\n';
    }

    return 0;
}

