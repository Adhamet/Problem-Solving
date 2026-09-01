#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k;   std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];   
    for (int i = 0; i < n; i++) std::cin >> b[i];

    bool acc = true;
    std::multiset<int> desire, satisfy;
    for (int i = 0; i < n; i++) {
        if (satisfy.count(a[i])) satisfy.erase(satisfy.find(a[i]));
        else if (!satisfy.empty()  && *satisfy.begin() == -1) {
            satisfy.erase(satisfy.find(-1));
        } else desire.insert(a[i]);
        if (desire.count(b[i])) desire.erase(desire.find(b[i]));
        else satisfy.insert(b[i]);
        
        if (i >= k && (!desire.empty() || !satisfy.empty())) {
            while (!desire.empty() && !satisfy.empty() && *satisfy.begin() == -1) {
                desire.erase(desire.begin());
                satisfy.erase(satisfy.begin());
            }

            if (!desire.empty() || !satisfy.empty()) {
                acc = false;
                break;
            }
        }
    }

    std::cout << (acc? "YES": "NO") << '\n';
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    // -1 can be any element to be desired
    int t;  std::cin >> t;
    while (t--) solve();
    return 0;
}
