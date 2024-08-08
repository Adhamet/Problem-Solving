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

        int minEle = 1e9, evenCnt = 0, oddCnt = 0;
        vector<int> a(n);
        for (auto &i: a) {
            cin >> i;

            if (i % 2 == 0) evenCnt += 1;
            else oddCnt += 1;

            minEle = min(minEle, i);
        }

        if (evenCnt == n || oddCnt == n || minEle % 2 == 1) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
