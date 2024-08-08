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

        if (n == 1) {
            cout << 0 << el;
            continue;
        }

        if (n <= k) {
            cout << 1 << el;
            continue;
        }


        int ans = 0;
        vector<int> nums;

        while (n > k && n % k != 0) {
            n -= k;

            if (n == 1 && k == 1) {
                ans += 1;
            } else if (n == 1) {
                    ans += 2;
            } else if (n <= k) {
                ans += 3;
            } else ans += 2;
        }

        if (n > 1 && n % k == 0) ans += k + 1;

        cout << ans << el;
    }

    return 0;
}
