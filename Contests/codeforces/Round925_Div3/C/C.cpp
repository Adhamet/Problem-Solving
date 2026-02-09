#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        int lf = 1, cnt = 1;
        int x = a[0];
        while (lf < n && a[lf] == x) {
            cnt++;
            lf++;
        }
        int len1 = lf;

        int rg = n - 2;
        int x2 = a[n-1];
        while (rg >= 0 && a[rg] == x2) {
            cnt++;
            rg--;
        }
        int len2 = n - rg - 1;

        if (a[0] == a[n-1]) {
            int val = len1+len2;
            std::cout << n - (val > n? n: val) << '\n';
        } else {
            std::cout << std::min(n - len1, n - len2) << '\n';
        }
    }

    return 0;
}
