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
        int n,k;    cin >> n >> k;
        vector<int> a(n),b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        int total = a[0];
        int bbest = b[0];
        int mx = total + (bbest * (k-1));
        for(int i = 1; i < min(n,k); i++) {
            bbest = max(bbest, b[i]);
            if(mx < total+a[i]+(bbest*(k-i-1)))
                mx = total+a[i]+(bbest*(k-i-1));
            total+=a[i];
        }
        cout << mx << el;
    }

    return 0;
}
