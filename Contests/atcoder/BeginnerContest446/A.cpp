#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    std::string s;  std::cin >> s;
    s[0] = std::tolower(s[0]);
    std::cout << "Of" + s;

    return 0;
}
