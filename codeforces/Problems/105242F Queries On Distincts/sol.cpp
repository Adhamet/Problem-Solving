#include <bits/stdc++.h>

// -- Don't use with doubles -----------
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
// -------------------------------------
#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

const int INF = 1e9;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    std::string s;  std::cin >> s;

    std::vector pref(n+1, std::vector<int>(26, 0));
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1];
        pref[i][s[i-1] - 'a']++;
    }

    std::vector nxtR(27, std::vector<int>(n, INF));
    std::vector mnLen(27, std::vector<int>(n, INF));

    for (int x = 1; x <= 26; x++) {
        int r = 0, curdistinct = 0;
        std::vector<int> cnt(26, 0);

        for (int l = 0; l < n; l++) {
            while (r < n && curdistinct < x) {
                if (cnt[s[r] - 'a'] == 0) curdistinct++;
                cnt[s[r] - 'a']++;
                r++;
            }

            if (curdistinct == x) {
                nxtR[x][l] = r - 1;
                mnLen[x][l] = r - l;
            }
            
            cnt[s[l] - 'a']--;
            if (cnt[s[l] - 'a'] == 0) curdistinct--;
        }
    }


    int LOG = 32 - __builtin_clz(n);
    std::vector spt(27, std::vector(LOG, std::vector<int>(n, INF)));
    for (int x = 1; x <= 26; x++) {
        for (int i = 0; i < n; i++) 
            spt[x][0][i] = mnLen[x][i];
        for (int j = 1; j <= LOG; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                spt[x][j][i] = std::min(spt[x][j-1][i], spt[x][j-1][i + (1 << (j-1))]);
    }
    auto querySpt = [&](int x, int L, int R) {
        if (L > R) return INF;
        int j = 31 - __builtin_clz(R - L + 1);
        return std::min(spt[x][j][L], spt[x][j][R - (1 << j) + 1]);
    };


    int q;  std::cin >> q;
    while (q--) {
        int L, R;   std::cin >> L >> R;
        L--; R--;

        int distinct = 0;
        for (int i = 0; i < 26; i++) {
            int val = pref[R+1][i] - pref[L][i];
            if (val) distinct++;
        }

        int ll = L, rr = R, ansL = L - 1;
        while (ll <= rr) {
            int mid = (ll + rr) >> 1;
            if (nxtR[distinct][mid] <= R) {
                ansL = mid;
                ll = mid + 1;
            } else {
                rr = mid - 1;
            }
        }

        std::cout << querySpt(distinct, L, ansL) << '\n';
    }

    return 0;
}
