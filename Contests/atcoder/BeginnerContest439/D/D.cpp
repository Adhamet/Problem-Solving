#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    i64 ans = 0;
    std::unordered_map<int,i64> freq;
    for (int i = 0; i < n; i++) {
        if (a[i] % 5 == 0) {
            int x = a[i] / 5;
            ans += (i64)freq[x*3] * freq[x*7];
        }
        freq[a[i]] += 1;
    }

    freq.clear();
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] % 5 == 0) {
            int x = a[i] / 5;
            ans += (i64)freq[x*3] * freq[x*7];
        }
        freq[a[i]] += 1;
    }

    return std::cout << ans, 0;
}
