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
    adhamet;    cout.precision(10); cout.setf(ios::fixed);

    int t;  cin >> t;
    while(t--) {
        int n,d,h;  cin >> n >> d >> h;
        vi y(n);    for(int i = 0; i < n; i++) cin >> y[i];
        long double ans = (long double)d*h/2.0;
        for(int i = 0; i < n-1; i++) {
            if(y[i+1] >= y[i]+h) ans+= (long double)d*h/2.0;
            else {
                long double d2 = (long double)d * (y[i]+h-y[i+1])/h;
                long double nh = y[i+1]-y[i];
                ans+=(d+d2)/2.0*nh;
            }
        }
        cout << ans << el;
    }

    return 0;
}
