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
	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);
	int barn_i = 0, barn_j = 0, rock_i = 0, rock_j = 0, lake_i = 0, lake_j = 0;
	for (int i = 0; i < 10; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < 10; j++) {
			if (row[j] == 'B') {
				barn_i = i;
				barn_j = j;
			} else if (row[j] == 'R') {
				rock_i = i;
				rock_j = j;
			} else if (row[j] == 'L') {
				lake_i = i;
				lake_j = j;
			}
		}
	}

	int cows = abs(barn_i - lake_i) + abs(barn_j - lake_j) - 1;

	if (barn_i == lake_i && rock_i == barn_i &&
	    ((lake_j < rock_j && rock_j < barn_j) ||
	     (barn_j < rock_j && rock_j < lake_j))) {
		cows += 2;
	}
	else if (barn_j == lake_j && rock_j == barn_j &&
	         ((lake_i < rock_i && rock_i < barn_i) ||
	          (barn_i < rock_i && rock_i < lake_i))) {
		cows += 2;
	}
	cout << cows << endl;

    return 0;
}
