#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    std::vector<std::pair<int,int>> a;
    for (int i = 0; i < n; i++) {
        int x;  std::cin >> x;
        a.push_back({x, i});
    }

    std::sort(a.begin(), a.end());
    for (int i = 0; i < 3; i++) {
        std::cout << a[i].second + 1 << ' ';
    }

    return 0;
}
