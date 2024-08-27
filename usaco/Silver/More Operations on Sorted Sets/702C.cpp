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

int main()
{
    adhamet;

    int n,m,j=0;    cin >> n >> m;
    vll city(n);    for(int i = 0; i < n; i++) cin >> city[i];
    vll cell(m); for(int i = 0; i < m; i++) cin >> cell[i];

    vll d(n);
    for(int i = 0; i < n; i++) {
        while(abs(city[i]-cell[j]) >= abs(city[i]-cell[j+1]) && j < m) j++;
        d[i] = abs(city[i]-cell[j]);
    } sort(d.begin(), d.end());
    cout << d[n-1];

    return 0;
}
