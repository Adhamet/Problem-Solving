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

        vector<int> a(n), b(n);
        vector<pair<int, int>> mpA(n), mpB(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mpA[i] = make_pair(a[i], i);
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            mpB[i] = make_pair(b[i], i);
        }

        sort(begin(mpA), end(mpA));
        sort(begin(mpB), end(mpB));

        map<int, int> connect;
        for (int i = 0; i < n; i++) {
            connect[mpA[i].second] = mpB[i].second;
        }

        for (int i = 0; i < n; i++) {
            cout << b[connect[i]] << " ";
        }
        cout << el;
    }

    return 0;
}
