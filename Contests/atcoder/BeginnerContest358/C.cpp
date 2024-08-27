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

int n,m,ans=0;
vector<string> vecS;
void solve(int pos, int take, vector<bool> strAns) {
    if(pos == n) {
        for(int i = 0; i < m; i++) if(!strAns[i]) return;
        ans = min(ans, take);
        return;
    }

    solve(pos+1, take, strAns);
    vector<bool> newStrAns = strAns;
    for(int i = 0; i < m; i++) if(vecS[pos][i] == 'o') newStrAns[i]=true;
    solve(pos+1, take+1, newStrAns);
}

int main()
{
    adhamet;

    cin >> n >> m;
    vecS.resize(n);
    for(int i = 0; i < n; i++) cin >> vecS[i];

    ans = n;
    vector<bool> strAns(m,false);
    solve(0,0,strAns); 
    cout << ans;

    return 0;
}
