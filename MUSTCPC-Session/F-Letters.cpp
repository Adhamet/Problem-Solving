#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	int n,m;	cin >> n >> m;
	ll a[n+2] = {}, s[n+2] = {}, b[m+2] = {};

	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	for(int i = 1; i <= m; i++) {
		int l = 0, r = n - 1, dorm_idx = 0;
		while(l <= r) {
			int mid = (l + r) / 2;

			if(s[mid] < b[i]) dorm_idx = mid, l = mid + 1;
			else r = mid - 1;
		}
		cout << dorm_idx + 1 << " ";
		cout << b[i] - s[dorm_idx] << el;
	}
	
	
    return 0;
}