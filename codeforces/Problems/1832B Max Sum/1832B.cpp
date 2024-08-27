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

        vector<int> vec(n);
        for (auto &i: vec) cin >> i;

        sort(begin(vec), end(vec));

        ll currSum = 0;
        int l = 2 * k - 1, r = n;
        for (int i = l + 1; i < r; i++) currSum += vec[i];
        ll ans = currSum;

        l -= 2, r -= 1;
        while (l >= -1 && r >= 2) {
            currSum += vec[l + 1];
            currSum += vec[l + 2];
            currSum -= vec[r];

            ans = max(ans, currSum);
            
            l -= 2, r -= 1;
        }

        cout << ans << el;
    }

    return 0;

}
