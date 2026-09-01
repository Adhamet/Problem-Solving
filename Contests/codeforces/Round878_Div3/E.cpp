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

    int T;  std::cin >> T;
    while (T--) {
        std::string a, b;
        std::cin >> a >> b;
        int n = (int)a.size();
        int t, q;   std::cin >> t >> q;

        int unequ = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) unequ++;
        }

        int timer = 0;
        std::vector<int> expire(n, -1);
        std::set<std::pair<int,int>> st;
        while (q--) {
            timer++;
            int type;   std::cin >> type;
            if (type == 1) {
                int pos; std::cin >> pos;
                pos--;

                if (expire[pos] != -1) st.erase({expire[pos], pos});
                expire[pos] = timer + t;
                st.insert({expire[pos], pos});

                // debug(a, b, unequ);
                if (a[pos] != b[pos]) unequ--;
                // debug(unequ);
            } else if (type == 2) {
                int str1, pos1, str2, pos2;
                std::cin >> str1 >> pos1 >> str2 >> pos2;
                pos1--, pos2--;

                std::string *pa = (str1 == 1? &a: &b);
                std::string *pb = (str2 == 1? &a: &b);

                bool state1 = false, state2 = false;
                if (a[pos1] == b[pos1]) state1 = true;
                if (a[pos2] == b[pos2]) state2 = true;

                std::swap((*pa)[pos1], (*pb)[pos2]);

                if (a[pos1] != b[pos1] && state1) unequ++;
                else if (a[pos1] == b[pos1] && !state1) unequ--;
                if (a[pos2] != b[pos2] && state2) unequ++;
                else if (a[pos2] == b[pos2] && !state2) unequ--;
            } else { // type == 3
                while (!st.empty()) {
                    auto it = st.begin();
                    if (it->first <= timer) {
                        int pos = it->second;
                        expire[pos] = -1;
                        st.erase(it);
                        if (a[pos] != b[pos]) unequ++;
                    } else break;
                }

                if (unequ == 0) std::cout << "YES\n";
                else std::cout << "NO\n";
            }
        }
    }

    return 0;
}
