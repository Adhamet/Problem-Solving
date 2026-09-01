#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    char a[n][n];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
            if (a[i][j] == 'P' || a[i][j] == 'p') {
                ans++;
            }
        }
    }
    return std::cout << ans, 0;
}
