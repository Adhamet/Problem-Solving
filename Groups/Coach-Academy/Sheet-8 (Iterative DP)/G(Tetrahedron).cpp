#include <bits/stdc++.h>
 
using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'
const int N = 1e7+5, oo = 1e9+7, MOD=1e9+7;
int n;
int a[N],b[N],c[N],d[N];

int main()
{
    adhamet
    d[0]=1;
    cin >> n;
    
    for(int i = 1; i<=n; i++)
    {
        d[i] = ((ll)a[i-1] + b[i-1] + c[i-1])%MOD;
        a[i] = ((ll)b[i-1] + c[i-1] + d[i-1])%MOD;
        b[i] = ((ll)a[i-1] + c[i-1] + d[i-1])%MOD;
        c[i] = ((ll)a[i-1] + b[i-1] + d[i-1])%MOD;
    }
    cout << d[n] << el;
    return 0;
}
