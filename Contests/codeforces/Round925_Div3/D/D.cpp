#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n, x, y;    std::cin >> n >> x >> y;

        std::vector<int> a(n);
        std::vector<std::pair<int,int>> vec(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            vec[i] = {a[i] % x, a[i] % y};
        }

        i64 ans = 0;
        std::map<std::pair<int,int>, int> cnt;
        for (int i = 0; i < n; i++) {
            int r1 = (x - (a[i] % x)) % x;
            int r2 = a[i] % y;
            ans += cnt[{r1, r2}];
            cnt[vec[i]]++;
        }

        std::cout << ans << '\n';
    }

    return 0;
}

