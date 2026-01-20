#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int q; std::cin >> q;
    while (q--) {
        int n;  std::cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) std::cin >> a[i];
        std::sort(a, a+n);
        bool yeye = false;
        for (int i = 0; i < n-1; i++) {
            if (std::abs(a[i]-a[i+1]) == 1) {
                yeye = true;
            }
        }
        std::cout << (yeye? 2: 1) << '\n';
    }

    return 0;
}
