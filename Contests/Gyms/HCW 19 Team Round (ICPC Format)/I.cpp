/*{وَأَنْ لَيْسَ لِلإِنسَانِ إِلَّا مَا سَعَى ۝ وَأَنَّ
* سَعْيَهُ سَوْفَ يُرَى}*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
#define int64 long long
#define pii pair<int,int>
#define pb push_back
#define MeZo ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define el '\n';
#define int long long
#define yes cout << "YES" << el
#define no cout << "NO" << el
#define ull unsigned long long
#define all(x) std::sort((x).begin(), (x).end())
#define rall(x) std::sort((x).begin(), (x).end(),greater<decltype(*(x).begin())>{})
int cx[4] = {-1, 1, 0, 0};
int cy[4] = {0, 0, -1, 1};
// const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1e9 + 7, MAX = 1e18;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;
mt19937_64 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
// memset(dp,-1,sizeof dp);
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
// tree_order_statistics_node_update> ordered_set;
//--------------------------------------------------------------------------------------------------------------------------
ll inv(ll a, ll b = MOD) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0, mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
		mn = min(mn, v[i]);
	}

    bool flag;
    if (n % 2 == 1) {
        if (sum % 2 == 1)
            flag = true;
        else
            flag = false;
    } else {
        if (mn%2==1 || sum%2==1)
            flag = true;
        else
            flag = false;
    }
    if (flag)
        cout << "lowie" << el
    else
        cout << "imitater" << el
}
signed main() {
    MeZo
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
