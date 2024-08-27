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
        ll l;
        cin >> n >> l;

        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i].F >> vec[i].S;
        }

        
        sort(begin(vec), end(vec), [&](pi a, pi b) {
            return a.S < b.S;
        });

        
        int finalAns = 0;
        for (int startingPt = 0; startingPt < n; startingPt++) {
            multiset<ll> ms;

            ll totalSum = 0;

            for (int i = startingPt; i < n; i++) {
                if (i == startingPt) totalSum += vec[i].F;
                else totalSum += vec[i].F + abs(vec[i].S - vec[i - 1].S);
                
                ms.insert(vec[i].F);
    
                while (!ms.empty() && totalSum > l) {
                    auto itr = prev(ms.end());

                    totalSum -= (*itr);

                    ms.erase(itr);
                }

                finalAns = max(finalAns, (int)ms.size());
            }
        }

        cout << finalAns << el;
    }

    return 0;
}
