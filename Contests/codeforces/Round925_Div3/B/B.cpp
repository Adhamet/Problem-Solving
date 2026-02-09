#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<i64> a(n);
        i64 tot = 0;
        for (int i = 0; i < n; i++) std::cin >> a[i], tot += a[i];

        i64 avg = tot / n;
        i64 x = a[n-1];

        bool acc = true;
        i64 accu = 0;
        for (int i = n-1; i >= 0; i--) {
            accu += (a[i] - avg);
            if (accu > 0) {
                acc = false;
                break;
            }
        }

        std::cout << (acc? "YES": "NO") << '\n';
    }

    return 0;
}
