#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    std::string s;  std::cin >> s;
    std::cout << (s[0] == s[1] && s[1] == s[2]? "Yes": "No") << '\n';

    return 0;
}
