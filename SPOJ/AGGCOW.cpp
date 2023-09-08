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

int n,c;
const int N = 1e5+5;
int arr[N];

bool can(int dist) {
    int curr = arr[0], cnt = 1;
    for(int i = 1; i<n; i++) if (arr[i] - curr >= dist) {
        cnt++;
        curr = arr[i];
    }
    if (cnt >= c) return true;
    return false;
}

int main()
{
    adhamet
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> c;
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr,arr+n);

        int l = 0, r = 1e9, mid;
        while (l < r - 1) {
            mid = (l + r) / 2;
            if (can(mid)) l = mid;
            else r = mid - 1;
        }
        if (can(r)) cout << r << el;
        else cout << l << el;
    }
    return 0;
}
