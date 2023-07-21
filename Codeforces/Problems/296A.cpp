#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el '\n'
int main() 
{
/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */
    adhamet
    
	int n;
    cin >> n;
    if ( n == 1 ) return cout << "YES", 0;
    int arr[n];

    for(int i = 0; i < n; i++) cin >> arr[i];

    if ( n == 2 ) 
    {
        if (arr[0] == arr[1]) return cout << "NO", 0;
        return cout << "YES", 0;
    }

    for(int i = 1; i < n - 1; i++) if (arr[i-1] == arr[i] && arr[i] == arr[i+1])
        return cout << "NO", 0;
    cout << "YES";

	return 0;
}
