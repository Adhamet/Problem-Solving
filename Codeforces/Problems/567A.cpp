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
    int size;
    cin >> size;
    ll arr[size];
    for(int i = 0; i < size; i++) cin >> arr[i];

    ll maxi,mini;
    for(int i = 0; i < size; i++) {
        maxi=0,mini=INT_MAX;
        
        if(i==0) { 
            mini = abs( arr[i] - arr[i+1] ); 
            maxi = abs( arr[i] - arr[size-1] ); 
        } 
        else if(i==(size-1)) {
            mini=abs( arr[i] - arr[i-1] );
            maxi=abs( arr[i] - arr[0] );
        }
        else { 
            mini = min( abs( arr[i] - arr[i+1] ), abs( arr[i] - arr[i-1] ) );
            maxi = max( abs( arr[i] - arr[0] ), abs( arr[i] - arr[size-1] ) );
        }
    
        cout << mini << " " << maxi << endl;
    }
}

int main()
{
    adhamet

    solve();
    return 0;
}