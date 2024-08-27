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
	
	int n;
	cin >> n;
	int arr[n], stored[n];
	if (n == 1) {
		cin >> arr[0];
		if (arr[0] == 1)
			return cout << 1,0;
		else return cout << 0,0;
	}

	int j = 0;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 1) {
			stored[j] = i; // 0 -> 0, 1 -> 1, 2 -> 4
			j++;
		}
	}
	
	if(j == 0) return cout << 0,0;

	int op=1;
	for(int i = 1; i < j; i++) {
		if ( (stored[i] - stored[i-1]) >= 2)
			op+=2;
		else op++;
	}
	cout << op;

    return 0;
}
