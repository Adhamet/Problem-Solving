#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
	adhamet;

	int t;	cin >> t;
	while(t--) {
		int n;	cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++) cin >> arr[i];

        ll ans = 0;

        for(int i = 1; i < n; i++) {
            if(arr[i] < arr[i-1]) {
                int diff = arr[i-1] - arr[i];
                int bits = 32 - __builtin_clz(diff);
                ans = max(ans, (ll)bits);
                arr[i] = arr[i-1];
            }
        }

        cout << ans << el;
	}
	
    return 0;
}