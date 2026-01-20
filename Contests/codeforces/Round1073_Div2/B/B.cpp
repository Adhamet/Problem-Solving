#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        std::sort(a.begin(), a.end());

        std::vector<int> prefMex(n), suffMex(n);

        std::vector<bool> seen(n+2, false);
        int curMex=0;
        for (int i = 0; i < n; i++) {
            seen[a[i]] = true;
            while (seen[curMex]) curMex++;
            prefMex[i] = curMex;
        }

        std::fill(seen.begin(), seen.end(), false);
        curMex = 0;
        for (int i = n-1; i>=0; i--) {
            seen[a[i]]= true;
            while (seen[curMex])curMex++;
            suffMex[i] = curMex;
        }

        bool acc = true;
        for (int i = 0; i < n-1; i++) {
            if (prefMex[i] == suffMex[i+1]) {
                acc = false;
                break;
            }
        }

        std::cout << (acc? "YES\n": "NO\n");
    }

    return 0;
}
