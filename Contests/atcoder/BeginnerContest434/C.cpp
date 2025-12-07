#include <bits/stdc++.h>

using i64 = long long;

void solve() {
      int n;
      i64 f_curr;      std::cin >> n >> f_curr;
      i64 t[n], u[n], v[n];
      for (int i = 0; i < n; ++i) std::cin >> t[i] >> u[i] >> v[i];

      int i = 0;
      while (i < n) {
            int j = i;
            i64 curT = t[i];
            while (j < n && curT) {
                  if (j > i) curT += (t[j] - t[j-1] + 1);
                  // std::cout << "\nCurJ: " << j << '\n';
                  // std::cout << "CurT: " << curT << '\n';
                  // std::cout << "f_curr: " << f_curr << '\n';
                  // std::cout << "u[j] = " << u[j] << '\n';
                  // std::cout << "v[j] = " << v[j] << '\n';
                  i64 op1 = 0, op2 = 0;
                  while (j < n && f_curr >= u[j] && f_curr <= v[j]) {
                        j = j + 1;
                        curT += (t[j] - t[j-1] + 1);
                  }

                  op1 = std::abs(f_curr - u[j]);
                  op2 = std::abs(f_curr - v[j]);
                  if (!(std::min(op1,op2) <= curT)) return void(std::cout << "No\n");
                  if (op1 <= op2) {
                        i64 dir = (u[j] - f_curr);
                        if (dir > 0) {
                              if (u[j] - f_curr >= curT) f_curr += curT, curT = 0;
                              else curT -= std::abs(u[j] - f_curr), f_curr += (u[j] - f_curr);
                        } else {
                              if (u[j] - f_curr >= curT) f_curr -= curT, curT = 0;
                              else curT -= std::abs(u[j] - f_curr), f_curr -= (u[j] - f_curr);
                        }
                  } else {
                        i64 dir = (v[j] - f_curr);
                        if (dir > 0) {
                              if (v[j] - f_curr >= curT) f_curr += curT, curT = 0;
                              else curT -= std::abs(v[j] - f_curr), f_curr += (v[j] - f_curr);
                        } else {
                              if (v[j] - f_curr >= curT) f_curr -= curT, curT = 0;
                              else curT -= std::abs(v[j] - f_curr), f_curr -= (v[j] - f_curr);
                        }
                  }
                  j++;
                  // std::cout << "CURJ DONE.\n\n";
            }
            i = j;
      }

      std::cout << "Yes\n";
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
