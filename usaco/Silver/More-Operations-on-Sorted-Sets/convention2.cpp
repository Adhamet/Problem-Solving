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

int main() {
	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);
	adhamet;

	int n;	cin >> n;
	vector<vi> cows;
	for(int seniority = 0; seniority < n; seniority++) {
		int start, duration;	cin >> start >> duration;
		cows.push_back( {seniority, start, duration} );
	}	
	sort(cows.begin(), cows.end(), [&](const vi &a, const vi &b) {
		return a[1] < b[1];
	});

	set<vi> waiting;
	int i = 0, time = 0, longestWait = 0;
	while(i < n || !waiting.empty()) {
		if(i < n && cows[i][1] <= time) waiting.insert(cows[i++]);	// insert all waiting cows
		else if (waiting.empty()) time = cows[i][1] + cows[i][2], i++; // finish current cow
		else {	// finish waiting cows
			vector<int> nextCow = *waiting.begin();
			longestWait = max(longestWait, time - nextCow[1]);
			time += nextCow[2];
			waiting.erase(waiting.begin());
		}
	}
	cout << longestWait;
	
	return 0;
}
