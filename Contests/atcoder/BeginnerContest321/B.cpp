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
	vector<int> A(n-1);
	for(int i = 0; i < n-1; i++)
		cin >> A[i];	
	vector<int> B(101,0);
	for(int i = 0; i <= 100; i++) {
		vector<int> TMP = A;
		TMP.push_back(i);
		sort(TMP.begin(),TMP.end());
		for(int j = 0; j < n - 2; j++)
			B[i] += TMP[j+1];
	}

	if(B[100] < goal) cout << -1;
	else {
		for(int i = 0; i <= 100; i++) if (B[i] >= goal) {
			cout << i;
			break;
		}
	}

    return 0;
}
