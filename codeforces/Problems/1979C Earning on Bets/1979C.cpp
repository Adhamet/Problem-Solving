#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int t;  cin >> t;
    while(t--) {
        int n;  cin >> n;
        ll seq[n], LCR=1;
        for(int i = 0; i < n; i++) {
            cin >> seq[i];
            LCR = lcm(LCR, seq[i]);
        }

        ll ans[n], sum = 0;
        for(int i = 0; i < n; i++) {
            ans[i] = LCR/seq[i];
            sum += ans[i];
        }

        if(sum < LCR) {
            for(auto it: ans) cout << it << " ";
            cout << el;
        } else cout << -1 << el;
    }

    return 0;
}
