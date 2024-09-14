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
using ull = unsigned long long;
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
	
    int t;
    cin >> t;
    while(t--) {
    	int n;
        int zeroes=0;
        ull product=1;
        cin >> n;
        ull arr[n];
        ull mn = 1e9;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            mn = min(mn, arr[i]);
            if (arr[i] == 0) { zeroes++; continue; }
            product *= arr[i];
        }
        if (zeroes > 1) cout << 0 << el;
        else if (mn == 0) cout << product << el;
        else {
            product /= mn;
            product *= (mn+1);
            cout << product << el;
        }
    }


    return 0;
}
