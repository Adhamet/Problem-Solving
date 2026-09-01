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

    // c y n k u v a z
    // r x v c n v x r
    //
    // 1. cant have two different characters
    // pointing to the same one.
    // 2. if theres a repeat they have to lead
    // to the same character
    // 3. if the whole alphabet is there then
    // each x |-> y where x in s and y in t &
    //      y |-> x where y in s and x in t

    int t;  std::cin >> t;
    while (t--) {
        std::string s, t;   std::cin >> s >> t;
        int n = (int)s.size();

        bool acc = true;
        std::set<int> st;
        std::unordered_map<char,int> mp;
        std::unordered_map<char,int> rmp;
        for (int i = 0; i < n; i++) {
            if (!mp.count(s[i])) {
                st.insert(s[i]);
                mp[s[i]] = t[i];
                if (!rmp.count(t[i])) rmp[t[i]] = s[i];
                else {
                    acc = false;
                    break;
                }
            } else if (mp[s[i]] != t[i]) {
                acc = false;
                break;
            }
        }

        if (!acc) {
            std::cout << "NO\n";
            continue;
        }

        if ((int)st.size() == 26) {
            for (int i = 0; i < n; i++) {
                if (s[i] != mp[mp[s[i]]]) {
                    acc = false;
                    break;
                }
            }
        }

        std::cout << (acc? "YES\n": "NO\n");
    }

    return 0;
}
