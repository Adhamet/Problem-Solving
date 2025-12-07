#include <bits/stdc++.h>

using i64 = long long;

void solve() {
      int n;      std::cin >> n;
      if (n == 1) return void(std::cout << 1 << '\n');
      if (n == 2) return void(std::cout << 9 << '\n');
      i64 op1 = (n*n) + ((n*n) - 1) + ((n*n) - 2) + ((n*n) - n - 1);
      i64 op2 = ((n*n) - 1) + ((n*n) - n) + ((n*n) - n - 1) + ((n*n) - n - 2) + ((n*n) - 2*n - 1);
      std::cout << std::max(op1, op2) << '\n';
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
