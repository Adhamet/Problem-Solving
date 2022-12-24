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
    int arr[4], hs=0;
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    if(arr[0] == arr[1] || arr[0] == arr[2] || arr[0] == arr[3]) hs++;
    if(arr[1] == arr[2] || arr[1] == arr[3] ) hs++;
    if(arr[2] == arr[3]) hs++;
    cout << hs;
}

int main()
{
    adhamet
    
    solve();
    return 0;
}