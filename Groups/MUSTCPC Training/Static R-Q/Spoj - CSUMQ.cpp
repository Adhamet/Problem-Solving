//Cumulative Sum Query
// Time: 20ms, Memory 5530KB
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

int main()
{
    adhamet
    
    int n,q;
    cin >> n;
    int arr[n];
    cin >> arr[0];
    for(int i = 1; i < n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        if(l != 0) cout << arr[r] - arr[l-1] << el;
        else cout << arr[r] << el;
    }
    return 0;
}