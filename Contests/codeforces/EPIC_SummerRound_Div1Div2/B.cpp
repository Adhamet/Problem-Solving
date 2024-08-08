#include <bits/stdc++.h>
#include <tuple>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int t;  cin >> t;

    while(t--) {
        int n;  cin >> n;

        vi vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }

        vector<tuple<int,int,int>> fix;
        int l = 0, r = 1;
        while (l < r && l < n && r < n) {
            ll minDiff=1e9+7;
            if (vec[r] < vec[l]) {
                while (r < n && vec[r] < vec[l]) {
                    minDiff = min(minDiff, abs((ll)vec[r] - vec[l])); 
                    r++;
                }

                fix.push_back(make_tuple(l+1, r-1, minDiff));
                l = r - 1;
            } else {
                l++;
                r++;
            }
        }

        ll coins = 0;
        for (auto f: fix) {
            int lleft = get<0>(f), rright = get<1>(f), inc = get<2>(f);

            coins += inc;
            for (int i = lleft; i <= rright; i++) {
                vec[i] += inc;
            } 
        }
        cout << coins << el;
    }

    return 0;
}
