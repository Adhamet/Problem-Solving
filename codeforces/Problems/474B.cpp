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
	int n,x;
	cin >> n;
	vector<int> hashtbl(n+1);
	int num = 1;
	for(int i = 1; i <= n; i++) { 
		cin >> x;
		hashtbl[i] = hashtbl[i-1] + x;
	}
	
	int m,q;
	cin >> m;
	while(m--) {
		cin >> q;
		int l = 1,r=n,mid,ans=0;
		while(l <= r) {
			mid = (l+r)/2;

			if (hashtbl[mid] < q) l = mid + 1;
			else ans = mid, r = mid - 1;
		}
		cout << ans << el;
	}
	
    return 0;
}