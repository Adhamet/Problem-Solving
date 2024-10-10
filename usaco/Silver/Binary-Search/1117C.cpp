#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct pt {
	ll x, y;
};

void windDir(char wind, pt &a) {
	if (wind == 'U') a.y++;
	else if (wind == 'D') a.y--;
	else if (wind == 'L') a.x--;
	else if (wind == 'R') a.x++;
}

bool can_reach(ll mid, pt a, pt b, string &s, ll n) {
	ll cycles = mid / n;
	ll rem = mid % n;
	
	pt moves = {0, 0};
	for (char wind : s) windDir(wind, moves);
	a.x += moves.x * cycles;
	a.y += moves.y * cycles;
	
	for (ll i = 0; i < rem; i++) windDir(s[i], a);
	return abs(a.x - b.x) + abs(a.y - b.y) <= mid;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n;
	pt a, b;
	string s;
	cin >> a.x >> a.y >> b.x >> b.y >> n >> s;

	ll left = 0, right = LLONG_MAX / 2, ans = -1;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (can_reach(mid, a, b, s, n)) {
			ans = mid;
			right = mid - 1;
		} else left = mid + 1;
	}

	cout << ans << '\n';
	return 0;
}

