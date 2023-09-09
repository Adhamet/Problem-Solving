#include <bits/stdc++.h>
 
using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define ull unsigned long long
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'

const int N = 1e6+9;
int pre[N];

int main()
{
    adhamet

    int n,m,k,x;
    cin >> n >> m >> k;
    
    for(int i = 0; i < m; i++) cin >> x, pre[x]=1;

    int ans = 1;
    while( k-- ) {
        int u,v;
        cin >> u >> v;
        if(pre[ans]) break;
        else if (ans==u) ans = v;
        else if (ans==v) ans = u;
    }
    cout << ans << el;

    return 0;
}
