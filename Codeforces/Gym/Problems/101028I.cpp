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

int n, longestStrip;
vector<int> vec;
bool can(int num, int k) { // 
	longestStrip = 0;
	int i = 2;
	longestStrip += vec[1] - vec[0];
	for(; i < n; i++) { // 2
		if (longestStrip <= num) longestStrip += (vec[i] - vec[i-1]) - 1;
		else { 
			longestStrip = 0;
			k--;
		}
		if ( k == 0 ) break;
	}
	if ( k == 0 && i < n-1 ) return false;
	return true;
}

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		int x,k;
		cin >> n >> k;
		for(int i = 0; i < n; i++) { 
			cin >> x;
			vec.push_back(x);
		}

		int l=0,r=1e5+1,mid,ans=0;
		while(l <= r) {
			mid = (l+r)/2;

			if (can(mid,k)) r = mid - 1;
			else ans = mid, l = mid + 1;
		}
		cout << ans << el;
	}
	
	
    return 0;
}