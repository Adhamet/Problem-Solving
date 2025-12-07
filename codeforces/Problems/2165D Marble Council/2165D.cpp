#include <bits/stdc++.h>

using i64 = long long;

void solve() {
      constexpr int MOD = 998244353;
      int n, mxCnt = 0;      std::cin >> n;
      std::map<int,int> cnt;
      for (int i = 0; i < n; ++i) {
            int x;      std::cin >> x;
            cnt[x]++;
            mxCnt = std::max(mxCnt, cnt[x]);
      }

      i64 someDp[n+1];
      i64 *dp = someDp;
      std::fill(dp, dp+n+1, 0);
      dp[0] = 1;
      for (auto [x, c]: cnt) {
            for (int j = n; j >= c; --j) {
                  dp[j] = (dp[j] + 1LL * c * dp[j - c]) % MOD;
            }
      }

      i64 ans = 0;
      for (int i = mxCnt; i <= n; ++i) ans = (ans + dp[i]) % MOD;
      std::cout << ans << '\n';
}

int main() {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
      
      int t;      std::cin >> t;
      while (t--) {
            solve();
      }
      
      return 0;
}
