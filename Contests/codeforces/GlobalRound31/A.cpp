#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

void solve() {
    int l, a, b;
    std::cin >> l >> a >> b;

    int mx = 0;
    std::set<int> st;
    a %= l;
    mx = std::max(mx, a);
    st.insert(a);
    a = (a + b) % l;
    while (!st.count(a)) {
        mx = std::max(mx, a);
        st.insert(a);
        a = (a + b) % l;
    }

    std::cout << mx << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
