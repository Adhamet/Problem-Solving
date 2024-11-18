#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int> a(k);
		for (auto &i: a) cin >> i;

		k -= 2;
        pair<int, int> res = {1, k};
        for (int i = 1; i * i <= k; ++i) {
            if (k % i == 0) {
                int n = i;
                int m = k / i;

                if (find(a.begin(), a.end(), n) != a.end() &&
                    find(a.begin(), a.end(), m) != a.end()) {
                    res = {n, m};
                    break;
                }

                if (find(a.begin(), a.end(), m) != a.end() &&
                    find(a.begin(), a.end(), n) != a.end()) {
                    res = {m, n};
                    break;
                }
            }
        }

        cout << res.first << " " << res.second << el;
    }

    return 0;
}

