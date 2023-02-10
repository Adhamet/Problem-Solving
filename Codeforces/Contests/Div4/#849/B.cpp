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
    int moves;
    char move;
    bool flag = 0;
    cin >> moves;
    pair<int,int> co = {0,0}, candy = {1,1};
    for(int i = 0; i < moves; i++)
    {
        cin >> move;
        if(flag) continue;
        if(move == 'U') { co.first++; }
        else if(move == 'D') { co.first--; }
        else if(move == 'R') { co.second++; }
        else if(move == 'L') { co.second--; }
        if(co == candy) {cout << "YES\n"; flag=1;}
        else if (moves-1 == i) { cout << "NO\n"; }
    }
}

int main()
{
    adhamet
    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}