#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<std::pair<int,int>> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i].first;
            if (i&1) a[i].second = 1;
            else a[i].second = 0;
        }
        
        std::sort(a.begin(), a.end(), [](auto x, auto y) {
            return x.first < y.first;
        });
        
        bool acc = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i].second == a[i+1].second) {
                acc = false;
            }
        }

        std::cout << (acc? "YES\n": "NO\n");
    }

    return 0;
}
