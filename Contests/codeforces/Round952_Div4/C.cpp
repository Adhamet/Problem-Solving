#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

/* void setIO(string name = "") { */
/*     if (name.size()) { */
/*         freopen((name+".in").c_str(), "r", stdin); */
/*         freopen((name+".out").c_str(), "w", stdout); */    
/*     } */
/* } */

int main()
{
    /* setIO("cowqueue"); */
    adhamet;

    int t;  cin >> t;
    while(t--) {
        int n;  cin >> n;
        vector<long long> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        int ans = 0;
        long long sum = 0, maxEle = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(maxEle < arr[i]) maxEle = arr[i];
            if(sum - maxEle == maxEle) ans++;
        }
        cout << ans << el;
    }

    return 0;
}
