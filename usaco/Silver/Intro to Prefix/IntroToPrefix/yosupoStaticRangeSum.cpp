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

    int n, q;
    cin >> n >> q;

    int pre[n];
    cin >> pre[0];

    for (int i = 1; i < n; i++) {
        int num;
        cin >> num;

        pre[i] = pre[i - 1] + num;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        if (l == 0) cout << pre[r - 1] << el;
        else cout << pre[r - 1] - pre[l - 1] << el;
    }

    return 0;
}
