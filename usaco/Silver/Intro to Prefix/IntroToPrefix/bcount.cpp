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

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q;
    cin >> n >> q;

    vector<tuple<int, int, int>> pre(n + 1);
    
    get<0>(pre[0]) = 0, get<1>(pre[0]) = 0, get<2>(pre[0]) = 0;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        
        get<0>(pre[i]) = get<0>(pre[i - 1]);
        get<1>(pre[i]) = get<1>(pre[i - 1]);
        get<2>(pre[i]) = get<2>(pre[i - 1]);

        if (x == 1) get<0>(pre[i]) += 1;
        else if (x == 2) get<1>(pre[i]) += 1;
        else if (x == 3) get<2>(pre[i]) += 1;

    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        cout << get<0>(pre[r]) - get<0>(pre[l - 1]) << " ";
        cout << get<1>(pre[r]) - get<1>(pre[l - 1]) << " ";
        cout << get<2>(pre[r]) - get<2>(pre[l - 1]) << el;
    }

    return 0;
}
