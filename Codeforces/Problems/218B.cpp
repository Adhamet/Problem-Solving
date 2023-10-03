#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	
	ll n,m;
	cin >> n >> m;
	vector<ll> vec(m);
	for(int i = 0; i < m; i++) cin >> vec[i];
	sort(vec.begin(), vec.end());

	vector<ll> dummy=vec;
	ll tempN = n, mn=0;
	for(ll i = 0; i < m, tempN>0; i++) {
		ll temp = vec[i];
		while(temp > 0 && tempN > 0) {
			mn += temp;
			--temp;
			--tempN;
		}
	}
	
	ll mx=0;
	for(int i=0; i < n; i++) {
		sort(vec.rbegin(), vec.rend());
		mx += vec[0];
		vec[0]--;
	}
	cout << mx << ' ' << mn << el;
    return 0;
}