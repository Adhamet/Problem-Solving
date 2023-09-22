#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T, class U = null_type, class chash = hash<T>> using hset = 
gp_hash_table<T,U,chash>;
template<class T, class U = null_type, class cmp = less<T>> using oset = 
tree<T,U,cmp,rb_tree_tag,tree_order_statistics_node_update>;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using pd = pair<ld,ld>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

vector<int> vec;
bool can(ll resistance, int strength) {
	int n = (int)vec.size();
	for(int i = 0; i < n; i++) {
		if (vec[i] > resistance)
			strength -= vec[i];
	}
	return (strength > 0);
}

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	
	int t;
	cin >> t;
	while(t--) {
		int n,H;
		cin >> n >> H;
		vec.clear();
		int temp;
		for(int i = 0; i < n; i++) {
			cin >> temp;
			vec.push_back(temp);
		}

		ll l=0, r=1e11+1,mid,ans=0;
		while(l <= r) {
			mid = l + (r-l)/2;

			if(!can(mid,H)) l = mid + 1;
			else {
				ans = mid;
				r = mid - 1;
			}
		}
		cout << ans << el;
	}
	
    return 0;
}
