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
    int n,x;
    cin >> n;
    int arr[n+5];
    for(int i = 0; i < n; i++) 
    {
        cin >> x;
        arr[x-1] = i+1;
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    adhamet

    solve();
    return 0;
}