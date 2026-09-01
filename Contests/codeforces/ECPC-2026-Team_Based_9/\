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

    int t;  std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;

        std::map<std::string, int> mj = {
            {"1p", 0},{"2p", 0},{"3p", 0},{"4p", 0},{"5p", 0},{"6p", 0},{"7p", 0},{"8p", 0},{"9p", 0},
            {"1s", 0},{"2s", 0},{"3s", 0},{"4s", 0},{"5s", 0},{"6s", 0},{"7s", 0},{"8s", 0},{"9s", 0},
            {"1m", 0},{"2m", 0},{"3m", 0},{"4m", 0},{"5m", 0},{"6m", 0},{"7m", 0},{"8m", 0},{"9m", 0},
            {"1z", 0},{"2z", 0},{"3z", 0},{"4z", 0},{"5z", 0},{"6z", 0},{"7z", 0}
        };

        for (int i = 0; i < 28 - 1; i+=2) {
            std::string cur = s.substr(i, 2);
            mj[cur] += 1;
        }

        if (mj["1p"] && mj["9p"] && mj["1s"] && mj["9s"] && mj["1m"] && mj["9m"] &&
            mj["1z"] && mj["2z"] && mj["3z"] && mj["4z"] && mj["5z"] && mj["6z"] && mj["7z"]) {
            std::cout << "Thirteen Orphans\n";
        } else {
            int cnt = 0;
            for (auto [_, val]: mj) if (val == 2) cnt++;
            
            if (cnt == 7) std::cout << "7 Pairs\n";
            else std:: cout << "Otherwise\n";
        }
    }

    return 0;
}
