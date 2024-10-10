#include <bits/stdc++.h>
using namespace std;
#define adhamet ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll, ll>
#define F first
#define S second
#define el "\n"
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

struct Boot {
	int max_dist, max_depth, index;
};

int main() {
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);
	adhamet;

	int n,b;	cin >> n >> b;
	vi tiles(n);	for(int &t: tiles) cin >> t;
	Boot B[b];	for(int i = 0; i < b; i++) cin >> B[i].max_depth >> B[i].max_dist, B[i].index = i;
	sort(B,B+b, [&](const Boot&a, const Boot& b) { return a.max_depth > b.max_depth; });
	
	vi tilesByDepth;	for(int i = 1; i < n-1; i++) tilesByDepth.push_back(i);	
	sort(tilesByDepth.begin(), tilesByDepth.end(), [&](const int& a, const int& b) {
		return tiles[a] > tiles[b];
	});
	set<int> validTiles;	for(int i = 0; i < n; i++) validTiles.insert(i);
	
	int tileIdx = 0, neededSteps = 1;
	vector<bool> canReach(b);
	for(auto &boot: B) {
		while(tileIdx < tilesByDepth.size() && tiles[tilesByDepth[tileIdx]] > boot.max_depth) {
			auto toRemoveItr = validTiles.find(tilesByDepth[tileIdx]);
			neededSteps = max(neededSteps, *next(toRemoveItr) - *prev(toRemoveItr));
			validTiles.erase(toRemoveItr);
			tileIdx++;
		}
		canReach[boot.index] = (neededSteps <= boot.max_dist);
	}
	for(bool ans: canReach) cout << ans << el;

	return 0;
}
