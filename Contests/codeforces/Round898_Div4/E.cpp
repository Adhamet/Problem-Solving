#include <iostream>
#include <vector>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

vector<int> vec;
bool can(ll height, int x) {
	int n = (int)vec.size();
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		if(vec[i] >= height) continue;
		ans += (height - vec[i]);
	}
	return (ans <= x);
}

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	
	int t;	cin >> t;
	while(t--) {
		int n,x;
		cin >> n >> x;
		vec.clear();
		for(int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}

		ll l=0,r=2e9+5,mid;
		ll ans = 0;
		while(l <= r) {
			mid = l + (r-l)/2;
			if (!can(mid,x)) r = mid-1;
			else { 
				ans = mid; 
				l = mid+1; 
			}
		}
		cout << ans << el;
	}
	
    return 0;
}
