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

        vector<int> vec(n);
        map<int, int> rep;
        for (auto &i: vec) {
            cin >> i;

            rep[i] += 1;
        }

        bool acc = false;
        for (auto ele: rep) {
            if(ele.second % 2 != 0) {
                acc = true;
            }
        }

        if (acc) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
