#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::unordered_map<std::string, std::pair<int,int>> mp;

    std::cin.ignore();
    for (int i = 0; i < 3*n; i++) {
        std::string s;
        std::getline(std::cin, s);
        mp[s].first += 1;
        mp[s].second = i;
    }

    std::vector<std::pair<std::string, std::array<int, 2>>> vec;
    for (auto [str, x]: mp) {
        vec.push_back({str, {x.first, x.second}});
    }

    std::sort(vec.begin(), vec.end(), [](auto x, auto y) {
        if (x.second[0] != y.second[0]) return x.second[0] > y.second[0];
        return x.second[1] > y.second[1];
    });

    int sz = std::min(k, (int)vec.size());
    for (int i = 0; i < sz; i++) {
        std::cout << vec[i].first << '\n';
    }

    return 0;
}
