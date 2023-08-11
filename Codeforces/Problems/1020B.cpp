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
    
    int n; cin >> n;
    int arr[n], b[n];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1,j; i <= n; i++) {
        for(j=1; j<=n; j++) b[j]=0;
        for(j=i; !b[j]; j=arr[j]) b[j]=1;
        cout << j;
    }

    return 0;
}
