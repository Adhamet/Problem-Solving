#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 20 + 5;
// const int oo = 1e9 + 20;

int main()	{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (auto &i: a) cin >> i;
    
        if (a.front() == a.back()) {
            int cnt = 0;

            for (int i = 0; i < n; i++) if (a[i] == a[0]) {
                cnt += 1;
            } 

            if (cnt >= k) cout << "YES\n";
            else cout << "NO\n";

            continue;
        }

        int l = 0, r = n - 1, x = 0, y = 0;

        while (x < k && l < n) {
            if (a[l] == a[0]) x += 1;
            l += 1;
        }

        while (y < k && r >= 0) {
            if (a[r] == a[n - 1]) y += 1;
            r--;
        }

        if (x == k && y == k && l - 1 < r + 1) cout << "YES" << el;
        else cout << "NO" << el;
    }

    return 0;
}
