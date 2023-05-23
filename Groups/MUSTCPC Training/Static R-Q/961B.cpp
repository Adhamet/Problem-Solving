// Lecture sleep
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
    int n,k;
    cin >> n >> k;

    int theorems[n], behavior[n], holder[n];
    for(int minute = 0; minute < n; minute++)
        cin >> theorems[minute];
    for(int minute = 0; minute < n; minute++) {
        cin >> behavior[minute];
        if(behavior[minute] == 1)
            holder[minute] = minute > 0? holder[minute-1] + theorems[minute]: theorems[minute];
        else
            holder[minute] = minute > 0? holder[minute-1]: 0;
    }
    
    int currentMax=0,max=0;
    for(int minute = 0; minute < n; minute++) if(behavior[minute] == 0)
    {
        currentMax = holder[minute];
        for(int i = 0, j = minute; i < k && j < n; i++, j++)
        {
            currentMax += theorems[j];
        }
        if(max < currentMax) max = currentMax;
    }

    cout << max;
}

int main()
{
    adhamet;

    solve();

    return 0;
}