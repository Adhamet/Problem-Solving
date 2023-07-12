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
    
    int sum = 0;
    // Taking input -------------
    int n, x, y;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i], sum += arr[i];
    cin >> x >> y;
    // --------------------------

    // Logic ----------------
    int cSum = 0;
    for (int i = 0; i < n; i++) {
        if (cSum >= x && cSum <= y && sum - cSum >= x && sum - cSum <= y)
            return cout << i+1, 0;
        cSum += arr[i];
    }
    cout << 0;
    // --------------------------

    return 0;
}
