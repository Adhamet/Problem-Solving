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
        int n;
        cin >> n;

        int arr[n];
        for (auto &i: arr) cin >> i;

        int ans = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            ans = max(ans + 1, arr[i]);
        }

        cout << ans << el;
    }

    return 0;
}
