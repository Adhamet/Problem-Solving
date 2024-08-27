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
    int n,cntr=0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr,arr+n);

    for(int i = 0; i < n; i++)
        if(arr[i] > arr[0] && arr[i] < arr[n-1]) cntr++;
    cout << cntr;
}

int main()
{
    adhamet

    solve();
    return 0;
}