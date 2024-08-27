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

    int n,a;    cin >> n >> a;
    vector<pair<int,int>> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i].F;
    vec[0].S = vec[0].F + a;
    cout << vec[0].S;
    for(int i = 1; i < n; i++) {
        if(vec[i].F < vec[i-1].S) vec[i].S = vec[i-1].S + a;
        else vec[i].S = vec[i].F + a;
        cout << el << vec[i].S;
    }

    return 0;
}
