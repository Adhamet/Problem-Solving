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
	
	vector<vi> v(3, vi(3));
	for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) {
		cin >> v[i][j];
	}

	v[0][0] = (v[1][2] + v[2][1]) / 2;
	v[1][1] = (v[0][2] + v[2][0]) / 2;
	v[2][2] = (v[0][1] + v[1][0]) / 2;

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
			cout << v[i][j] << " ";
		cout << el;
	}

    return 0;
}
