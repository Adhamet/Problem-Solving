#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<char> flats(n);
	unordered_set<char> types;
	for (char &poke: flats) {
		cin >> poke;
		types.insert(poke);
	}

	int ans = INT_MAX, l = 0, r = 0;
	unordered_map<char, int> currTypes;
	while (r < n) {
		currTypes[flats[r]]++;
		while (l + 1 <= r && currTypes.count(flats[l]) && currTypes[flats[l]] > 1) {
			currTypes[flats[l]]--;
			l++;
		}

		if (currTypes.size() == types.size()) ans = min(ans, r - l + 1);

		r += 1;
	}
	cout << ans << el;

	return 0;
}
