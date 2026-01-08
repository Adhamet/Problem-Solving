#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    std::vector<int> pref(n+1, 0);
    for (int i = 2; i <= n; i++) {
        int num = i;
        while (num % 2 == 0) {
            num /= 2;
            pref[i]++;
        }
        pref[i] += pref[i-1];
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int x;  std::cin >> x;
        if (pref[n - 1] - pref[i] - pref[n - 1 - i] == 0)
            ans ^= x;
    }

    return std::cout << ans, 0;
}
