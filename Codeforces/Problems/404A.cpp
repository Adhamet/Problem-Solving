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
    int n;
    cin >> n;
    string s;
    set<char> x,y;

    for(int i = 0; i < n; i++)
    {
        cin >> s;
        for(int j = 0; j < n; j++) {
            if(i==j || i+j == n - 1)
                x.insert(s[j]);
            else
                y.insert(s[j]);
        }
    }

    if(x.size()==1 && y.size()==1 && *x.begin() != *y.begin()) cout << "YES";
    else cout << "NO";
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