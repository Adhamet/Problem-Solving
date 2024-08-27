#include <bits/stdc++.h>
using namespace std;
#define adhamet ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll, ll>
#define F first
#define S second
#define el "\n"
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main() {
	freopen("evolution.in", "r", stdin);
	freopen("evolution.out", "w", stdout);
	adhamet;

	int n;	cin >> n;
	vector<set<string>> cows;
	set<string> all_char_set;
	for(int i=0; i<n; i++) {
		int k;	cin >> k;
		set<string> currCow;
		for(int j = 0; j < k; j++) {
			string s;	cin >> s;
			currCow.insert(s);
		}
		all_char_set.insert(currCow.begin(),currCow.end());
		cows.push_back(currCow);
	}

	vector<string> all_char(all_char_set.begin(), all_char_set.end());
	for(int a = 0; a<all_char.size(); a++) {
		for(int b = a + 1; b<all_char.size(); b++) {
			bool both=false, only_a=false, only_b=false;
			for(const set<string> &c: cows) {
				bool has_a = c.count(all_char[a]);
				bool has_b = c.count(all_char[b]);

				if(has_a && has_b) both=true;
				else if(has_a && !has_b) only_a=true;
				else if(has_b && !has_a) only_b=true;
			}

			if(only_a && only_b && both) return cout << "no", 0;
		}
	}
	cout << "yes";
	
	return 0;
}

