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

    int t;  cin >> t;
    while(t--) {
        int x1,y1,x2,y2;    cin >> x1 >> y1 >> x2 >> y2;
        if(x1<y1 && x2>=y1 && y2<=x2 || y1<x1 && y2>=x1 && x2<=y2) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
