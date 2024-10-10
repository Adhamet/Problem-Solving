#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

void solve() {
    int n;  cin >> n;
    vll hunger(n+1);
    for(int i = 1; i <= n; i++) cin >> hunger[i];
    ll bags=0;
    for(int i = 1; i < n; i++) {
        if(hunger[i+1]>hunger[i]) {
            if(i+2>n) {
                cout << -1 << el;
                return;
            }

            ll diff=hunger[i+1] - hunger[i];
            hunger[i+1] -= diff;    hunger[i+2] -= diff;
            if(hunger[i+2]<0) {
                cout << -1 << el;
                return;
            }
            bags+=diff*2;
        } else if(hunger[i]>hunger[i+1]) {
            if(i%2==1) {
                cout << -1 << el;
                return;
            }

            ll diff=hunger[i]-hunger[i+1];
            bags+=diff*i;
        }
    }
    cout<<bags<<el;
}

int main()
{
    adhamet;

    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
