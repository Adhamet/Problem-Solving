#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);


    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<i64> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        std::sort(a.begin(), a.end());

        i64 x = a[0] * a[n-1];
        bool acc = true;
        for (int i = 0; i < n; i++) if (a[i] * a[n-i-1] != x) {
            acc = false; // x=pq*r;
            break;
        }

        if (!acc) {
            std::cout << -1 << '\n';
            continue;
        }

        std::vector<i64> divs;
        for (i64 i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                divs.push_back(i);
                if (i != x/i) divs.push_back(x/i);
            }
        }
        std::sort(divs.begin(), divs.end());

        if ((int)divs.size() != n) {
            std::cout << -1 << '\n';
            continue;
        } else {
            for (int i = 0; i < n; i++) if (divs[i] != a[i]) {
                acc = false;
                break;
            }
        }

        std::cout << (acc? x: -1) << '\n';
    }

    return 0;
}

