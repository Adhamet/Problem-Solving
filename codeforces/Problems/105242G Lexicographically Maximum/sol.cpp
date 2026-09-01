#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

struct SparseTableMax {
    std::vector<std::vector<int>> st;

    inline int log2_floor(int i) {
        return i ? 31 - __builtin_clz(i): -1;
    };

    SparseTableMax(const std::string& s) {
        int n = (int)s.size();
        int k = log2_floor(n);
        st.assign(k + 1, std::vector<int>(n));
        for (int i = 0; i < n; i++)
            st[0][i] = s[i]-'a';
        for (int i = 1; i <= k; i++)
            for (int j = 0; j+(1<<i) <= n; j++)
                st[i][j] = std::max(st[i-1][j], st[i-1][j+(1<<(i-1))]);
    };

    inline int query(int l, int r) {
        if (l > r) return -1;
        int w = log2_floor(r - l + 1);
        return std::max(st[w][l], st[w][r - (1<<w) + 1]);
    }
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    std::string s;  std::cin >> s;
    int n = (int)s.size();

    SparseTableMax spt(s);

    std::vector pref(n+1, std::vector<int>(26));
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1];
        pref[i][s[i-1] - 'a']++;
    }

    std::vector<std::tuple<int,int,int>> change;

    int idx = 1;
    while (idx < n) {
        int distinct = 0;
        for (int i = 0; i < 26; i++) {
            int curOcc = pref[n][i] - pref[idx-1][i];
            if (curOcc) distinct++;
        }

        int target = distinct - 1;
        if (s[idx-1] - 'a' > target) {
            idx++;
            continue;
        } else if (s[idx-1] - 'a' == target) {
            int j = idx;
            while (j < n && s[j] == s[idx-1]) j++;
            if (j == n || s[j] - 'a' > target) {
                idx = j + 1; 
                continue;
            }
        }

        int l = idx, r = n, ans = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int distinctMid = 0;
            for (int i = 0; i < 26; i++) {
                int curOcc = pref[mid][i] - pref[idx-1][i];
                if (curOcc) distinctMid++;
            }

            if (distinctMid == distinct) ans = mid, r = mid-1;
            else l = mid + 1;
        }

        int start = std::max(0, ans);
        l = start, r = n - 1;
        int firstPos = -1, mx = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int curmx = spt.query(start, mid);
            if (curmx > distinct - 1) firstPos=mid, mx=curmx, r=mid-1;
            else l = mid + 1;
        }

        change.push_back({idx-1, (firstPos==-1? n-1: firstPos-1), distinct});
        idx = (firstPos==-1? n: firstPos+1);
        while (idx < n && s[idx-1]-'a' == mx) idx++;
    }

    std::string ans = s;
    for (auto [l, r, val]: change) {
        for (int i = l; i <= r; i++) ans[i] = ('a' + val - 1);
    }
    
    return std::cout << ans, 0;
}
