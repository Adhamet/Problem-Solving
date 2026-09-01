#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<i64> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        bool acc = false;
        for (int i = 0; i < (1<<n); i++) {
            i64 sm = 1;
            for (int j = 0; j < n; j++) {
                if (i & (1<<j)) {
                    sm *= a[j];
                }
            }

            if (sm == 67) {
                std::cout << "YES\n";
                acc = true;
                break;
            }
        }

        if (!acc) std::cout << "NO\n";
    }

    return 0;
}
