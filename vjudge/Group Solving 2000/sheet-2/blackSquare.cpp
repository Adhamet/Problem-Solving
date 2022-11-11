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
    int moves = 0;
    char currPointer = 'a';
    string str;

    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        int clockWise = abs(str[i] - currPointer), cntr_clockWise = abs(26 - abs(str[i] - currPointer));
        if ( clockWise < cntr_clockWise)
        {
            moves+= clockWise;
            currPointer = str[i];
        }
        else 
        {
            moves+= cntr_clockWise;
            currPointer = str[i];
        }
    }
    
    cout << moves;
}

int main()
{
    adhamet

    solve();
    return 0;
}