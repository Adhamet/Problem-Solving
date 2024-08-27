#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

const ll MOD = 998244353;
const ll N = 400001;
vll p2(N);

int main()
{
    adhamet;

    p2[0]=1;
    for(int i=1; i < N; i++) p2[i] = 2 * p2[i - 1] % MOD;

    int t;  cin >> t;
    while(t--) {
        int n;  cin >> n;
        vector<int> arr(n);     for(int i = 0; i < n; i++) cin >> arr[i];

        ll sum = 0, mn = 0, ans = 0, af = 0;
        for(int i = 0; i < n; i++) sum += arr[i], mn = min(mn,sum);
        if(mn == 0) {
            cout << p2[n] << el;
            continue;
        }

        sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum == mn) ans = (ans + p2[n - i - 1 + af]) % MOD;
            if(sum >= 0) af++;
        }
        cout << ans << el;
    }

    return 0;
}
