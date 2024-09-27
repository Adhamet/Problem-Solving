#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a.begin() + 1, a.begin() + n + 1);

        if (k >= 3) {
            cout << "0\n";
        } else if (k == 1) {
            ll mn = a[1];
            for (int i = 1; i < n; ++i) 
                mn = min(mn, a[i + 1] - a[i]);
            cout << mn << '\n';
        } else {
            ll mn = a[1];
            for (int i = 1; i < n; ++i) mn = min(mn, a[i + 1] - a[i]);

            for (int i = 1; i <= n; ++i) {
                for (int j = i + 1; j <= n; ++j) {
                    ll curr = a[j] - a[i];
                    int idx = lower_bound(a.begin() + 1, a.begin() + n + 1, curr) - a.begin();
                    if (idx <= n) mn = min(mn, a[idx] - curr);
                    if (idx > 1) mn = min(mn, curr - a[idx - 1]);
                }
            }

            cout << mn << '\n';
        }
    }

    return 0;
}
