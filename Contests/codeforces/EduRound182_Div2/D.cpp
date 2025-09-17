#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int t;	std::cin >> t;
    while (t--) {
        int n, mxPrice = 0;
        i64 y;
        std::cin >> n >> y;
        
	  std::vector<int> c(n);
        std::map<int,int> freq;
        for (int i = 0; i < n; i++) {
            std::cin >> c[i];
            freq[c[i]]++;
            mxPrice = std::max(mxPrice, c[i]);
        }

        i64 ans = LLONG_MIN;
        for (int x = 2; x <= mxPrice; x++) {
            std::map<int,int> used;
            i64 tot = 0, reused = 0;

            for (int i = 0; i < n; i++) {
                int newPrice = (c[i] + x - 1) / x;
                tot += newPrice;
                if (freq[newPrice] - used[newPrice] > 0) {
                    reused++;
                    used[newPrice]++;
                }
            }

            ans = std::max(ans, tot - y * (n - reused));
        }

        i64 tot = n;
        i64 reused = std::min((i64)freq[1], (i64)n);
        ans = std::max(ans, tot - y * (n - reused));

        std::cout << ans << "\n";
    }

    return 0;
}

