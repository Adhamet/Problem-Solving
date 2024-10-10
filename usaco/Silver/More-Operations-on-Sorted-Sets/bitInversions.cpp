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

int m;
string s;
set<int> dif;
multiset<int> ret;
void modify(int x) {
	if(x == 0 || x == s.size()) return;
	auto it = dif.find(x);
	if(it != dif.end()) {
		int a = *prev(it), b = *next(it);
		ret.erase(ret.find(x - a));		ret.erase(ret.find(b - x));
		ret.insert(b - a);
		dif.erase(it);
	} else {
		it = dif.insert(x).first;
		int a = *prev(it), b = *next(it);
		ret.erase(ret.find(b - a));
		ret.insert(x - a);		ret.insert(b - x);
	}
}

int main() {
	adhamet;

	cin >> s >> m;
	dif.insert(0);	dif.insert(s.size());
	for(int i = 0; i < s.size()-1; i++) if(s[i] != s[i+1]) dif.insert(i+1);
	for(auto it = dif.begin(); next(it) != dif.end(); it++) ret.insert(*next(it)-*it);
	for(int i = 0; i < m; i++) {
		int x;	cin >> x;
		modify(x-1);
		modify(x);
		cout << *ret.rbegin() << " ";
	}
	
	return 0;
}
