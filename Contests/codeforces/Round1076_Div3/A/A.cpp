#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n, s, x;    std::cin >> n >> s >> x;
        int a[n];
        int sum = 0;
        for (int i = 0; i < n; i++) std::cin >> a[i], sum+=a[i];

        bool acc = false;
        while (sum <= s) {
            if (sum == s) {
                acc = true;
                break;
            } else sum += x;
        }

        std::cout << (acc? "YES\n": "NO\n");
    }

    return 0;
}
