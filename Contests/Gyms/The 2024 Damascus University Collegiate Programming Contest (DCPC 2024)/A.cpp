#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

struct SparseTableGCD {
    std::vector<std::vector<int>> st;

    inline int log2_floor(int i) {
        return i ? 31 - __builtin_clz(i): -1;
    }

    SparseTableGCD(const std::vector<int> &a) {
        int n = (int)a.size();
        st.assign(log2_floor(n) + 1, std::vector<int>(n)); // + !
        for (int i = 0; i < n; i++)
            st[0][i] = a[i];
        int k = log2_floor(n);
        for (int i = 1; i <= k; i++) // the equals?
            for (int j = 0; j + (1 << i) <= n; j++)
                st[i][j] = std::gcd(st[i-1][j], st[i-1][j + (1<<(i-1))]);
    }
    
    inline int query(int l, int r) {
        if (l > r) return 0;
        int i = log2_floor(r - l + 1);
        return std::gcd(st[i][l], st[i][r-(1<<i)+1]);
    }
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    
    SparseTableGCD spt(a);

    std::vector<int> prefGCD(n);
    prefGCD[0] = a[0];
    for (int i = 1; i < n; i++)
        prefGCD[i] = std::gcd(prefGCD[i-1], a[i]);

    std::vector<i64> summation(n);
    summation[0] = prefGCD[0];
    for (int i = 1; i < n; i++)
        summation[i] = summation[i-1] + prefGCD[i];

    auto calcRHS = [&](int idx) -> i64 {
        i64 rhs = 0;
        int curgcd = (idx>0? prefGCD[idx-1]: -1);
        if (curgcd == -1 && idx + 1 < n)
            curgcd = a[idx+1];
        if (curgcd == -1) return 0LL;

        int j = idx + 1;
        while (j < n) {
            int l = j, r = n - 1, k = j - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                int midgcd = spt.query(j, mid);
                if (curgcd == std::gcd(curgcd, midgcd)) k = mid, l = mid + 1;
                else r = mid - 1;
            }

            rhs += (k - j + 1) * (i64)curgcd;
            if (k + 1 < n) curgcd = std::gcd(curgcd, a[k + 1]);
            j = k + 1;
        }

        return rhs;
    };

    i64 ans = 0;
    for (int i = 0; i < n; i++) { // remove i
        i64 lhs = (i>0? summation[i-1]: 0);
        i64 rhs = calcRHS(i);
        ans = std::max(ans, lhs + rhs);
    }

    return std::cout << ans, 0;
}
