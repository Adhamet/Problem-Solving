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
        int a,b,c;  cin >> a >> b >> c;
        int mid = min(a,min(b,c));
        int smallestAns = 1e9;
        for(; mid <= max(a,max(b,c)); mid++) {
            smallestAns = min(smallestAns, abs(mid-a)+abs(mid-b)+abs(mid-c));
        }
        cout << smallestAns << el;
    }

    return 0;
}
