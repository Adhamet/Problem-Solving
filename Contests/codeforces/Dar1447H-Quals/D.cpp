#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        i64 s;  std::cin >> s;

        if (s % 2 == 0) {
            if (s < 10) std::cout << "-1\n";
            else std::cout << 2 << ' ' << 3 << ' ' << s - 5 << '\n';
        } else {
            i64 a = 3, b = 4, c = s - 7;
            if (c % a == 0) b++, c--;
            if (c <= b) std::cout << -1 << '\n';
            else std::cout << a << ' ' << b << ' ' << c << '\n';
        }
    }

    return 0;
}

