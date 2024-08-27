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
	adhamet;

	int n;	cin >> n;
	vi a(n);	for(int &i: a) cin >> i;
	multiset<int> ms;
	ms.insert(max(a[0],a[1]));
	for(int i = 2; i < n; i+=2) {
		int smallestTaken = *ms.begin();
		if(smallestTaken < min(a[i],a[i+1])) {
			ms.erase(ms.find(smallestTaken));
			ms.insert(a[i]);	ms.insert(a[i+1]);
		} else ms.insert(max(a[i],a[i+1]));
	}
	ll ans = 0;		for(int num: ms) ans+=num;
	cout << ans;

	return 0;
}
