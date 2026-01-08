#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) {
        int n, k; std::cin >> n >> k;
        std::set<int> st;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            mx = std::max(mx, x);
            st.insert(x);
        }

        int nn = (int)st.size();
        while (nn >= k) {
            st.erase(mx);
            mx -= 1;
            while (!st.count(mx)) mx -= 1;
            nn -= 1;
        }

        int mex = 0;
        std::unordered_map<int,bool> exist;
        for (auto x: st) {
            exist[x] = true;
            while (exist[mex]) mex++;
        }

        std::cout << mex << '\n';
    }

    return 0;
}
