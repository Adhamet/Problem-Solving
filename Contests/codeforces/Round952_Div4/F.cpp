#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define el '\n'
#define ll long long
#define pLL pair<ll,ll>
#define F first
#define S second
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int t;  cin >> t;
    while (t--) {
        ll h,n;  cin >> h >> n;
        set<pLL> st;
        vector<ll> dmg(n), cooldown(n);
        for (int i = 0; i < n; i++) cin >> dmg[i];
        for (int i = 0; i < n; i++) cin >> cooldown[i];
        for(int i = 0; i < n; i++) st.insert({1,i});

        ll turns = 1;
        while (h > 0) {
            ll attackIdx = (*st.begin()).S, attackTurn = (*st.begin()).F;

            st.erase(st.begin());

            turns = attackTurn;
            h -= dmg[attackIdx];

            st.insert({attackTurn+cooldown[attackIdx], attackIdx});
        }
        cout << turns << el;
    }

    return 0;
}
