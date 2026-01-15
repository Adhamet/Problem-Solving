#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) std::cin >> a[i];

    int ans = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            i64 sm = 0;
            for (int i = l; i <= r; i++) sm += a[i];

            bool acc = true;
            for (int i = l; i <= r; i++) {
                if (sm % a[i] == 0) {
                    acc = false;
                    break;
                }
            }

            if (acc) ans += 1;
        }
    }

    return std::cout << ans, 0;
}
