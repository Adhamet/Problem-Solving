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
        int n, m, k;
        cin >> n >> m >> k;

        int a[n], b[n];

        for (int i = 0; i < n; i++) cin >> a[i];

        map<int, int> mp;
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            mp[b[i]]++;
        }

        int l = 0, r = 0, cnt = 0, ans = 0;
        map<int, int> toMatch;

        while (r < m) {
            if (toMatch[a[r]] < mp[a[r]]) cnt++;
            toMatch[a[r++]]++;
        }

        if (cnt >= k) ans++;

        while (r < n) {
            if (toMatch[a[r]] < mp[a[r]]) cnt += 1;
            toMatch[a[r]]++;
            toMatch[a[l]]--;

            if (toMatch[a[l]] < mp[a[l]]) {
                cnt--;
            }

            l++;

            if (cnt >= k) ans += 1;
            r += 1;
        }

        cout << ans << el;
    }

    return 0;
}
