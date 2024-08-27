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

    while(t--) {
        int n;
        cin >> n;

        int a[n];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        if (n == 2) {
            cout << min(a[1], a[2]) << el;
        } else {
            int ans = min(a[1], a[2]);

            for (int i = 1; i <= n-2; i++) {
                vector<int> tmp;

                for (int k = 0; k <= 2; k++) {
                    tmp.push_back(a[i+k]);
                }

                sort(tmp.begin(), tmp.end());
                ans = max(ans, tmp[1]);
            }

            cout << ans << el;
        }
    }

    return 0;
}
