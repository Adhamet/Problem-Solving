#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, x, y;    std::cin >> n >> x >> y;
    std::string s;  std::cin >> s;
    int itr = n - 1;
    int ans = 0;
    while (y) {
        if (s[itr] != '0') ans++;
        y--;
        x--;
        itr--;
    }
    if (s[itr] != '1') ans++;
    x--;
    itr--;
    while (x) {
        if (s[itr] != '0') ans++;
        x--;
        itr--;
    }

    return std::cout << ans, 0;
}
