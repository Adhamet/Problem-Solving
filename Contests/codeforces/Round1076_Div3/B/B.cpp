#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        std::vector<std::pair<int,int>> suffMx(n);
        suffMx[n-1].first = a[n-1], suffMx[n-1].second = n-1;
        for (int i = n-2; i >= 0; i--) {
            suffMx[i] = suffMx[i+1];
            if (suffMx[i].first < a[i]) {
                suffMx[i].first = a[i];
                suffMx[i].second = i;
            }
        }

        int l = -1, r = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] < suffMx[i].first) {
                l = i, r = suffMx[i].second;
                break;
            }
        }

        if (l == -1) {
            for (auto x: a) std::cout << x << ' ';
            std::cout << '\n';
            continue;
        }

        std::vector<int> ans = a;
        std::reverse(ans.begin() + l, ans.begin() + r + 1);
        for (auto x: ans) std::cout << x << ' ';
        std::cout << '\n';
    }

    return 0;
}
