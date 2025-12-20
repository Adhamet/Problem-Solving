#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int h, w, n;    std::cin >> h >> w >> n;
    int a[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> a[i][j];
        }
    }

    std::set<int> st;
    for (int i = 0; i < n; i++) {
        int x;  std::cin >> x;
        st.insert(x);
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        int cnt = 0;
        for (int j = 0; j <  w; j++) {
            if (st.count(a[i][j])) cnt += 1;
        }
        ans = std::max(ans, cnt);
    }

    return std::cout << ans,0 ;
}
