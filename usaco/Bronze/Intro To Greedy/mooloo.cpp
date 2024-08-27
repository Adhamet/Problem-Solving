#include <bits/stdc++.h>
using namespace std;
#define adhamet ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define el "\n"
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main() {
	// freopen("outofplace.in","r",stdin);
	// freopen("outofplace.out","w",stdout);
	adhamet;

	int n,k;	cin >> n >> k;
	vll days(n);	for(int i = 0; i < n; i++) cin >> days[i];
	sort(days.begin(),days.end());

	ll last_day = days[0], cost = k+1;
	for(ll d: days) {
		if(d - last_day < k + 1) cost += (d - last_day);
		else cost += k + 1;
		last_day = d;
	}
	cout << cost << el;
	return 0;
}

