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
        for (auto &i: vec) cin >> i;
        

        int MEX = 0;
        set<int> mexDealer(vec.begin(), vec.end());

        for (auto ele: mexDealer) {
            if (ele == MEX) MEX += 1;
            else break;
        }
        
        vector<pair<int, int>> ans;
        
        int l = 0, r = 0;
        mexDealer.clear();

        while (r < n && l <= r) {
            if (vec[r] < MEX) {
                mexDealer.insert(vec[r]);
            }

            if (mexDealer.size() == MEX) {
                ans.push_back({l, r});

                mexDealer.clear();
                l = r + 1;
            }

            r += 1;
        }

        if (ans.size() == 1) {
            cout << -1 << el;
        } else {
            cout << ans.size() << el;

            for (auto pr = ans.begin(); pr != ans.end(); pr++) {
                cout << pr->first + 1 << " " << (next(pr) == ans.end() ? n: pr->second + 1);
                cout << el;
            }
        }
    }

    return 0;
}
