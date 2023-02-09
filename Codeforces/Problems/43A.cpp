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
    string s;
    map<string,int> teams;

    int n;
    cin >> n;
    while(n--)
    {
        cin >> s;
        teams[s]++;
    }
    pair<string,int> maxTeam = {"zeby", 0};
    for(auto team: teams) if (team.second > maxTeam.second) 
    { 
        maxTeam.first = team.first; maxTeam.second = team.second; 
    }
    cout << maxTeam.first;
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