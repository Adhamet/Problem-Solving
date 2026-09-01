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

    int n;  std::cin >> n;

    i64 ans = 0;
    // Case 1:
    for (int i = 1; i <= n; i++) {
        std::string cur = std::to_string(i);
        for (int j = 0; j < cur.size() - 1; j++) {
            if (cur[j] == '4' && cur[j+1] == '2') {
                ans += 1;
            }
        }
    }
        
    // Case 2: (2x4 2x5)
    if (25 <= n) ans++;
    for (int i = 0; i < 10; i++) {
        std::string cur = "2";
        cur.push_back(i + '0');
        cur.push_back('5');

        int val = std::stoi(cur);
        if (val <= n) ans += 1;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::string cur = "2";
            cur.push_back(i + '0');
            cur.push_back(j + '0');
            cur.push_back('5');

            int val = std::stoi(cur);
            if (val <= n) ans += 1;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                std::string cur = "2";
                cur.push_back(i + '0');
                cur.push_back(j + '0');
                cur.push_back(k + '0');
                cur.push_back('5');

                int val = std::stoi(cur);
                if (val <= n) ans += 1;
            }
        }
    }

    return std::cout << ans, 0;
}
