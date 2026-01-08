#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) std::cin >> a[i];

        if ((a[0] == 1 || a[n-1] == 1)) {
            std::cout << "Alice\n";
        } else std::cout << "Bob\n";
    }

    return 0;
}
