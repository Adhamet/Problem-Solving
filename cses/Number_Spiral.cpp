#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T, class U = null_type, class chash = hash<T>> using hset = 
gp_hash_table<T,U,chash>;
template<class T, class U = null_type, class cmp = less<T>> using oset = 
tree<T,U,cmp,rb_tree_tag,tree_order_statistics_node_update>;
template <class T> int sz(const T &container) { return (int)container.size(); }

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
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
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
        ll x,y;
        cin >> x >> y;

        if ( x < y ) {
            if ( y % 2 == 1 ) {
                ll r = y*y;
                cout << r-x+1 << el;
            } else {
                ll r = (y-1)*(y-1)+1;
                cout << r+x-1 << el;
            }
        }
        else {
            if ( x % 2 == 0 ) {
                ll r = x*x;
                cout << r-y+1 << el;
            } else {
                ll r = (x-1)*(x-1)+1;
                cout << r+y-1 << el;
            }
        }
    }


    return 0;
}
