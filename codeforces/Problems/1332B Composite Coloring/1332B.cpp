#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        int m = 0;
        vector<int> ans(n, 0);
        for (int p : primes) {
            bool ok = false;
            for (int i = 0; i < n; i++) {
                if (!ans[i] && a[i] % p == 0) {
                    ans[i] = m + 1;
                    ok = true;
                }
            }

            if (ok) m += 1;
        }

        cout << m << el;
        for (int i = 0; i < n; ++i) cout << ans[i] << " ";
		cout << el;
    }

    return 0;
}

