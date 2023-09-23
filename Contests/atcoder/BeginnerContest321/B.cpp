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
	
	int n,goal;
	cin >> n >> goal;
	int arr[n-1],score=0;
	for(int i = 0; i < n-1; i++) { 
		cin >> arr[i];
		score+=arr[i];
	}
	sort(arr,arr+(n-1));

	if( n == 3 ) {
		score -= arr[0];
		if (score == goal) {
			if (arr[0] == score) return cout << 0, 0;
			else return cout << score, 0;
		}
		else if (score > goal) {
			
		}
	}

	score -= (arr[0] + arr[n-2]);
	if (score == goal) return cout << 0, 0;
	else if (score > goal)
		return cout << (arr[n-2] - (score - goal)), 0;
	else if (score < goal) {
		int ans = (goal - score);
		if (ans <= 100) {
			if (ans < arr[n-2])
				return cout << ans, 0;
			else if (ans == arr[n-2]) return cout << 0, 0;
		}
	}
	cout << -1;
	
    return 0;
}
