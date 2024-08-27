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

        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        sort(begin(vec), end(vec));

        int left = k, lastTickets = 0;
        ll sum = 0;
        for (int i = 0; i < n && left > 0; i++) {
            sum += (ll)(vec[i]+lastTickets) * min(left, m);
            left -= m;
            lastTickets += m;
        }

        cout << sum << el;
    }

    return 0;
}
