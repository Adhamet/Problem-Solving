#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

constexpr int MXN = (int)5e5+5;

int lst[MXN];
std::vector<int> seg[MXN];

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, c;   std::cin >> n >> c;
    std::vector<int> a(n);
    std::unordered_set<int> ust;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        ust.insert(a[i]);
        lst[a[i]] = -1;
    }

    std::vector<int> cnt2Pref(n);    cnt2Pref[0] = ((i64)a[0] == c);
    for (int i = 1; i < n; i++) {
        cnt2Pref[i] = cnt2Pref[i-1] + (a[i] == c);
    }

    for (auto x: ust) {
        if (x == c) continue;
        seg[x].push_back(1);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == c) continue;
        int x = a[i];
        if (lst[x] == -1) {
            lst[x] = i; 
            continue;
        } else if (i - 1 < 0) continue;

        seg[x].push_back(-(cnt2Pref[i-1] - cnt2Pref[lst[x]]));
        seg[x].push_back(1);
        lst[x] = i;
    }

    int ans = 0;
    for (auto x: ust) {
        int curV = 0, curA = 0;
        for (auto v: seg[x]) {
            curV = std::max(0, curV + v);
            curA = std::max(curA, curV);
        }
        ans = std::max(ans, curA);
    }

    return std::cout << cnt2Pref[n-1] + ans, 0;
}
