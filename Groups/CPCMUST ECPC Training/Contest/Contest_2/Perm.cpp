#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
 
int main() 
{/*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
    #endif
    */
    
    adhamet;
    
    ll n,ans=0;
    cin >> n;
    int arr[n];
    for(int i = 0; i <n ;i++) cin >> arr[i];
    sort(arr,arr+n);

    for(int i = 0; i < n; i++) {
        if (arr[i] != i+1) ans+=abs(arr[i]-(i+1));
    }
    cout << ans;
 
	return 0;
}
