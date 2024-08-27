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

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	
	ll n,m;		cin >> n >> m;
	vll arr(m);
	for(int i = 0; i < m-1; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	ll mn = 0;
	ll y = n;
	while( n > 0 ) {
		for(int i = 0; i < m-1; i++) {
			ll x = arr[i];
			while( x > 0 && n > 0 ) {
				mn += x;
				x--;
				n--;
			}
		}
	}
	n = y;
	ll mx = 0;
	for(int i = 0; i < n-1; i++) {
		sort(arr.begin(),arr.end());
		mx += arr[m-1];
		arr[m-1]--;
	}
	cout << mx << " " << mn << el;

    return 0;
}
