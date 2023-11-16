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

int need[3];
int have[3];
int cost[3];
ll money;

bool ok(long long num) {
	ll totalMoney = 0;
	for(int i = 0; i < 3; i++) {
		if (have[i] >= num*need[i])
			continue;
		totalMoney += (num * need[i] - have[i]) * cost[i];
	}
	if (totalMoney <= money) return true;
	return false;
}

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	string recipe;	cin >> recipe;
	for(char ch: recipe) {
		if (ch == 'B') need[0]++;
		else if (ch == 'S') need[1]++;
		else if (ch == 'C') need[2]++;
	}

	for(int i = 0; i < 3; i++) cin >> have[i];
	for(int i = 0; i < 3; i++) cin >> cost[i];

	cin >> money;
	
	ll l = 0, r = 1e14+5, ans = 0;
	while(l <= r) {
		ll mid = (l+r)/2;
		if( ok(mid) ) { ans = mid; l = mid + 1; }
		else r = mid - 1;
	}
	cout << ans;
	
    return 0;
}