#include "bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>

int main() 
{
    adhamet;

    freopen("jumping.in", "r", stdin);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        float x;
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; // 2 2 2 2 2
            x = (float)(n - i - 1) / arr[i];
            if (x == (int)x) cout << x << '\n';
            else cout << -1 << '\n';
        }
    }
 
	return 0;
}
