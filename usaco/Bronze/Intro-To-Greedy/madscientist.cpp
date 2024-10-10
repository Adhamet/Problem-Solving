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

void setIO(string name = "") {
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);    
    }
}

int main()
{
    setIO("breedflip");
    adhamet;

 	ll n;   cin >> n;
    string A, B;    cin >> A >> B;
    ll ans = 0;
    bool mismatch=false;
    for(ll i = 0; i < n; i++) {
        if(A[i]!=B[i]) {
            if(!mismatch) mismatch=true, ans++;
        } else mismatch = false;
    }
    cout << ans << el;

    return 0;
}
