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
	int n;	cin >> n;
	int shops[n];
	for(int i = 0; i < n; i++) cin >> shops[i];
	sort(shops, shops+n);
	int q,x,ans;
	cin >> q;
	while(q--) {
		int l=0,r=n-1,mid,ans=0;
		int x;
		cin >> x;
		while(l <= r) {
			mid = (l + r) / 2;
			if (shops[mid] > x) r = mid - 1;
			else { ans = mid+1; l = mid+1; }
		}
		cout << ans << el;
	}
	
    return 0;
}