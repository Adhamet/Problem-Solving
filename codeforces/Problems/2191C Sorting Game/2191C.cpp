#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<int> a(n);
        std::string s;  std::cin >> s;
        for (int i = 0; i < n; i++) {
            a[i] = s[i]-'0';
        }

        std::string t = s;
        std::sort(t.begin(), t.end());
        if (s == t) {
            std::cout << "Bob\n";
            continue;
        } else {
            std::cout << "Alice\n";

            std::vector<std::pair<int,int>> dp;
            for (int i = 0; i < n; i++) {
                auto it = std::upper_bound(dp.begin(), dp.end(), -a[i]);
                if (it == dp.end()) dp.push_back({-a[i], i+1});
                else *it = {-a[i], i+1};
            }

            std::cout << (int)dp.size() << '\n';
            for (auto [_, x]: dp) std::cout << x << ' ';
            std::cout << '\n';
        }
    
    }

    return 0;
}
