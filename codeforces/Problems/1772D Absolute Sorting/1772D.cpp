#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int t;  cin >> t;
    while(t--) {
        int n,low=0,high=1e9;  cin >> n;
        vi arr(n);  for(int i = 0; i < n; i++) cin >> arr[i];
        for(int i = 0; i < n-1; i++) {
            int sum = arr[i]+arr[i+1];
            if(arr[i] > arr[i+1])
                low = max(low, sum/2+sum%2);
            else if(arr[i] < arr[i+1])
                high = min(high, sum/2);
        }
        cout << ( low<=high? low: -1 ) << el;
    }

    return 0;
}
