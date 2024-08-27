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

void solve()
{
    int n,m,rep=1;
    cin >> n >> m;

    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++)
        {
            if(i&1 && rep&1)
            {
                if(j != m-1) cout << '.';
                else { cout << '#'; rep++; }
            }
            else if(i&1)
            {
                if(j != 0) { cout << '.'; j == m-1? rep++: 0; }
                else cout << '#';
            }
            else cout << '#';
        }
        cout << endl;
    }
        
}

int main()
{
    adhamet

    solve();

    return 0;
}