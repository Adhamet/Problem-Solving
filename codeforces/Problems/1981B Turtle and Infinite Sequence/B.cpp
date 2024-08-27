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
        ll n, m;
        cin >> n >> m;

        ll L = max(0LL, n - m), R = n + m, ans = 0;

        for (int i = 31; ~i; i--) {
            if ((L & (1LL << i)) || (R & (1LL << i)) || (L >> (i + 1)) != (R >> (i + 1))) {
                ans |= (1LL << i);
            }
        }

        cout << ans << el;
    }

    return 0;
}
