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
    std::string s;  std::cin >> s;

    std::vector<std::vector<int>> pref(n, std::vector<int>(27));
    pref[0][s[0] - 'a']++;
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1];
        pref[i][s[i] - 'a']++;
    }

    int q;  std::cin >> q;
    while (q--) {
        int l, r;   std::cin >> l >> r;
        l--, r--;

        std::vector<std::pair<int,int>> cnt;
        for (int i = 0; i < 26; i++) {
            int curCnt = pref[r][i] - (l > 0 ? pref[l - 1][i] : 0);
            if (curCnt) cnt.push_back({curCnt, i});
        }
        std::sort(cnt.rbegin(), cnt.rend());
        int m = (int)cnt.size();

        bool done = false;

        int curLen = 0;
        for (int i = 0; i < m; i++) {
            curLen += cnt[i].first;
            
            if (i + 1 == m || cnt[i].first != cnt[i + 1].first) {
                int ll = r - curLen;
                int curCnt = 0;
                
                for (int j = 0; j <= i; j++) {
                    int ch = cnt[j].second;
                    curCnt += pref[r][ch] - (ll >= 0 ? pref[ll][ch] : 0);
                }
                
                if (curCnt != curLen) {
                    done = true;
                    break;
                }
            }
        }

        std::cout << (done ? "YES\n" : "NO\n");
    }

    return 0;
}
