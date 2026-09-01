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
        int n, x, y;  std::cin >> n >> x >> y;
        std::deque<int> seg1, seg2, seg3;
        for (int i = 0; i < n; i++) {
            int input;  std::cin >> input;
            if (i < x) {
                seg1.push_back(input);
            } else if (i >= x && i < y) {
                seg2.push_back(input);
            } else {
                seg3.push_back(input);
            }
        }

        // work on seg2 first
        if (!seg2.empty()) {
            int mn = *std::min_element(seg2.begin(), seg2.end());
            while (seg2.front() != mn) {
                seg2.push_back(seg2.front());
                seg2.pop_front();
            }
        }

        std::deque<int> s;
        for (int v: seg1) s.push_back(v);
        for (int v: seg3) s.push_back(v);

        std::vector<int> ans;
        while (!s.empty() && !seg2.empty() && s.front() < seg2.front()) {
            ans.push_back(s.front());
            s.pop_front();
        }

        for (int v: seg2) ans.push_back(v);

        while (!s.empty()) {
            ans.push_back(s.front());
            s.pop_front();
        }

        for (int v: ans) std::cout << v << ' ';
        std::cout << '\n';
    }

    return 0;
}
