#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
 
void solve()
{
    int n,k;
    string arr[] = { "0","1","2","3","4","5","6","7","8","9" };
    cin >> n >> k;
    string s;
    bool flag;
    int cnt = 0;
    
    for(int i = 0; i < n; i++)
    {
        flag = false;
        cin >> s;
        for(int j = 0; j <= k; j++) if (s.find(arr[j]) == -1)
                { flag = true; break; }
        if(!flag) cnt++;
    }
    cout << cnt;
}
 
int main() 
{
    /*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
    #endif
    */
    
    adhamet;
    
    solve();
 
	return 0;
}